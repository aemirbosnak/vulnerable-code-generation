//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Define a struct for a transaction
typedef struct {
    char *description;
    double amount;
    char *category;
} Transaction;

// Function to add a transaction
void add_transaction(Transaction *transactions, int *num_transactions, char *description, double amount, char *category) {
    (*num_transactions)++;
    transactions = realloc(transactions, sizeof(Transaction) * (*num_transactions));
    transactions[*num_transactions - 1].description = description;
    transactions[*num_transactions - 1].amount = amount;
    transactions[*num_transactions - 1].category = category;
}

// Function to print transactions
void print_transactions(Transaction *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("%s - $%.2f - %s\n", transactions[i].description, transactions[i].amount, transactions[i].category);
    }
}

// Function to calculate total spending by category
void calculate_spending(Transaction *transactions, int num_transactions, char *category, double *total_spending) {
    *total_spending = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (strcmp(transactions[i].category, category) == 0) {
            *total_spending += transactions[i].amount;
        }
    }
}

int main() {
    // Initialize variables
    int num_transactions = 0;
    Transaction *transactions = NULL;

    // Add some sample transactions
    add_transaction(transactions, &num_transactions, "Cyberpunk clothing", 100.00, "Fashion");
    add_transaction(transactions, &num_transactions, "Neural implant upgrade", 500.00, "Tech");
    add_transaction(transactions, &num_transactions, "Street food", 10.00, "Food");

    // Print all transactions
    print_transactions(transactions, num_transactions);

    // Calculate total spending by category
    double total_spending;
    calculate_spending(transactions, num_transactions, "Fashion", &total_spending);
    printf("Total spending on fashion: $%.2f\n", total_spending);

    calculate_spending(transactions, num_transactions, "Tech", &total_spending);
    printf("Total spending on tech: $%.2f\n", total_spending);

    calculate_spending(transactions, num_transactions, "Food", &total_spending);
    printf("Total spending on food: $%.2f\n", total_spending);

    // Free memory
    for (int i = 0; i < num_transactions; i++) {
        free(transactions[i].description);
        free(transactions[i].category);
    }
    free(transactions);

    return 0;
}