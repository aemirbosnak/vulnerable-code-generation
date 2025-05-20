//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTION_NUMBER 100

typedef struct Transaction {
    char name[MAX_NAME_LENGTH];
    int amount;
    int date;
} Transaction;

void createTransaction(Transaction *transaction) {
    printf("Enter the name of the transaction: ");
    scanf("%s", transaction->name);

    printf("Enter the amount of the transaction: ");
    scanf("%d", &transaction->amount);

    printf("Enter the date of the transaction: ");
    scanf("%d", &transaction->date);
}

void displayTransactions(Transaction *transactions, int numTransactions) {
    for (int i = 0; i < numTransactions; i++) {
        printf("Name: %s\n", transactions[i].name);
        printf("Amount: %d\n", transactions[i].amount);
        printf("Date: %d\n", transactions[i].date);
        printf("\n");
    }
}

int main() {
    Transaction transactions[MAX_TRANSACTION_NUMBER];
    int numTransactions = 0;

    printf("Welcome to the Personal Finance Planner!\n");

    // Create a new transaction
    printf("Enter 'new' to create a new transaction: ");
    char command[MAX_NAME_LENGTH];
    scanf("%s", command);

    // If the user wants to create a new transaction
    if (strcmp(command, "new") == 0) {
        transactions[numTransactions].name[0] = '\0';
        createTransaction(&transactions[numTransactions]);
        numTransactions++;
    }

    // Display all transactions
    displayTransactions(transactions, numTransactions);

    return 0;
}