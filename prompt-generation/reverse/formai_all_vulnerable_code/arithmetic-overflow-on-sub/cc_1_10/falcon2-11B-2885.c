//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <sys/time.h>

int main()
{
    // Initialize variables
    char* input = "Enter your financial information: ";
    char* output = "Your financial information: ";
    char* budget = "Budget: ";
    char* income = "Income: ";
    char* expenses = "Expenses: ";
    char* savings = "Savings: ";
    int budget_amount = 0;
    int income_amount = 0;
    int expenses_amount = 0;
    int savings_amount = 0;
    int current_month = 1;
    int next_month = 0;
    int months_tracked = 0;

    // Prompt user for input
    printf("%s", input);
    fgets(input, 100, stdin);

    // Parse input and calculate financial information
    sscanf(input, "%s %s %s %s %s %s", budget, income, expenses, savings, budget_amount, income_amount);
    sscanf(budget, "%d", &budget_amount);
    sscanf(income, "%d", &income_amount);
    sscanf(expenses, "%d", &expenses_amount);
    sscanf(savings, "%d", &savings_amount);

    // Calculate next month's budget and savings
    next_month = income_amount - expenses_amount + savings_amount;
    if (next_month > 0) {
        savings_amount += next_month;
        budget_amount -= next_month;
    }

    // Print output
    printf("%s", output);
    printf("%s %d %s %d %s %d %s %d %s %d %s %d %s\n", budget, budget_amount, income, income_amount, expenses, expenses_amount, savings, savings_amount, current_month, "Month: ", next_month, "Next Month: ");

    // Track months tracked
    months_tracked++;

    // Print summary
    printf("Financial summary:\n");
    printf("Total months tracked: %d\n", months_tracked);
    printf("Total budget: $%.2f\n", (budget_amount * 100) / (months_tracked * 100));
    printf("Total income: $%.2f\n", (income_amount * 100) / (months_tracked * 100));
    printf("Total expenses: $%.2f\n", (expenses_amount * 100) / (months_tracked * 100));
    printf("Total savings: $%.2f\n", (savings_amount * 100) / (months_tracked * 100));

    // Repeat program until user exits
    while (1) {
        // Prompt user for input
        printf("%s", input);
        fgets(input, 100, stdin);

        // Parse input and calculate financial information
        sscanf(input, "%s %s %s %s %s %s", budget, income, expenses, savings, budget_amount, income_amount);
        sscanf(budget, "%d", &budget_amount);
        sscanf(income, "%d", &income_amount);
        sscanf(expenses, "%d", &expenses_amount);
        sscanf(savings, "%d", &savings_amount);

        // Calculate next month's budget and savings
        next_month = income_amount - expenses_amount + savings_amount;
        if (next_month > 0) {
            savings_amount += next_month;
            budget_amount -= next_month;
        }

        // Print output
        printf("%s", output);
        printf("%s %d %s %d %s %d %s %d %s %d %s %d %s\n", budget, budget_amount, income, income_amount, expenses, expenses_amount, savings, savings_amount, current_month, "Month: ", next_month, "Next Month: ");

        // Track months tracked
        months_tracked++;

        // Print summary
        printf("Financial summary:\n");
        printf("Total months tracked: %d\n", months_tracked);
        printf("Total budget: $%.2f\n", (budget_amount * 100) / (months_tracked * 100));
        printf("Total income: $%.2f\n", (income_amount * 100) / (months_tracked * 100));
        printf("Total expenses: $%.2f\n", (expenses_amount * 100) / (months_tracked * 100));
        printf("Total savings: $%.2f\n", (savings_amount * 100) / (months_tracked * 100));
    }

    return 0;
}