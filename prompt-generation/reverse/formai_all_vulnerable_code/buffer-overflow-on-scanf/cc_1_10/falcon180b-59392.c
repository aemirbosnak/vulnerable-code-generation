//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_BUDGET_ITEM_NAME_LENGTH 50

typedef struct {
    char name[MAX_BUDGET_ITEM_NAME_LENGTH];
    float amount;
} BudgetItem;

BudgetItem budgetItems[MAX_BUDGET_ITEMS];
int numBudgetItems;

void addBudgetItem() {
    printf("Enter budget item name: ");
    scanf("%s", budgetItems[numBudgetItems].name);
    printf("Enter budget item amount: ");
    scanf("%f", &budgetItems[numBudgetItems].amount);
    numBudgetItems++;
}

void removeBudgetItem() {
    printf("Enter budget item name to remove: ");
    scanf("%s", budgetItems[numBudgetItems-1].name);
    memmove(&budgetItems[0], &budgetItems[1], sizeof(BudgetItem)*(numBudgetItems-1));
    numBudgetItems--;
}

void editBudgetItem() {
    printf("Enter budget item name to edit: ");
    scanf("%s", budgetItems[numBudgetItems-1].name);
    printf("Enter new budget item name: ");
    scanf("%s", budgetItems[numBudgetItems-1].name);
    printf("Enter new budget item amount: ");
    scanf("%f", &budgetItems[numBudgetItems-1].amount);
}

void viewBudget() {
    printf("Budget:\n");
    for (int i = 0; i < numBudgetItems; i++) {
        printf("%s: $%.2f\n", budgetItems[i].name, budgetItems[i].amount);
    }
}

int main() {
    printf("Personal Finance Planner\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add budget item\n");
        printf("2. Remove budget item\n");
        printf("3. Edit budget item\n");
        printf("4. View budget\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);
        if (choice == 1) {
            addBudgetItem();
        } else if (choice == 2) {
            removeBudgetItem();
        } else if (choice == 3) {
            editBudgetItem();
        } else if (choice == 4) {
            viewBudget();
        } else if (choice == 5) {
            break;
        }
    }
    return 0;
}