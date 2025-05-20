//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 1000

typedef struct transaction {
    char category[20];
    float amount;
} Transaction;

int main()
{
    printf("Welcome to the Personal Finance Planner!\n");

    // Array to hold all transactions
    Transaction transactions[MAX_TRANSACTIONS];
    int transactionCount = 0;

    // Variable to hold the user's input
    char command[100];

    while (1) {
        printf("\nEnter a command: (add/total/quit) ");

        // Get user input and remove trailing newline character
        fgets(command, 100, stdin);
        command[strcspn(command, "\n")] = 0;

        // Determine which command to run
        if (strcmp(command, "add") == 0) {
            char category[20];
            float amount;

            printf("\nEnter the transaction category: ");
            scanf("%s", category);

            printf("Enter the amount in dollars: ");
            scanf("%f", &amount);

            Transaction newTransaction;
            strcpy(newTransaction.category, category);
            newTransaction.amount = amount;

            transactions[transactionCount] = newTransaction;
            transactionCount++;

            printf("\nTransaction added successfully!");
        } else if (strcmp(command, "total") == 0) {
            float total = 0;

            for (int i = 0; i < transactionCount; i++) {
                total += transactions[i].amount;
            }

            printf("\nTotal spent so far is $%.2f", total);
        } else if (strcmp(command, "quit") == 0) {
            printf("\nExiting program...\n");
            exit(0);
        } else {
            printf("\nInvalid command!");
        }
    }

    return 0;
}