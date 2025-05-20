//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to Personal Finance Planner\n\n");

    // Variables for user input
    float income;
    float expenses;
    float savings;
    float percentSaved;
    int numMonths;

    // Get user input
    printf("Enter your monthly income: $");
    scanf("%f", &income);

    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);

    printf("Enter the percent of your income you want to save each month (without the percentage sign): ");
    scanf("%f", &percentSaved);

    printf("Enter the number of months you want to plan for: ");
    scanf("%d", &numMonths);

    printf("\n");

    // Calculate monthly savings and total savings
    savings = income * (percentSaved / 100.0);
    float totalSavings = savings * numMonths;

    // Display results
    printf("Here is your finance plan for the next %d months:\n\n", numMonths);

    printf("Monthly Income: $%.2f\n", income);
    printf("Monthly Expenses: $%.2f\n", expenses);
    printf("Monthly Savings: $%.2f\n", savings);
    printf("Total Savings: $%.2f\n\n", totalSavings);

    // Calculate projected expenses and income
    float projectedIncome = income * numMonths;
    float projectedExpenses = expenses * numMonths;

    printf("Here is your projected income and expenses for the next %d months:\n\n", numMonths);

    printf("Projected Income: $%.2f\n", projectedIncome);
    printf("Projected Expenses: $%.2f\n\n", projectedExpenses);

    // Calculate the difference between projected income and expenses
    float difference = projectedIncome - projectedExpenses;

    if (difference > 0) {
        printf("You have a projected surplus of $%.2f over the next %d months.\n", difference, numMonths);
    } else if (difference < 0) {
        printf("You have a projected deficit of $%.2f over the next %d months.\n", -difference, numMonths);
    } else {
        printf("You have a balanced budget over the next %d months.\n", numMonths);
    }

    return 0;
}