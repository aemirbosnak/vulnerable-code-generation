//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Welcome message
    printf("Welcome to Personal Finance Planner\n");

    // Variables to hold user data
    float monthlyIncome, housingExpenses, foodExpenses, transportationExpenses, entertainmentExpenses;
    float totalExpenses, monthlySavings;

    // Get user data
    printf("Please enter your monthly income: $");
    scanf("%f", &monthlyIncome);

    printf("Please enter your monthly housing expenses: $");
    scanf("%f", &housingExpenses);

    printf("Please enter your monthly food expenses: $");
    scanf("%f", &foodExpenses);

    printf("Please enter your monthly transportation expenses: $");
    scanf("%f", &transportationExpenses);

    printf("Please enter your monthly entertainment expenses: $");
    scanf("%f", &entertainmentExpenses);

    // Calculate total expenses and monthly savings
    totalExpenses = housingExpenses + foodExpenses + transportationExpenses + entertainmentExpenses;
    monthlySavings = monthlyIncome - totalExpenses;

    // Output results
    printf("\nYour monthly income: $%.2f\n", monthlyIncome);
    printf("Your monthly housing expenses: $%.2f\n", housingExpenses);
    printf("Your monthly food expenses: $%.2f\n", foodExpenses);
    printf("Your monthly transportation expenses: $%.2f\n", transportationExpenses);
    printf("Your monthly entertainment expenses: $%.2f\n", entertainmentExpenses);
    printf("Your total monthly expenses: $%.2f\n", totalExpenses);
    printf("Your monthly savings: $%.2f\n", monthlySavings);

    // Determine if user is meeting their savings goals
    if (monthlySavings <= 0) {
        printf("You are spending more than you are earning. You need to adjust your budget.\n");
    } else if (monthlySavings <= 500) {
        printf("You are saving enough to meet your basic needs, but you may want to consider some adjustments to meet your long-term financial goals.\n");
    } else if (monthlySavings <= 1000) {
        printf("You are on track to meet your long-term financial goals.\n");
    } else {
        printf("You are making great progress towards your financial goals.\n");
    }

    return 0;
}