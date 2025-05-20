//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

// Constants
#define MAX_INCOME_CATEGORIES 5
#define MAX_EXPENSE_CATEGORIES 5

// Income and expense categories
char* income_categories[] = {"Salary", "Investments", "Business", "Gifts", "Other"};
char* expense_categories[] = {"Rent/Mortgage", "Utilities", "Food", "Transportation", "Entertainment"};

// Income and expense amounts
double income_amounts[MAX_INCOME_CATEGORIES];
double expense_amounts[MAX_EXPENSE_CATEGORIES];

// Calculate total income
double calculate_total_income() {
    double total_income = 0.0;
    for (int i = 0; i < MAX_INCOME_CATEGORIES; i++) {
        total_income += income_amounts[i];
    }
    return total_income;
}

// Calculate total expenses
double calculate_total_expenses() {
    double total_expenses = 0.0;
    for (int i = 0; i < MAX_EXPENSE_CATEGORIES; i++) {
        total_expenses += expense_amounts[i];
    }
    return total_expenses;
}

// Calculate net income
double calculate_net_income() {
    double net_income = calculate_total_income() - calculate_total_expenses();
    return net_income;
}

// Print income and expense report
void print_report() {
    printf("Personal Finance Planner\n");
    printf("========================\n");

    // Print income categories and amounts
    printf("Income:\n");
    for (int i = 0; i < MAX_INCOME_CATEGORIES; i++) {
        printf("%-20s%-10.2f\n", income_categories[i], income_amounts[i]);
    }

    // Print expense categories and amounts
    printf("\nExpenses:\n");
    for (int i = 0; i < MAX_EXPENSE_CATEGORIES; i++) {
        printf("%-20s%-10.2f\n", expense_categories[i], expense_amounts[i]);
    }

    // Print net income
    printf("\nNet Income: %-10.2f\n", calculate_net_income());
}

// Main function
int main() {

    // Get income amounts from the user
    for (int i = 0; i < MAX_INCOME_CATEGORIES; i++) {
        printf("Enter amount for %s: ", income_categories[i]);
        scanf("%lf", &income_amounts[i]);
    }

    // Get expense amounts from the user
    for (int i = 0; i < MAX_EXPENSE_CATEGORIES; i++) {
        printf("Enter amount for %s: ", expense_categories[i]);
        scanf("%lf", &expense_amounts[i]);
    }

    // Print income and expense report
    print_report();

    return 0;
}