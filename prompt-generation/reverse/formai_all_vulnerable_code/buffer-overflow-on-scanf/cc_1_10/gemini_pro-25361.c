//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double amount;
} transaction_t;

int main() {
    // Initialize the program
    int num_transactions = 0;
    transaction_t *transactions = NULL;

    // Get the number of transactions from the user
    printf("How many transactions do you want to track? ");
    scanf("%d", &num_transactions);

    // Allocate memory for the transactions
    transactions = malloc(sizeof(transaction_t) * num_transactions);

    // Get the details of each transaction from the user
    for (int i = 0; i < num_transactions; i++) {
        printf("Enter the name of the transaction: ");
        char *name = malloc(sizeof(char) * 100);
        scanf("%s", name);

        printf("Enter the amount of the transaction: ");
        double amount;
        scanf("%lf", &amount);

        // Store the transaction in the array
        transactions[i].name = name;
        transactions[i].amount = amount;
    }

    // Calculate the total amount of the transactions
    double total_amount = 0;
    for (int i = 0; i < num_transactions; i++) {
        total_amount += transactions[i].amount;
    }

    // Print the total amount of the transactions
    printf("The total amount of the transactions is: %.2f\n", total_amount);

    // Free the memory allocated for the transactions
    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i].name);
    }
    free(transactions);

    return 0;
}