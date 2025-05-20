//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float monthly_income, housing_expenses, transportation_expenses, food_expenses, utilities_expenses, other_expenses, total_expenses, savings;
    int months;

    printf("Welcome to Personal Finance Planner!\n\n");

    printf("What is your monthly income?\n");
    scanf("%f", &monthly_income);

    printf("\nWhat are your monthly housing expenses?\n");
    scanf("%f", &housing_expenses);

    printf("\nWhat are your monthly transportation expenses?\n");
    scanf("%f", &transportation_expenses);

    printf("\nWhat are your monthly food expenses?\n");
    scanf("%f", &food_expenses);

    printf("\nWhat are your monthly utilities expenses?\n");
    scanf("%f", &utilities_expenses);

    printf("\nWhat are your other monthly expenses?\n");
    scanf("%f", &other_expenses);

    total_expenses = housing_expenses + transportation_expenses + food_expenses + utilities_expenses + other_expenses;

    savings = monthly_income - total_expenses;

    printf("Please enter the number of months this plan should cover:\n");
    scanf("%d", &months);

    printf("\nHere is your Personal Finance Planner report for the next %d months:\n\n", months);

    printf("Monthly Income: %.2f\n", monthly_income);
    printf("Total Monthly Expenses: %.2f\n", total_expenses);
    printf("Monthly Savings: %.2f\n\n", savings);

    for (int i = 1; i <= months; i++) {
        printf("Month %d:\n", i);
        printf("Monthly Income: %.2f\n", monthly_income);
        printf("Total Monthly Expenses: %.2f\n", total_expenses);

        if (savings > 0) {
            printf("Monthly Savings: %.2f\n\n", savings);
        } else {
            printf("You need to cut your expenses to avoid going into debt!\n\n");
        }
    }

    printf("Thank you for using Personal Finance Planner!\n");

    return 0;
}