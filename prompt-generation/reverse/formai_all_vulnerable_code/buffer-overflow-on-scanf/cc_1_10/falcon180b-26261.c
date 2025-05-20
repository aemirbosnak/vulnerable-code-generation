//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_BUDGET_NAME_LENGTH 50
#define MAX_BUDGET_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_BUDGET_NAME_LENGTH];
    char amount[MAX_BUDGET_AMOUNT_LENGTH];
} BudgetItem;

void addBudgetItem(BudgetItem *budget, int numItems, char *name, char *amount) {
    if (numItems >= MAX_BUDGET_ITEMS) {
        printf("Error: Maximum number of budget items reached.\n");
        return;
    }

    strcpy(budget[numItems].name, name);
    strcpy(budget[numItems].amount, amount);

    numItems++;
}

void displayBudget(BudgetItem *budget, int numItems) {
    printf("Budget:\n");

    for (int i = 0; i < numItems; i++) {
        printf("%s: %s\n", budget[i].name, budget[i].amount);
    }
}

void main() {
    srand(time(NULL));

    char budgetName[MAX_BUDGET_NAME_LENGTH];
    printf("Enter budget name: ");
    scanf("%s", budgetName);

    BudgetItem budget[MAX_BUDGET_ITEMS];
    int numItems = 0;

    addBudgetItem(budget, numItems, "Housing", "500.00");
    addBudgetItem(budget, numItems, "Transportation", "150.00");
    addBudgetItem(budget, numItems, "Food", "200.00");
    addBudgetItem(budget, numItems, "Entertainment", "100.00");

    displayBudget(budget, numItems);
}