//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char *description;
    double amount;
} transaction_t;

int main() {
    // Declare variables
    int num_transactions = 0;
    transaction_t *transactions = NULL;
    double total_income = 0.0;
    double total_expenses = 0.0;
    double balance = 0.0;

    // Allocate memory for transactions
    transactions = malloc(sizeof(transaction_t) * 100);
    if (transactions == NULL) {
        fprintf(stderr, "Error: could not allocate memory for transactions\n");
        exit(EXIT_FAILURE);
    }

    // Read transactions from user
    while (1) {
        // Prompt user for transaction description
        printf("Enter transaction description (or 'q' to quit): ");
        char description[100];
        fgets(description, sizeof(description), stdin);

        // Check if user entered 'q' to quit
        if (strcmp(description, "q\n") == 0) {
            break;
        }

        // Prompt user for transaction amount
        double amount;
        printf("Enter transaction amount: ");
        scanf("%lf", &amount);

        // Add transaction to array
        transactions[num_transactions].description = strdup(description);
        transactions[num_transactions].amount = amount;
        num_transactions++;
    }

    // Calculate total income and expenses
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].amount > 0) {
            total_income += transactions[i].amount;
        } else {
            total_expenses += transactions[i].amount;
        }
    }

    // Calculate balance
    balance = total_income + total_expenses;

    // Print report
    printf("\nPersonal Finance Report\n");
    printf("======================\n");
    printf("Total Income:  $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Balance:       $%.2f\n", balance);

    // Free memory
    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i].description);
    }
    free(transactions);

    return 0;
}