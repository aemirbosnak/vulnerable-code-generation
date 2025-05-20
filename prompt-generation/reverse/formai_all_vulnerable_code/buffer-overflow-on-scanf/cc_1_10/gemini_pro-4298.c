//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Elementary, my dear Watson!
typedef struct {
    char *description;
    float amount;
} Transaction;

// The game is afoot!
int main() {
    // Initialize an array of transactions
    Transaction transactions[100];

    // Read the transactions from the user
    int numTransactions;
    printf("Enter the number of transactions: ");
    scanf("%d", &numTransactions);

    for (int i = 0; i < numTransactions; i++) {
        // Read the description and amount of the transaction
        char buffer[100];
        printf("Enter the description of transaction %d: ", i + 1);
        scanf(" %[^\n]", buffer);
        transactions[i].description = strdup(buffer);

        printf("Enter the amount of transaction %d: ", i + 1);
        scanf("%f", &transactions[i].amount);
    }

    // Calculate the total income and expenses
    float totalIncome = 0;
    float totalExpenses = 0;
    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i].amount > 0) {
            totalIncome += transactions[i].amount;
        } else {
            totalExpenses += transactions[i].amount;
        }
    }

    // Print the financial report
    printf("\nFinancial Report:\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Balance: %.2f\n", totalIncome + totalExpenses);

    // Free the allocated memory
    for (int i = 0; i < numTransactions; i++) {
        free(transactions[i].description);
    }

    return 0;
}