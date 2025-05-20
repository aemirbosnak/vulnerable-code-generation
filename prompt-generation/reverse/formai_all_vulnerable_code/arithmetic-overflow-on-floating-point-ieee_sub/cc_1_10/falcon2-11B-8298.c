//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Variables to track income and expenses
    double income = 1000.0;
    double expenses = 0.0;
    double savings = 0.0;

    // Variables to track account balance and interest earned
    double account_balance = 0.0;
    double interest_earned = 0.0;

    // Initialize account balance and interest rate
    double interest_rate = 0.05;
    account_balance = 1000.0;

    // Loop through each day
    for (int day = 1; day <= 365; day++)
    {
        // Calculate interest earned on account balance
        interest_earned += (account_balance * interest_rate);

        // Prompt user to enter income and expenses for the day
        printf("Enter income for day %d: ", day);
        double income_day = scanf("%lf", &income);

        // Prompt user to enter expenses for the day
        printf("Enter expenses for day %d: ", day);
        double expenses_day = scanf("%lf", &expenses);

        // Update income and expenses variables
        income += income_day;
        expenses += expenses_day;

        // Update account balance and savings
        account_balance -= expenses_day;
        savings += (income - expenses);

        // Print the account balance, interest earned, income, and expenses
        printf("Account balance: %.2lf\n", account_balance);
        printf("Interest earned: %.2lf\n", interest_earned);
        printf("Income: %.2lf\n", income);
        printf("Expenses: %.2lf\n", expenses);
    }

    // Print final balance, interest earned, income, and expenses
    printf("Final balance: %.2lf\n", account_balance);
    printf("Interest earned: %.2lf\n", interest_earned);
    printf("Income: %.2lf\n", income);
    printf("Expenses: %.2lf\n", expenses);

    // Print savings and total expenses
    printf("Savings: %.2lf\n", savings);
    printf("Total expenses: %.2lf\n", expenses);

    return 0;
}