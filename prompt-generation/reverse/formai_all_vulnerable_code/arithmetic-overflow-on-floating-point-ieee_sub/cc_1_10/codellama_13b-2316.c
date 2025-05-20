//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: accurate
/*
 * C Personal Finance Planner Example Program
 *
 * This program allows users to input their monthly income and expenses,
 * and calculates their net worth and suggested savings amounts.
 */

#include <stdio.h>

// Define the data structures used in the program
typedef struct {
    double income;
    double expenses;
} FinancialData;

typedef struct {
    double net_worth;
    double savings;
} FinancialPlan;

// Define the functions used in the program
FinancialData get_financial_data();
FinancialPlan calculate_financial_plan(FinancialData data);
void print_financial_plan(FinancialPlan plan);

int main() {
    // Get the financial data from the user
    FinancialData data = get_financial_data();

    // Calculate the financial plan
    FinancialPlan plan = calculate_financial_plan(data);

    // Print the financial plan
    print_financial_plan(plan);

    return 0;
}

// Function to get the financial data from the user
FinancialData get_financial_data() {
    FinancialData data;

    // Get the income
    printf("Enter your monthly income: ");
    scanf("%lf", &data.income);

    // Get the expenses
    printf("Enter your monthly expenses: ");
    scanf("%lf", &data.expenses);

    return data;
}

// Function to calculate the financial plan
FinancialPlan calculate_financial_plan(FinancialData data) {
    FinancialPlan plan;

    // Calculate the net worth
    plan.net_worth = data.income - data.expenses;

    // Calculate the suggested savings amount
    plan.savings = plan.net_worth * 0.1;

    return plan;
}

// Function to print the financial plan
void print_financial_plan(FinancialPlan plan) {
    printf("Your net worth is: $%.2f\n", plan.net_worth);
    printf("Your suggested savings amount is: $%.2f\n", plan.savings);
}