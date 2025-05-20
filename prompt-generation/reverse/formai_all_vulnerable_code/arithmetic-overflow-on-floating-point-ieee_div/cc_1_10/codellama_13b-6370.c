//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
// Personal Finance Planner

#include <stdio.h>

int main() {
    // Declare variables
    int income, expenses, savings, debts, goal;

    // Get user input
    printf("Enter your monthly income: ");
    scanf("%d", &income);
    printf("Enter your monthly expenses: ");
    scanf("%d", &expenses);
    printf("Enter your savings: ");
    scanf("%d", &savings);
    printf("Enter your debts: ");
    scanf("%d", &debts);
    printf("Enter your financial goal: ");
    scanf("%d", &goal);

    // Calculate savings rate
    float savings_rate = (float)savings / income * 100;

    // Calculate debt-to-income ratio
    float debt_to_income = (float)debts / income;

    // Check if savings rate is sufficient
    if (savings_rate < 20) {
        printf("Your savings rate is too low. Consider increasing your savings to achieve your financial goal.\n");
    }

    // Check if debt-to-income ratio is acceptable
    if (debt_to_income > 3) {
        printf("Your debt-to-income ratio is too high. Consider paying off your debts to achieve your financial goal.\n");
    }

    // Check if goal is achievable
    if (savings + debts > goal) {
        printf("Your financial goal is not achievable. Consider adjusting your expenses or saving habits to reach your goal.\n");
    }

    // Print financial summary
    printf("Income: %d\n", income);
    printf("Expenses: %d\n", expenses);
    printf("Savings: %d\n", savings);
    printf("Debts: %d\n", debts);
    printf("Savings rate: %f%%\n", savings_rate);
    printf("Debt-to-income ratio: %f\n", debt_to_income);
    printf("Financial goal: %d\n", goal);

    return 0;
}