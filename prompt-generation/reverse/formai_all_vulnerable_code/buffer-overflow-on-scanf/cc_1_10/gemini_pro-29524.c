//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of transactions
#define MAX_TRANSACTIONS 100

// Define the structure of a transaction
typedef struct {
    char *description;
    double amount;
    int type; // 0 for expense, 1 for income
} transaction_t;

// Create an array of transactions
transaction_t transactions[MAX_TRANSACTIONS];

// Get the number of transactions from the user
int get_num_transactions() {
    int num_transactions;
    printf("Enter the number of transactions: ");
    scanf("%d", &num_transactions);
    return num_transactions;
}

// Get the details of a transaction from the user
transaction_t get_transaction(int index) {
    transaction_t transaction;

    // Get the description of the transaction
    char description[100];
    printf("Enter the description of transaction %d: ", index + 1);
    scanf("%s", description);
    transaction.description = strdup(description);

    // Get the amount of the transaction
    double amount;
    printf("Enter the amount of transaction %d: ", index + 1);
    scanf("%lf", &amount);
    transaction.amount = amount;

    // Get the type of the transaction
    int type;
    printf("Enter the type of transaction %d (0 for expense, 1 for income): ", index + 1);
    scanf("%d", &type);
    transaction.type = type;

    return transaction;
}

// Calculate the total expenses and income
void calculate_totals(int num_transactions, double *total_expenses, double *total_income) {
    *total_expenses = 0;
    *total_income = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].type == 0) {
            *total_expenses += transactions[i].amount;
        } else {
            *total_income += transactions[i].amount;
        }
    }
}

// Print the transactions
void print_transactions(int num_transactions) {
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%d. %s - %lf\n", i + 1, transactions[i].description, transactions[i].amount);
    }
}

// Print the totals
void print_totals(double total_expenses, double total_income) {
    printf("\nTotals:\n");
    printf("Total expenses: %lf\n", total_expenses);
    printf("Total income: %lf\n", total_income);
}

// Main function
int main() {
    // Get the number of transactions from the user
    int num_transactions = get_num_transactions();

    // Get the details of each transaction from the user
    for (int i = 0; i < num_transactions; i++) {
        transactions[i] = get_transaction(i);
    }

    // Calculate the total expenses and income
    double total_expenses, total_income;
    calculate_totals(num_transactions, &total_expenses, &total_income);

    // Print the transactions
    print_transactions(num_transactions);

    // Print the totals
    print_totals(total_expenses, total_income);

    return 0;
}