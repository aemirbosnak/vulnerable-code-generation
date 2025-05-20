//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
/*
 * Personal Finance Planner
 * A program to help users plan their finances
 */

#include <stdio.h>
#include <stdlib.h>

// Structure to hold user's financial information
struct FinancialInfo {
    float income;
    float expenses[10];
    int num_expenses;
};

// Function to calculate total expenses
float calculate_total_expenses(struct FinancialInfo *info) {
    float total = 0;
    for (int i = 0; i < info->num_expenses; i++) {
        total += info->expenses[i];
    }
    return total;
}

// Function to calculate savings
float calculate_savings(struct FinancialInfo *info) {
    return info->income - calculate_total_expenses(info);
}

// Function to print financial information
void print_financial_info(struct FinancialInfo *info) {
    printf("Income: %.2f\n", info->income);
    for (int i = 0; i < info->num_expenses; i++) {
        printf("Expense %d: %.2f\n", i + 1, info->expenses[i]);
    }
    printf("Total expenses: %.2f\n", calculate_total_expenses(info));
    printf("Savings: %.2f\n", calculate_savings(info));
}

// Main function
int main() {
    struct FinancialInfo info;

    // Get user's income
    printf("Enter your income: ");
    scanf("%f", &info.income);

    // Get user's expenses
    printf("Enter the number of expenses: ");
    scanf("%d", &info.num_expenses);
    for (int i = 0; i < info.num_expenses; i++) {
        printf("Enter expense %d: ", i + 1);
        scanf("%f", &info.expenses[i]);
    }

    // Print financial information
    print_financial_info(&info);

    return 0;
}