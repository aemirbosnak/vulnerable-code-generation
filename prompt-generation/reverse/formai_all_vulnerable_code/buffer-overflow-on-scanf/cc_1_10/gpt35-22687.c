//FormAI DATASET v1.0 Category: Expense Tracker ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    float amount;
} Expense;

// Recursive function to add expenses
void addExpenses(Expense *expenses, int size) {
    printf("Enter expense name (enter 'a' to finish adding expenses): ");
    scanf("%s", expenses[size].name);

    if (strcmp(expenses[size].name, "a") == 0) {
        return;
    }

    printf("Enter expense amount: ");
    scanf("%f", &expenses[size].amount);

    addExpenses(expenses, size + 1); // recursive call to add more expenses
}

// Recursive function to display expenses
void displayExpenses(Expense *expenses, int size, float total) {
    if (size < 1) {
        printf("Total expenses: %.2f\n", total);
        return;
    }

    printf("%s: %.2f\n", expenses[size - 1].name, expenses[size - 1].amount);
    total += expenses[size - 1].amount;

    displayExpenses(expenses, size - 1, total); // recursive call to display previous expenses
}

int main() {
    int numExpenses;

    printf("How many expenses do you want to add? ");
    scanf("%d", &numExpenses);

    Expense *expenses = malloc(sizeof(Expense) * numExpenses);

    addExpenses(expenses, 0); // add expenses recursively

    displayExpenses(expenses, numExpenses, 0); // display expenses recursively

    free(expenses);

    return 0;
}