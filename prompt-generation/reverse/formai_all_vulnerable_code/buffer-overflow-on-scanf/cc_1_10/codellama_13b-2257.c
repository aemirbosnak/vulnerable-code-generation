//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
/*
 * C Expense Tracker
 *
 * This program allows users to track their expenses.
 *
 * Usage:
 * 1. Add a new expense by typing "add" followed by the amount and description.
 * 2. View all expenses by typing "view".
 * 3. Remove an expense by typing "remove" followed by the index of the expense.
 *
 * Example:
 * add 100.50 "Grocery shopping"
 * view
 * remove 1
 */

#include <stdio.h>
#include <stdlib.h>

struct Expense {
    double amount;
    char* description;
};

void addExpense(struct Expense* expenses, int* numExpenses, double amount, char* description) {
    expenses[*numExpenses].amount = amount;
    expenses[*numExpenses].description = description;
    (*numExpenses)++;
}

void viewExpenses(struct Expense* expenses, int numExpenses) {
    for (int i = 0; i < numExpenses; i++) {
        printf("%.2f - %s\n", expenses[i].amount, expenses[i].description);
    }
}

void removeExpense(struct Expense* expenses, int* numExpenses, int index) {
    for (int i = index; i < *numExpenses; i++) {
        expenses[i] = expenses[i+1];
    }
    (*numExpenses)--;
}

int main() {
    struct Expense* expenses = (struct Expense*)malloc(100 * sizeof(struct Expense));
    int numExpenses = 0;
    char command[100];
    double amount;
    char description[100];

    while (1) {
        printf("Enter a command: ");
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            scanf("%lf %s", &amount, description);
            addExpense(expenses, &numExpenses, amount, description);
        } else if (strcmp(command, "view") == 0) {
            viewExpenses(expenses, numExpenses);
        } else if (strcmp(command, "remove") == 0) {
            int index;
            scanf("%d", &index);
            removeExpense(expenses, &numExpenses, index);
        } else {
            printf("Invalid command.\n");
        }
    }

    free(expenses);

    return 0;
}