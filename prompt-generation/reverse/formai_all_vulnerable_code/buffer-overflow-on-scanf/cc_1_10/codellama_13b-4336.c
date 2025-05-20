//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: happy
/*
 * Banking Record System
 *
 * This program is a simple example of a banking record system
 * that allows users to create, view, and modify their bank accounts.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 25

// Structure to store bank account information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int account_number;
    float balance;
} account_t;

// Function to create a new bank account
void create_account(account_t *account) {
    printf("Enter name: ");
    scanf("%s", account->name);
    printf("Enter account number: ");
    scanf("%d", &account->account_number);
    printf("Enter initial balance: ");
    scanf("%f", &account->balance);
}

// Function to view a bank account
void view_account(account_t *account) {
    printf("Name: %s\n", account->name);
    printf("Account number: %d\n", account->account_number);
    printf("Balance: $%.2f\n", account->balance);
}

// Function to modify a bank account
void modify_account(account_t *account) {
    printf("Enter the amount to deposit: ");
    float amount;
    scanf("%f", &amount);
    account->balance += amount;
}

int main() {
    // Create an array of accounts
    account_t accounts[MAX_ACCOUNTS];

    // Create a new account
    create_account(&accounts[0]);

    // View the account
    view_account(&accounts[0]);

    // Modify the account
    modify_account(&accounts[0]);

    // View the account again
    view_account(&accounts[0]);

    return 0;
}