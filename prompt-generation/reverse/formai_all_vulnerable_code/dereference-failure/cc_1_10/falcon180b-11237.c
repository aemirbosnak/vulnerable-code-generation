//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a bank account
struct BankAccount {
    char name[50];
    int accountNumber;
    double balance;
};

// Function to deposit money into an account
void deposit(struct BankAccount* account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposit of $%.2f made into account %d for %s\n", amount, account->accountNumber, account->name);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

// Function to withdraw money from an account
void withdraw(struct BankAccount* account, double amount) {
    if (amount > 0) {
        if (account->balance >= amount) {
            account->balance -= amount;
            printf("Withdrawal of $%.2f made from account %d for %s\n", amount, account->accountNumber, account->name);
        } else {
            printf("Insufficient funds.\n");
        }
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}

// Function to check the balance of an account
void checkBalance(struct BankAccount* account) {
    printf("The balance in account %d for %s is $%.2f\n", account->accountNumber, account->name, account->balance);
}

// Function to create a new bank account
struct BankAccount* createAccount(char* name, int accountNumber) {
    struct BankAccount* newAccount = (struct BankAccount*)malloc(sizeof(struct BankAccount));
    strcpy(newAccount->name, name);
    newAccount->accountNumber = accountNumber;
    newAccount->balance = 0;
    return newAccount;
}

int main() {
    struct BankAccount account1 = {"John Doe", 12345, 0};
    struct BankAccount* account2 = createAccount("Jane Smith", 67890);

    deposit(&account1, 1000);
    withdraw(&account1, 500);
    checkBalance(&account1);

    deposit(account2, 2000);
    withdraw(account2, 1000);
    checkBalance(account2);

    return 0;
}