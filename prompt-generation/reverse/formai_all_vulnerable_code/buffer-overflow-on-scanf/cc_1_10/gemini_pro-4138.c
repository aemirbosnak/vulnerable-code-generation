//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store income and expense data
typedef struct {
    char description[50];
    float amount;
} Transaction;

// Function to add a transaction to the list
void add_transaction(Transaction *transactions, int *num_transactions, Transaction transaction) {
    // Reallocate memory if needed
    if (*num_transactions >= 100) {
        transactions = realloc(transactions, sizeof(Transaction) * (*num_transactions + 1));
    }

    // Add the transaction to the list
    transactions[*num_transactions] = transaction;
    *num_transactions += 1;
}

// Function to print the list of transactions
void print_transactions(Transaction *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("%s: %.2f\n", transactions[i].description, transactions[i].amount);
    }
}

// Function to calculate the total income and expenses
void calculate_totals(Transaction *transactions, int num_transactions, float *total_income, float *total_expenses) {
    *total_income = 0;
    *total_expenses = 0;

    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].amount > 0) {
            *total_income += transactions[i].amount;
        } else {
            *total_expenses += transactions[i].amount;
        }
    }
}

// Function to generate a report
void generate_report(Transaction *transactions, int num_transactions) {
    float total_income, total_expenses;

    // Calculate the total income and expenses
    calculate_totals(transactions, num_transactions, &total_income, &total_expenses);

    // Print the report
    printf("Personal Finance Report\n");
    printf("=======================\n");
    printf("Total Income: %.2f\n", total_income);
    printf("Total Expenses: %.2f\n", total_expenses);
    printf("Net Income: %.2f\n", total_income + total_expenses);
    printf("\n");
    printf("Transactions:\n");
    print_transactions(transactions, num_transactions);
}

// Main function
int main() {
    // Declare variables
    Transaction transactions[100];
    int num_transactions = 0;
    int choice;
    Transaction transaction;

    // Loop until the user chooses to quit
    do {
        // Display the menu
        printf("Personal Finance Planner\n");
        printf("=======================\n");
        printf("1. Add a transaction\n");
        printf("2. Print the list of transactions\n");
        printf("3. Generate a report\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice) {
            case 1:
                // Get the transaction details from the user
                printf("Enter the transaction description: ");
                scanf("%s", transaction.description);
                printf("Enter the transaction amount: ");
                scanf("%f", &transaction.amount);

                // Add the transaction to the list
                add_transaction(transactions, &num_transactions, transaction);

                break;
            case 2:
                // Print the list of transactions
                print_transactions(transactions, num_transactions);

                break;
            case 3:
                // Generate a report
                generate_report(transactions, num_transactions);

                break;
            case 4:
                // Quit the program
                break;
            default:
                // Invalid choice
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}