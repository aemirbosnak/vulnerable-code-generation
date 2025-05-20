//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: mathematical
#include <stdio.h>

int main() {

    // input variables
    double budget;
    double expenses;

    // expense categories as percentages of budget
    const double rent = 0.3;
    const double food = 0.2;
    const double transportation = 0.1;
    const double entertainment = 0.15;
    const double savings = 0.15;
    const double miscellaneous = 0.1;

    // calculated values
    double rentAmount;
    double foodAmount;
    double transAmount;
    double entAmount;
    double savAmount;
    double miscAmount;

    // gather user inputs
    printf("Enter your monthly budget: ");
    scanf("%lf", &budget);
    
    printf("Enter your monthly expenses: ");
    scanf("%lf", &expenses);

    // calculate amounts for each expense category
    rentAmount = rent * budget;
    foodAmount = food * budget;
    transAmount = transportation * budget;
    entAmount = entertainment * budget;
    savAmount = savings * budget;
    miscAmount = miscellaneous * budget;

    // calculate total expenses and remaining budget
    double totalExpenses = rentAmount + foodAmount + transAmount + entAmount + savAmount + miscAmount;
    double remainingBudget = budget - totalExpenses;

    // output expense breakdown
    printf("\n---- Expense Breakdown ----\n");

    printf("Rent: $%.2lf (%.0lf%% of budget)\n", rentAmount, rent * 100);
    printf("Food: $%.2lf (%.0lf%% of budget)\n", foodAmount, food * 100);
    printf("Transportation: $%.2lf (%.0lf%% of budget)\n", transAmount, transportation * 100);
    printf("Entertainment: $%.2lf (%.0lf%% of budget)\n", entAmount, entertainment * 100);
    printf("Savings: $%.2lf (%.0lf%% of budget)\n", savAmount, savings * 100);
    printf("Miscellaneous: $%.2lf (%.0lf%% of budget)\n", miscAmount, miscellaneous * 100);

    printf("\nTotal expenses: $%.2lf\n", totalExpenses);
    printf("Remaining budget: $%.2lf\n", remainingBudget);

    return 0;
}