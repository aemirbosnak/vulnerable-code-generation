//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_BUDGET_NAME_LENGTH 50
#define MAX_BUDGET_CATEGORY_LENGTH 50
#define MAX_BUDGET_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_BUDGET_NAME_LENGTH];
    char category[MAX_BUDGET_CATEGORY_LENGTH];
    char amount[MAX_BUDGET_AMOUNT_LENGTH];
} BudgetItem;

int numBudgetItems = 0;
BudgetItem budgetItems[MAX_BUDGET_ITEMS];

void addBudgetItem() {
    if (numBudgetItems >= MAX_BUDGET_ITEMS) {
        printf("Error: Maximum number of budget items reached.\n");
        return;
    }

    printf("Enter name of budget item: ");
    scanf("%s", budgetItems[numBudgetItems].name);

    printf("Enter category of budget item: ");
    scanf("%s", budgetItems[numBudgetItems].category);

    printf("Enter amount of budget item: ");
    scanf("%s", budgetItems[numBudgetItems].amount);

    numBudgetItems++;
}

void printBudget() {
    printf("\nBudget:\n");
    printf("--------------------\n");
    printf("Name\tCategory\tAmount\n");

    for (int i = 0; i < numBudgetItems; i++) {
        printf("%s\t%s\t%s\n", budgetItems[i].name, budgetItems[i].category, budgetItems[i].amount);
    }
}

void calculateTotal() {
    double total = 0.0;

    for (int i = 0; i < numBudgetItems; i++) {
        total += atof(budgetItems[i].amount);
    }

    printf("\nTotal: $%.2f\n", total);
}

void main() {
    printf("Welcome to the Personal Finance Planner!\n");

    int choice;

    do {
        printf("\nChoose an option:\n");
        printf("1. Add budget item\n");
        printf("2. Print budget\n");
        printf("3. Calculate total\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBudgetItem();
                break;
            case 2:
                printBudget();
                break;
            case 3:
                calculateTotal();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice!= 4);
}