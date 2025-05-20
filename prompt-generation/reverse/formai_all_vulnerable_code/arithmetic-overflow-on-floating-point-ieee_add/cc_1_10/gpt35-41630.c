//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET 10000 // Maximum budget that can be allocated

void allocate_budget(float* income, float* expense, float* savings);

int main()
{
    float income, expense, savings;
    
    printf("Welcome to Personal Finance Planner!\n");
    printf("Please enter your income for this month: $ ");
    scanf("%f", &income);
    
    printf("\nPlease enter your expenses for this month: $ ");
    scanf("%f", &expense);
    
    allocate_budget(&income, &expense, &savings);
    
    printf("\nHere is a breakdown of your budget:\n");
    printf("Income: $ %.2f\n", income);
    printf("Expenses: $ %.2f\n", expense);
    printf("Savings: $ %.2f\n", savings);
    
    return 0;
}

/*
    A function that takes income and expense as input and allocates
    the budget according to a predefined formula.
*/
void allocate_budget(float* income, float* expense, float* savings)
{
    float housing = *income * 0.30;
    float utilities = *income * 0.05;
    float food = *income * 0.10;
    float transportation = *income * 0.10;
    float entertainment = *income * 0.10;
    float health = *income * 0.10;
    float other = *income * 0.25;
    
    if (housing + utilities + food + transportation + entertainment + health > *income)
    {
        printf("\nWarning! Your expenses exceed your income. Some adjustments may need to be made.\n");
    }
    else
    {
        *expense = housing + utilities + food + transportation + entertainment + health + other;
        *savings = *income - *expense;
    }
}