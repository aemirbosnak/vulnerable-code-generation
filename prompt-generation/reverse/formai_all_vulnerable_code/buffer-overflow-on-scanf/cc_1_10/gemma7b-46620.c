//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TRANSACTIONS 100

struct Transaction {
    char description[50];
    double amount;
    double category;
};

int main() {
    // Allocate memory for the transactions
    struct Transaction *transactions = (struct Transaction *)malloc(MAX_TRANSACTIONS * sizeof(struct Transaction));

    // Get the number of transactions
    int numTransactions = 0;

    // Loop over the transactions
    while (numTransactions < MAX_TRANSACTIONS) {
        // Get the transaction description
        printf("Enter the transaction description: ");
        scanf("%s", transactions[numTransactions].description);

        // Get the transaction amount
        printf("Enter the transaction amount: ");
        scanf("%lf", &transactions[numTransactions].amount);

        // Get the transaction category
        printf("Enter the transaction category: ");
        scanf("%lf", &transactions[numTransactions].category);

        // Increment the number of transactions
        numTransactions++;
    }

    // Print the transactions
    printf("Here are your transactions:\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("Description: %s\n", transactions[i].description);
        printf("Amount: %.2lf\n", transactions[i].amount);
        printf("Category: %.2lf\n", transactions[i].category);
        printf("\n");
    }

    // Free the memory allocated for the transactions
    free(transactions);

    return 0;
}