//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length for names and account numbers
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20

// Define structure for a bank account
typedef struct {
    char name[NAME_LENGTH];
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    int balance;
} BankAccount;

// Function to create a new bank account
BankAccount* createAccount(char* name, char* accountNumber, int balance) {
    BankAccount* account = (BankAccount*) malloc(sizeof(BankAccount));
    strcpy(account->name, name);
    strcpy(account->accountNumber, accountNumber);
    account->balance = balance;
    return account;
}

// Function to deposit money into an account
void deposit(BankAccount* account, int amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
int withdraw(BankAccount* account, int amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        return 0;
    } else {
        printf("Insufficient funds.\n");
        return -1;
    }
}

// Function to print account information
void printAccount(BankAccount* account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %s\n", account->accountNumber);
    printf("Balance: $%d\n", account->balance);
}

// Main function
int main() {
    // Create a new account
    BankAccount* account = createAccount("John Doe", "1234567890", 1000);

    // Print account information
    printAccount(account);

    // Deposit money into the account
    deposit(account, 500);

    // Print account information
    printAccount(account);

    // Withdraw money from the account
    int result = withdraw(account, 200);
    if (result == 0) {
        printf("Withdrawal successful.\n");
    } else {
        printf("Withdrawal failed.\n");
    }

    // Print account information
    printAccount(account);

    // Free memory used by the account
    free(account);

    return 0;
}