//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];
} Expense;

Expense expenses[MAX_ITEMS];
int numExpenses = 0;

void addExpense() {
    if (numExpenses >= MAX_ITEMS) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);

    printf("Enter expense category: ");
    scanf("%s", expenses[numExpenses].category);

    printf("Enter expense amount: ");
    scanf("%s", expenses[numExpenses].amount);

    numExpenses++;
}

void displayExpenses() {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Category: %s\n", expenses[i].category);
        printf("Amount: $%s\n", expenses[i].amount);
        printf("\n");
    }
}

void calculateTotalExpenses() {
    float totalExpenses = 0.0;

    for (int i = 0; i < numExpenses; i++) {
        totalExpenses += atof(expenses[i].amount);
    }

    printf("Total expenses: $%.2f\n", totalExpenses);
}

int main() {
    int choice;

    do {
        printf("Personal Finance Planner\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Calculate total expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                displayExpenses();
                break;
            case 3:
                calculateTotalExpenses();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}