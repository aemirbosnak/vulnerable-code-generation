//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

typedef struct {
    char name[50];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void addExpense() {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);
    printf("Enter expense amount: $");
    scanf("%f", &expenses[numExpenses].amount);
    numExpenses++;
}

void displayExpenses() {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void calculateTotalExpenses() {
    float totalExpenses = 0.0;
    for (int i = 0; i < numExpenses; i++) {
        totalExpenses += expenses[i].amount;
    }
    printf("Total expenses: $%.2f\n", totalExpenses);
}

void deleteExpense() {
    if (numExpenses == 0) {
        printf("Error: No expenses to delete.\n");
        return;
    }
    printf("Enter expense name to delete: ");
    scanf("%s", expenses[numExpenses - 1].name);
    numExpenses--;
    for (int i = 0; i < numExpenses; i++) {
        if (i < numExpenses - 1) {
            strcpy(expenses[i].name, expenses[i + 1].name);
            expenses[i].amount = expenses[i + 1].amount;
        }
    }
}

int main() {
    printf("Expense Tracker\n");
    while (1) {
        printf("1. Add expense\n2. Display expenses\n3. Calculate total expenses\n4. Delete expense\n5. Exit\n");
        int choice;
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
                deleteExpense();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}