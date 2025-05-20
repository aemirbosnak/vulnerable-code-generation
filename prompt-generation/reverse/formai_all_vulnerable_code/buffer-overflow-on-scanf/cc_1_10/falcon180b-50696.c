//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_BUDGET_NAME_LENGTH 50

typedef struct {
    char name[MAX_BUDGET_NAME_LENGTH];
    double amount;
} BudgetItem;

void addBudgetItem(BudgetItem *budget, int *itemCount) {
    printf("Enter budget item name: ");
    scanf("%s", budget[*itemCount].name);

    printf("Enter budget item amount: $");
    scanf("%lf", &budget[*itemCount].amount);

    (*itemCount)++;
}

void displayBudget(BudgetItem *budget, int itemCount) {
    printf("\nBudget:\n");

    for (int i = 0; i < itemCount; i++) {
        printf("%s: $%.2lf\n", budget[i].name, budget[i].amount);
    }
}

int main() {
    BudgetItem budget[MAX_BUDGET_ITEMS];
    int itemCount = 0;

    addBudgetItem(budget, &itemCount);

    while (itemCount < MAX_BUDGET_ITEMS) {
        printf("\nDo you want to add another budget item? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (tolower(choice) == 'y') {
            addBudgetItem(budget, &itemCount);
        } else {
            break;
        }
    }

    displayBudget(budget, itemCount);

    return 0;
}