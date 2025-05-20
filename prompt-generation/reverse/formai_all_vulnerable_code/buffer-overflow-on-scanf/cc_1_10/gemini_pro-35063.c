//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char description[50];
    float amount;
    char type; // 'I' for income, 'E' for expense
} transaction;

// Initialize the array of transactions
transaction transactions[MAX_TRANSACTIONS];

// The number of transactions
int num_transactions = 0;

// Get the user's input
void get_input() {
    printf("Enter a description for the transaction: ");
    scanf("%s", transactions[num_transactions].description);

    printf("Enter the amount of the transaction: ");
    scanf("%f", &transactions[num_transactions].amount);

    printf("Enter the type of the transaction (I for income, E for expense): ");
    scanf(" %c", &transactions[num_transactions].type);

    num_transactions++;
}

// Print the list of transactions
void print_transactions() {
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s\t%.2f\t%c\n", transactions[i].description, transactions[i].amount, transactions[i].type);
    }
}

// Calculate the total income and expenses
void calculate_totals() {
    float total_income = 0;
    float total_expenses = 0;

    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].type == 'I') {
            total_income += transactions[i].amount;
        } else if (transactions[i].type == 'E') {
            total_expenses += transactions[i].amount;
        }
    }

    printf("\nTotal income: %.2f\n", total_income);
    printf("Total expenses: %.2f\n", total_expenses);
}

// Main function
int main() {
    // Get the user's input
    get_input();

    // Print the list of transactions
    print_transactions();

    // Calculate the total income and expenses
    calculate_totals();

    return 0;
}