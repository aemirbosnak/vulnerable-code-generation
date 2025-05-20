//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>

int main() {
    
    float monthly_income, monthly_expenses, savings_goal, current_savings;
    float total_expense = 0;
    int expense_count = 0;

    // Input user data
    printf("Welcome to the Personal Finance Planner!\n");
    printf("\nEnter your monthly income: $");
    scanf("%f", &monthly_income);
    printf("Enter your monthly expenses: $");
    scanf("%f", &monthly_expenses);
    printf("Enter your current savings: $");
    scanf("%f", &current_savings);

    // Calculate total monthly savings
    float total_monthly_savings = monthly_income - monthly_expenses;

    // Ask user for a savings goal
    printf("\nWhat is your savings goal? $");
    scanf("%f", &savings_goal);

    // Calculate monthly savings needed to achieve savings goal by target month
    int target_month, target_year;
    printf("\nWhat month (1-12) and year would you like to achieve your savings goal? ");
    scanf("%d%d", &target_month, &target_year);
    int months_remaining = ((target_year - 2022) * 12) + (target_month - 1);
    float monthly_savings_needed = (savings_goal - current_savings) / months_remaining;

    // Keep track of expenses
    char option;
    do {
        float expense;
        printf("\nEnter your expense amount: $");
        scanf("%f", &expense);
        total_expense += expense;
        expense_count++;
        printf("Enter another expense? (y/n): ");
        scanf(" %c", &option);
    } while (option == 'y');

    // Calculate average monthly spending
    float avg_monthly_spending = total_expense / expense_count;

    // Print out financial summary
    printf("\n--- Personal Finance Summary ---\n");
    printf("Monthly Income: $%.2f\n", monthly_income);
    printf("Monthly Expenses: $%.2f\n", monthly_expenses);
    printf("Total Monthly Savings: $%.2f\n", total_monthly_savings);
    printf("Current Savings: $%.2f\n", current_savings);
    printf("Savings Goal: $%.2f\n", savings_goal);
    printf("Monthly Savings Needed: $%.2f\n", monthly_savings_needed);
    printf("Avg Monthly Spending: $%.2f\n", avg_monthly_spending);

    return 0;
}