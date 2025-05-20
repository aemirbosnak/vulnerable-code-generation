//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: active
/*
 * Banking Record System
 *
 * This program is a simple example of a banking record system in C.
 * It allows users to create, view, update, and delete accounts, as well as
 * view account transactions.
 *
 * Author: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account information
typedef struct {
    char name[50];
    char account_number[20];
    double balance;
} Account;

// Function to create a new account
void create_account(Account *account) {
    printf("Enter the name of the account holder: ");
    scanf("%s", account->name);
    printf("Enter the account number: ");
    scanf("%s", account->account_number);
    printf("Enter the initial balance: ");
    scanf("%lf", &account->balance);
}

// Function to view an account
void view_account(Account *account) {
    printf("Name: %s\n", account->name);
    printf("Account Number: %s\n", account->account_number);
    printf("Balance: $%.2f\n", account->balance);
}

// Function to update an account
void update_account(Account *account) {
    printf("Enter the name of the account holder: ");
    scanf("%s", account->name);
    printf("Enter the account number: ");
    scanf("%s", account->account_number);
    printf("Enter the new balance: ");
    scanf("%lf", &account->balance);
}

// Function to delete an account
void delete_account(Account *account) {
    printf("Enter the name of the account holder: ");
    scanf("%s", account->name);
    printf("Enter the account number: ");
    scanf("%s", account->account_number);
    free(account);
}

// Function to view account transactions
void view_transactions(Account *account) {
    printf("Transactions for %s\n", account->name);
    printf("Account Number: %s\n", account->account_number);
    printf("Balance: $%.2f\n", account->balance);
}

// Main function
int main() {
    Account *account = (Account *)malloc(sizeof(Account));
    create_account(account);
    view_account(account);
    update_account(account);
    view_transactions(account);
    delete_account(account);
    free(account);
    return 0;
}