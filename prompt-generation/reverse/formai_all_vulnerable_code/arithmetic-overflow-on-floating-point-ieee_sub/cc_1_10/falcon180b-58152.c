//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} BudgetItem;

int main(void) {
    int numItems;
    BudgetItem budget[MAX_BUDGET_ITEMS];
    float totalIncome = 0.0;
    float totalExpenses = 0.0;
    float totalSavings = 0.0;
    float monthlySavings = 0.0;
    int i;

    // Get user input for number of budget items
    printf("Enter the number of budget items: ");
    scanf("%d", &numItems);

    // Get user input for budget items
    printf("Enter the budget items (name and amount):\n");
    for (i = 0; i < numItems; i++) {
        scanf("%s %f", budget[i].name, &budget[i].amount);
    }

    // Calculate total income
    printf("Enter your total income: ");
    scanf("%f", &totalIncome);

    // Calculate total expenses
    printf("Enter your total expenses: ");
    scanf("%f", &totalExpenses);

    // Calculate total savings
    totalSavings = totalIncome - totalExpenses;

    // Calculate monthly savings
    monthlySavings = totalSavings / 12;

    // Print summary
    printf("\nSummary:\n");
    printf("Total income: $%.2f\n", totalIncome);
    printf("Total expenses: $%.2f\n", totalExpenses);
    printf("Total savings: $%.2f\n", totalSavings);
    printf("Monthly savings: $%.2f\n", monthlySavings);

    // Print budget items
    printf("\nBudget items:\n");
    for (i = 0; i < numItems; i++) {
        printf("%s: $%.2f\n", budget[i].name, budget[i].amount);
    }

    return 0;
}