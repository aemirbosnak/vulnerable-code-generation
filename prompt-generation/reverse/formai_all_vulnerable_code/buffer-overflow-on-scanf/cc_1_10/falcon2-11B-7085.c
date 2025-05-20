//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Declare variables
    double income, expenses, savings, investment;
    double total_income, total_expenses, total_savings, total_investment;
    int days, months, years;
    double year_income, year_expenses, year_savings, year_investment;

    // Initialize variables
    income = 0.0;
    expenses = 0.0;
    savings = 0.0;
    investment = 0.0;
    total_income = 0.0;
    total_expenses = 0.0;
    total_savings = 0.0;
    total_investment = 0.0;
    days = 0;
    months = 0;
    years = 0;
    year_income = 0.0;
    year_expenses = 0.0;
    year_savings = 0.0;
    year_investment = 0.0;

    // Input income and expenses
    printf("Enter your monthly income: ");
    scanf("%lf", &income);
    printf("Enter your monthly expenses: ");
    scanf("%lf", &expenses);

    // Calculate total income and expenses
    total_income = income * 12;
    total_expenses = expenses * 12;

    // Input savings and investment
    printf("Enter your monthly savings: ");
    scanf("%lf", &savings);
    printf("Enter your monthly investment: ");
    scanf("%lf", &investment);

    // Calculate total savings and investment
    total_savings = savings * 12;
    total_investment = investment * 12;

    // Calculate total income, expenses, savings, and investment for the year
    year_income = total_income;
    year_expenses = total_expenses;
    year_savings = total_savings;
    year_investment = total_investment;

    // Calculate total days, months, and years
    days = 365;
    months = 12;
    years = 1;

    // Calculate total income, expenses, savings, and investment for the year
    year_income = year_income * days;
    year_expenses = year_expenses * days;
    year_savings = year_savings * days;
    year_investment = year_investment * days;

    // Print the results
    printf("Total income for the year: %.2lf\n", year_income);
    printf("Total expenses for the year: %.2lf\n", year_expenses);
    printf("Total savings for the year: %.2lf\n", year_savings);
    printf("Total investment for the year: %.2lf\n", year_investment);

    // Calculate the percentage of income, expenses, savings, and investment for the year
    double income_percentage = (year_income / year_income * 100);
    double expenses_percentage = (year_expenses / year_income * 100);
    double savings_percentage = (year_savings / year_income * 100);
    double investment_percentage = (year_investment / year_income * 100);

    // Print the percentage results
    printf("Income percentage: %.2lf%%\n", income_percentage);
    printf("Expenses percentage: %.2lf%%\n", expenses_percentage);
    printf("Savings percentage: %.2lf%%\n", savings_percentage);
    printf("Investment percentage: %.2lf%%\n", investment_percentage);

    // Output the number of days, months, and years
    printf("Total days: %d\n", days);
    printf("Total months: %d\n", months);
    printf("Total years: %d\n", years);

    return 0;
}