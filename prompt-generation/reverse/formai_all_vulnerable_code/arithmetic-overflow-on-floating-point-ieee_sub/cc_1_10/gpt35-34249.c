//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Welcome message
    printf("Welcome to Personal Finance Planner!\n\n");

    // Get user's name
    char name[20];
    printf("What is your name? ");
    scanf("%s", name);

    // Get user's income
    double income;
    printf("How much is your monthly income (in dollars)? ");
    scanf("%lf", &income);

    // Get user's expenses
    double expenses;
    printf("How much are your monthly expenses (in dollars)? ");
    scanf("%lf", &expenses);

    // Calculate user's savings
    double savings = income - expenses;

    // Print paranoid message
    printf("\n\nBEWARE %s! Your finances are always under threat. Here are the details of your finances:\n\n", name);

    // Print user's income
    printf("MONTHLY INCOME: $%.2f\n", income);

    // Print user's expenses
    printf("MONTHLY EXPENSES: $%.2f\n", expenses);

    // Print user's savings
    printf("MONTHLY SAVINGS: $%.2f\n\n\n", savings);

    // Calculate and print paranoid message
    double avg_expenses = (expenses / 30);
    double days_till_bankruptcy = savings / avg_expenses;

    if (days_till_bankruptcy > 30) {
        printf("You have %.0f days till bankruptcy. You're safe... for now.\n", days_till_bankruptcy);
    } else if (days_till_bankruptcy > 7 && days_till_bankruptcy <= 30) {
        printf("You have %.0f days till bankruptcy. You're cutting it close, %s.\n", days_till_bankruptcy, name);
    } else {
        printf("You have %.0f days till bankruptcy. Get your finances under control, %s!\n", days_till_bankruptcy, name);
    }

    // Return 0 if everything went well
    return 0;
}