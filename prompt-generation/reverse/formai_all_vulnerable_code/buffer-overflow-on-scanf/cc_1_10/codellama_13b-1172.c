//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: unmistakable
// Banking Record System Example Program

#include <stdio.h>
#include <stdlib.h>

// Structures to store account information
typedef struct {
    int account_number;
    char name[50];
    float balance;
} Account;

typedef struct {
    int transaction_id;
    int account_number;
    char type[20];
    float amount;
    char date[20];
} Transaction;

// Function to create a new account
void createAccount(Account *account) {
    printf("Enter the account number: ");
    scanf("%d", &account->account_number);
    printf("Enter the account holder's name: ");
    scanf("%s", &account->name);
    printf("Enter the initial balance: ");
    scanf("%f", &account->balance);
}

// Function to display account information
void displayAccount(Account account) {
    printf("Account Number: %d\n", account.account_number);
    printf("Name: %s\n", account.name);
    printf("Balance: %.2f\n", account.balance);
}

// Function to perform a transaction
void performTransaction(Transaction *transaction) {
    printf("Enter the transaction type (deposit/withdrawal): ");
    scanf("%s", &transaction->type);
    printf("Enter the amount: ");
    scanf("%f", &transaction->amount);
    printf("Enter the date (YYYY-MM-DD): ");
    scanf("%s", &transaction->date);
}

// Function to display transaction information
void displayTransaction(Transaction transaction) {
    printf("Transaction ID: %d\n", transaction.transaction_id);
    printf("Account Number: %d\n", transaction.account_number);
    printf("Type: %s\n", transaction.type);
    printf("Amount: %.2f\n", transaction.amount);
    printf("Date: %s\n", transaction.date);
}

int main() {
    // Create an account
    Account account;
    createAccount(&account);

    // Display account information
    displayAccount(account);

    // Perform a transaction
    Transaction transaction;
    performTransaction(&transaction);

    // Display transaction information
    displayTransaction(transaction);

    return 0;
}