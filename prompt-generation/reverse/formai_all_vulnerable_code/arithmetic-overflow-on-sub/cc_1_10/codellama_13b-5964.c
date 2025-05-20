//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: introspective
/*
 * A unique C Banking Record System example program in an introspective style.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 20
#define MAX_ACCOUNT_NUMBER_LENGTH 10
#define MAX_BALANCE_LENGTH 10

// Account structure
struct Account {
    char name[MAX_NAME_LENGTH];
    char account_number[MAX_ACCOUNT_NUMBER_LENGTH];
    int balance;
};

// Array of accounts
struct Account accounts[MAX_ACCOUNTS];

// Function to add a new account
void add_account(struct Account* new_account) {
    // Check if the account number is already in use
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accounts[i].account_number, new_account->account_number) == 0) {
            printf("Account number already in use.\n");
            return;
        }
    }

    // Add the new account to the array
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (accounts[i].account_number[0] == '\0') {
            accounts[i] = *new_account;
            printf("Account added successfully.\n");
            return;
        }
    }

    // If the array is full, print an error message
    printf("Account limit reached.\n");
}

// Function to print the balance of an account
void print_balance(char* account_number) {
    // Find the account with the given account number
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            printf("Balance: %d\n", accounts[i].balance);
            return;
        }
    }

    // If the account is not found, print an error message
    printf("Account not found.\n");
}

// Function to deposit money into an account
void deposit(char* account_number, int amount) {
    // Find the account with the given account number
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            accounts[i].balance += amount;
            printf("Deposited %d into account %s.\n", amount, account_number);
            return;
        }
    }

    // If the account is not found, print an error message
    printf("Account not found.\n");
}

// Function to withdraw money from an account
void withdraw(char* account_number, int amount) {
    // Find the account with the given account number
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            if (accounts[i].balance < amount) {
                printf("Insufficient funds.\n");
                return;
            }
            accounts[i].balance -= amount;
            printf("Withdrew %d from account %s.\n", amount, account_number);
            return;
        }
    }

    // If the account is not found, print an error message
    printf("Account not found.\n");
}

int main() {
    // Create a new account
    struct Account new_account;
    printf("Enter account name: ");
    fgets(new_account.name, MAX_NAME_LENGTH, stdin);
    printf("Enter account number: ");
    fgets(new_account.account_number, MAX_ACCOUNT_NUMBER_LENGTH, stdin);
    new_account.balance = 0;
    add_account(&new_account);

    // Print the balance of the account
    printf("Enter account number to print balance: ");
    char account_number[MAX_ACCOUNT_NUMBER_LENGTH];
    fgets(account_number, MAX_ACCOUNT_NUMBER_LENGTH, stdin);
    print_balance(account_number);

    // Deposit money into the account
    printf("Enter account number to deposit into: ");
    fgets(account_number, MAX_ACCOUNT_NUMBER_LENGTH, stdin);
    int amount;
    printf("Enter amount to deposit: ");
    scanf("%d", &amount);
    deposit(account_number, amount);

    // Withdraw money from the account
    printf("Enter account number to withdraw from: ");
    fgets(account_number, MAX_ACCOUNT_NUMBER_LENGTH, stdin);
    printf("Enter amount to withdraw: ");
    scanf("%d", &amount);
    withdraw(account_number, amount);

    return 0;
}