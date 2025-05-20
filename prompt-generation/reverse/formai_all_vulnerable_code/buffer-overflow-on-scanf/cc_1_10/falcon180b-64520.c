//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 10
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} BudgetItem;

void addBudgetItem(BudgetItem *budget, int numItems) {
    if (numItems >= MAX_BUDGET_ITEMS) {
        printf("Error: Maximum budget items reached.\n");
        return;
    }
    printf("Enter budget item name: ");
    scanf("%s", budget[numItems].name);
    printf("Enter budget item amount: ");
    scanf("%s", budget[numItems].amount);
    numItems++;
}

void displayBudget(BudgetItem *budget, int numItems) {
    printf("\nBudget:\n");
    for (int i = 0; i < numItems; i++) {
        printf("%s - %s\n", budget[i].name, budget[i].amount);
    }
}

void main() {
    BudgetItem budget[MAX_BUDGET_ITEMS];
    int numItems = 0;
    char choice;
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add budget item\n");
        printf("2. Display budget\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);
        switch (choice) {
            case '1':
                if (numItems == MAX_BUDGET_ITEMS) {
                    printf("Error: Maximum budget items reached.\n");
                } else {
                    addBudgetItem(budget, numItems);
                }
                break;
            case '2':
                displayBudget(budget, numItems);
                break;
            case '3':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice!= '3');
}