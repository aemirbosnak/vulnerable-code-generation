//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];
} Expense;

void addExpense(Expense expenses[], int numExpenses, char* name, float amount, char* category) {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Error: Cannot add more expenses. Maximum limit reached.\n");
        return;
    }

    strncpy(expenses[numExpenses].name, name, MAX_NAME_LENGTH);
    expenses[numExpenses].amount = amount;
    strncpy(expenses[numExpenses].category, category, MAX_NAME_LENGTH);

    numExpenses++;
}

void printExpenses(Expense expenses[], int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s\nAmount: $%.2f\nCategory: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];

    while (1) {
        printf("Enter name of expense: ");
        scanf("%s", name);

        printf("Enter amount of expense: $");
        scanf("%f", &amount);

        printf("Enter category of expense: ");
        scanf("%s", category);

        addExpense(expenses, numExpenses, name, amount, category);

        printf("Do you want to add another expense? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    printf("Total expenses: %d\n", numExpenses);
    printExpenses(expenses, numExpenses);

    return 0;
}