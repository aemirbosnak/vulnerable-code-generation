//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
/*
 * Personal Finance Planner
 *
 * A simple program to help you manage your personal finances.
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>

// Define the structure for a financial transaction
struct Transaction {
    char type; // 'd' for deposit, 'w' for withdrawal
    int amount;
    char date[11]; // Format: YYYY-MM-DD
};

// Define the structure for a financial account
struct Account {
    int balance;
    struct Transaction* transactions;
    int num_transactions;
};

// Function to print a financial transaction
void print_transaction(struct Transaction* transaction) {
    printf("Transaction: %c %d %s\n", transaction->type, transaction->amount, transaction->date);
}

// Function to print a financial account
void print_account(struct Account* account) {
    printf("Balance: %d\n", account->balance);
    for (int i = 0; i < account->num_transactions; i++) {
        print_transaction(&account->transactions[i]);
    }
}

// Function to add a financial transaction to an account
void add_transaction(struct Account* account, struct Transaction* transaction) {
    account->transactions = realloc(account->transactions, (account->num_transactions + 1) * sizeof(struct Transaction));
    account->transactions[account->num_transactions] = *transaction;
    account->num_transactions++;
}

// Function to deposit money into an account
void deposit(struct Account* account, int amount) {
    struct Transaction transaction;
    transaction.type = 'd';
    transaction.amount = amount;
    strcpy(transaction.date, "YYYY-MM-DD");
    add_transaction(account, &transaction);
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(struct Account* account, int amount) {
    struct Transaction transaction;
    transaction.type = 'w';
    transaction.amount = amount;
    strcpy(transaction.date, "YYYY-MM-DD");
    add_transaction(account, &transaction);
    account->balance -= amount;
}

// Main function
int main() {
    // Initialize an account with a balance of 0
    struct Account account;
    account.balance = 0;
    account.num_transactions = 0;

    // Deposit $1000
    deposit(&account, 1000);

    // Withdraw $500
    withdraw(&account, 500);

    // Print the account balance and transactions
    print_account(&account);

    return 0;
}