//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: systematic
// banking_record_system.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_NAME_LENGTH 256
#define MAX_ACCOUNT_NUMBER_LENGTH 20
#define MAX_BALANCE_LENGTH 20
#define MAX_TRANSACTIONS_LENGTH 100

// Structure to store account information
typedef struct {
    char name[MAX_NAME_LENGTH];
    char account_number[MAX_ACCOUNT_NUMBER_LENGTH];
    float balance;
    int num_transactions;
    char transactions[MAX_TRANSACTIONS_LENGTH];
} Account;

// Function to create a new account
void create_account(Account *account) {
    printf("Enter name: ");
    scanf("%s", account->name);
    printf("Enter account number: ");
    scanf("%s", account->account_number);
    printf("Enter initial balance: ");
    scanf("%f", &account->balance);
    account->num_transactions = 0;
}

// Function to deposit money into an account
void deposit(Account *account, float amount) {
    account->balance += amount;
    account->num_transactions++;
    char transaction[MAX_TRANSACTIONS_LENGTH];
    sprintf(transaction, "Deposit: %0.2f", amount);
    strcat(account->transactions, transaction);
}

// Function to withdraw money from an account
void withdraw(Account *account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        account->num_transactions++;
        char transaction[MAX_TRANSACTIONS_LENGTH];
        sprintf(transaction, "Withdrawal: %0.2f", amount);
        strcat(account->transactions, transaction);
    } else {
        printf("Insufficient funds.\n");
    }
}

// Function to print account information
void print_account(Account *account) {
    printf("Name: %s\n", account->name);
    printf("Account number: %s\n", account->account_number);
    printf("Balance: %0.2f\n", account->balance);
    printf("Number of transactions: %d\n", account->num_transactions);
    printf("Transactions: %s\n", account->transactions);
}

int main() {
    // Create a new account
    Account account;
    create_account(&account);

    // Deposit money into the account
    float amount = 100.00;
    deposit(&account, amount);

    // Withdraw money from the account
    amount = 50.00;
    withdraw(&account, amount);

    // Print account information
    print_account(&account);

    return 0;
}