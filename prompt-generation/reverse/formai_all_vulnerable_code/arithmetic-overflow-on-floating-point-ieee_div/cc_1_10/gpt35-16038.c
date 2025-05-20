//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: introspective
#include <stdio.h>

/* Personal Finance Planner */
/* This program helps a user plan and track their monthly expenses and income. */
/* Users will enter their income and expenses, and the program will calculate their net income and */
/* provide an overview of their monthly spending patterns. */

int main()
{
    /* variables to store user input */
    float income, housing, transportation, food, utilities, entertainment, other;

    /* Ask the user for their income */
    printf("Enter your monthly income: ");
    scanf("%f", &income);

    /* Ask the user for their monthly expenses */
    printf("Enter your monthly housing expense: ");
    scanf("%f", &housing);

    printf("Enter your monthly transportation expense: ");
    scanf("%f", &transportation);

    printf("Enter your monthly food expense: ");
    scanf("%f", &food);

    printf("Enter your monthly utilities expense: ");
    scanf("%f", &utilities);

    printf("Enter your monthly entertainment expense: ");
    scanf("%f", &entertainment);

    printf("Enter your other monthly expenses: ");
    scanf("%f", &other);

    /* Calculate monthly net income */
    float expenses = housing + transportation + food + utilities + entertainment + other;
    float net_income = income - expenses;

    /* Provide a summary of monthly finances */
    printf("\n");
    printf("MONTHLY FINANCES\n");
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", expenses);
    printf("Net Income: $%.2f\n", net_income);
    printf("\n");

    /* Determine what percent of monthly income is allocated to each expense category */
    float housing_percent = (housing / income) * 100;
    float transportation_percent = (transportation / income) * 100;
    float food_percent = (food / income) * 100;
    float utilities_percent = (utilities / income) * 100;
    float entertainment_percent = (entertainment / income) * 100;
    float other_percent = (other / income) * 100;

    /* Provide an overview of monthly spending patterns */
    printf("EXPENSE OVERVIEW\n");
    printf("Housing: %.2f%%\n", housing_percent);
    printf("Transportation: %.2f%%\n", transportation_percent);
    printf("Food: %.2f%%\n", food_percent);
    printf("Utilities: %.2f%%\n", utilities_percent);
    printf("Entertainment: %.2f%%\n", entertainment_percent);
    printf("Other: %.2f%%\n", other_percent);

    return 0;
}