//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 20
#define MAX_BUDGET_NAME_LENGTH 50
#define MAX_BUDGET_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_BUDGET_NAME_LENGTH];
    char amount[MAX_BUDGET_AMOUNT_LENGTH];
} budgetItem;

int main() {
    int numBudgetItems;
    budgetItem budget[MAX_BUDGET_ITEMS];
    char input[100];
    int i;

    // Get number of budget items
    printf("How many budget items do you have? ");
    scanf("%d", &numBudgetItems);

    // Get budget item names and amounts
    for (i = 0; i < numBudgetItems; i++) {
        printf("Enter name of budget item %d: ", i+1);
        scanf("%s", budget[i].name);
        printf("Enter amount of budget item %s: ", budget[i].name);
        scanf("%s", budget[i].amount);
    }

    // Calculate total income and expenses
    double totalIncome = 0;
    double totalExpenses = 0;
    for (i = 0; i < numBudgetItems; i++) {
        if (strcmp(budget[i].amount, "INCOME") == 0) {
            totalIncome += atof(budget[i].amount);
        } else if (strcmp(budget[i].amount, "EXPENSE") == 0) {
            totalExpenses += atof(budget[i].amount);
        }
    }

    // Print summary
    printf("\nSummary:\n");
    printf("Total income: $%.2f\n", totalIncome);
    printf("Total expenses: $%.2f\n", totalExpenses);
    printf("Net income: $%.2f\n", totalIncome - totalExpenses);

    return 0;
}