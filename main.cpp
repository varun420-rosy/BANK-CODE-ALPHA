#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string ac, string ah, double b) {
        accountNumber = ac;
        accountHolder = ah;
        balance = b;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    string getAccountHolder() {
        return accountHolder;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
        cout << "Deposited: " << amount << endl;
    }

    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void displayBalance() {
        cout << "Balance: " << balance << endl;
    }
};

class Bank {
private:
    vector<BankAccount> accounts;

public:
    void createAccount(string accountNumber, string accountHolder, double balance) {
        BankAccount account(accountNumber, accountHolder, balance);
        accounts.push_back(account);
    }

    void deposit(string accountNumber, double amount) {
        for (BankAccount &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.deposit(amount);
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

    void withdraw(string accountNumber, double amount) {
        for (BankAccount &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.withdraw(amount);
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

    void displayBalance(string accountNumber) {
        for (BankAccount &account : accounts) {
            if (account.getAccountNumber() == accountNumber) {
                account.displayBalance();
                return;
            }
        }
        cout << "Account not found!" << endl;
    }

    void displayAllAccounts() {
        for (BankAccount &account : accounts) {
            cout << "Account Number: " << account.getAccountNumber() << endl;
            cout << "Account Holder: " << account.getAccountHolder() << endl;
            cout << "Balance: " << account.getBalance() << endl;
            cout << endl;
        }
    }
};

int main() {
    Bank bank;

    while (true) {
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Display All Accounts" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string accountNumber, accountHolder;
                double balance;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter account holder's name: ";
                cin.ignore();
                getline(cin, accountHolder);
                cout << "Enter initial balance: ";
                cin >> balance;
                bank.createAccount(accountNumber, accountHolder, balance);
                break;
            }
            case 2: {
                string accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;
            }
            case 3: {
                string accountNumber;
                double amount;
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;
            }
            case 4: {
                string accountNumber;
                cout << "Enter account number: ";
                cin >> accountNumber;
                bank.displayBalance(accountNumber);
                break;
            }
            case 5:
                bank.displayAllAccounts();
                break;
            case 6:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;


}
