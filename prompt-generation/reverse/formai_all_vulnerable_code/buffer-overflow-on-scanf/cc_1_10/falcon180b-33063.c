//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int category;
} Expense;

void addExpense(Expense expenses[], int numExpenses, char name[], float amount, int category) {
    if (numExpenses == MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    strcpy(expenses[numExpenses].name, name);
    expenses[numExpenses].amount = amount;
    expenses[numExpenses].category = category;
    numExpenses++;
}

void displayExpenses(Expense expenses[], int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - $%.2f - Category %d\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char name[50];
    float amount;
    int category;

    printf("Welcome to the expense tracker!\n");
    printf("Enter your name: ");
    scanf("%s", name);

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Exit\n");
        scanf("%d", &category);

        switch (category) {
        case 1:
            printf("Enter expense name: ");
            scanf("%s", name);
            printf("Enter expense amount: $");
            scanf("%f", &amount);
            addExpense(expenses, numExpenses, name, amount, category);
            break;
        case 2:
            displayExpenses(expenses, numExpenses);
            break;
        case 3:
            printf("Goodbye, %s!\n", name);
            return 0;
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}