//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>

int main() {
    // Declare variables
    int user_input;
    float balance = 1000.00;
    float savings = 0.00;
    float interest_rate = 0.05;
    float monthly_savings = 0.00;
    float monthly_expenses = 0.00;
    float total_expenses = 0.00;
    float total_savings = 0.00;
    float total_balance = 0.00;
    int years = 0;

    // Ask user for input
    printf("Welcome to the Personal Finance Planner\n");
    printf("Please enter your annual income: ");
    scanf("%d", &user_input);
    printf("Please enter your monthly expenses: ");
    scanf("%f", &monthly_expenses);
    printf("Please enter your desired savings rate: ");
    scanf("%f", &savings);

    // Calculate monthly income
    float monthly_income = user_input / 12;

    // Calculate total expenses
    total_expenses = monthly_expenses * 12;

    // Calculate monthly savings
    monthly_savings = (monthly_income - total_expenses) * savings;

    // Calculate total savings
    total_savings = monthly_savings * 12;

    // Calculate total balance
    total_balance = balance + total_savings;

    // Calculate number of years
    years = total_balance / total_savings;

    // Print results
    printf("Total income: $%.2f\n", monthly_income * 12);
    printf("Total expenses: $%.2f\n", total_expenses);
    printf("Monthly savings: $%.2f\n", monthly_savings);
    printf("Total savings: $%.2f\n", total_savings);
    printf("Total balance: $%.2f\n", total_balance);
    printf("Years to reach $%.2f: %d\n", total_savings, years);

    return 0;
}