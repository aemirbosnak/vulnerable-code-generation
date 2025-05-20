//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: excited
/*
 * A C Personal Finance Planner
 *
 * This program will help you plan your finances by
 * calculating your expenses, savings, and budget.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure for a financial transaction
struct transaction {
    char type; // "E" for expense, "S" for savings
    double amount;
};

// Define the structure for a financial budget
struct budget {
    double income;
    double expenses;
    double savings;
};

// Function to calculate the total expenses
double calculate_expenses(struct transaction *transactions, int num_transactions) {
    double total = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].type == 'E') {
            total += transactions[i].amount;
        }
    }
    return total;
}

// Function to calculate the total savings
double calculate_savings(struct transaction *transactions, int num_transactions) {
    double total = 0;
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].type == 'S') {
            total += transactions[i].amount;
        }
    }
    return total;
}

// Function to calculate the budget
struct budget calculate_budget(double income, double expenses, double savings) {
    struct budget budget;
    budget.income = income;
    budget.expenses = expenses;
    budget.savings = savings;
    return budget;
}

// Function to print the budget
void print_budget(struct budget budget) {
    printf("Income: $%.2f\n", budget.income);
    printf("Expenses: $%.2f\n", budget.expenses);
    printf("Savings: $%.2f\n", budget.savings);
}

// Function to read the transactions
void read_transactions(struct transaction *transactions, int num_transactions) {
    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction %d:\n", i + 1);
        printf("Type (E for expense, S for savings): ");
        scanf("%c", &transactions[i].type);
        printf("Amount: ");
        scanf("%lf", &transactions[i].amount);
    }
}

// Function to calculate the budget
void calculate_budget_and_print(struct transaction *transactions, int num_transactions) {
    double income = 0;
    double expenses = calculate_expenses(transactions, num_transactions);
    double savings = calculate_savings(transactions, num_transactions);
    struct budget budget = calculate_budget(income, expenses, savings);
    print_budget(budget);
}

int main() {
    // Define the number of transactions
    int num_transactions = 5;

    // Define the transactions
    struct transaction transactions[num_transactions];

    // Read the transactions
    read_transactions(transactions, num_transactions);

    // Calculate the budget and print it
    calculate_budget_and_print(transactions, num_transactions);

    return 0;
}