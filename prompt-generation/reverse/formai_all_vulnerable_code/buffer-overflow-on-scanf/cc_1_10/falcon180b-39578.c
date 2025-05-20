//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    double amount;
} expense;

void addExpense(expense expenses[], int *numExpenses) {
    printf("Enter expense category: ");
    scanf("%s", expenses[*numExpenses].category);

    printf("Enter expense amount: ");
    scanf("%lf", &expenses[*numExpenses].amount);

    (*numExpenses)++;
}

void displayExpenses(expense expenses[], int numExpenses) {
    printf("\nExpenses:\n");

    for (int i = 0; i < numExpenses; i++) {
        printf("%s - $%.2lf\n", expenses[i].category, expenses[i].amount);
    }
}

void calculateTotalExpenses(expense expenses[], int numExpenses) {
    double totalExpenses = 0;

    for (int i = 0; i < numExpenses; i++) {
        totalExpenses += expenses[i].amount;
    }

    printf("\nTotal expenses: $%.2lf\n", totalExpenses);
}

int main() {
    expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    while (numExpenses < MAX_EXPENSES) {
        printf("Enter expenses (type 'done' to finish):\n");
        addExpense(expenses, &numExpenses);

        char input[50];
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }
    }

    displayExpenses(expenses, numExpenses);
    calculateTotalExpenses(expenses, numExpenses);

    return 0;
}