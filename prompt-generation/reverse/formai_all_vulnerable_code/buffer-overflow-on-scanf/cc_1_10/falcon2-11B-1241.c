//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    double amount;
} Expense;

Expense expenses[10];
int numExpenses = 0;

void addExpense(void) {
    char name[50];
    double amount;

    printf("Enter expense name: ");
    scanf("%s", name);
    if (strlen(name) > 50) {
        printf("Expense name is too long!\n");
        return;
    }
    printf("Enter expense amount: ");
    scanf("%lf", &amount);
    if (amount < 0) {
        printf("Expense amount cannot be negative!\n");
        return;
    }

    Expense newExpense;
    strcpy(newExpense.name, name);
    newExpense.amount = amount;

    expenses[numExpenses++] = newExpense;

    printf("Expense added successfully!\n");
}

void displayExpenses(void) {
    int i;
    for (i = 0; i < numExpenses; i++) {
        printf("Expense %d:\n", i+1);
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %.2lf\n", expenses[i].amount);
    }
}

int main(void) {
    int choice;
    do {
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addExpense(); break;
            case 2: displayExpenses(); break;
            case 3: return 0;
        }
    } while (choice!= 3);

    return 0;
}