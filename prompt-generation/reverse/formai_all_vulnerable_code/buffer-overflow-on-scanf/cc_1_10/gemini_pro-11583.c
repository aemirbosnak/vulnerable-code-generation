//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    float income;
    float expenses;
    float savings;
} budget_item;

int main() {
    // Create an array of budget items
    budget_item budget[10];

    // Get user input for each budget item
    for (int i = 0; i < 10; i++) {
        printf("Enter name of budget item %d: ", i + 1);
        scanf("%s", budget[i].name);
        printf("Enter income for budget item %d: ", i + 1);
        scanf("%f", &budget[i].income);
        printf("Enter expenses for budget item %d: ", i + 1);
        scanf("%f", &budget[i].expenses);
        printf("Enter savings for budget item %d: ", i + 1);
        scanf("%f", &budget[i].savings);
    }

    // Calculate the total income, expenses, and savings
    float total_income = 0;
    float total_expenses = 0;
    float total_savings = 0;
    for (int i = 0; i < 10; i++) {
        total_income += budget[i].income;
        total_expenses += budget[i].expenses;
        total_savings += budget[i].savings;
    }

    // Print the total income, expenses, and savings
    printf("Total income: %.2f\n", total_income);
    printf("Total expenses: %.2f\n", total_expenses);
    printf("Total savings: %.2f\n", total_savings);

    // Calculate the net income
    float net_income = total_income - total_expenses;

    // Print the net income
    printf("Net income: %.2f\n", net_income);

    return 0;
}