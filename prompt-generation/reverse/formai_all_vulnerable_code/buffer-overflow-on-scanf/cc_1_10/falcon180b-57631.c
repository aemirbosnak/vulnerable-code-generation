//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 50
#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
    char category[MAX_NAME_LENGTH];
} Expense;

void addExpense(Expense *expenses, int *numExpenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses].name);
    printf("Enter expense amount: ");
    scanf("%s", expenses[*numExpenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[*numExpenses].category);
    (*numExpenses)++;
}

void displayExpenses(Expense *expenses, int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %s - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void displaySummary(Expense *expenses, int numExpenses) {
    int totalExpenses = 0;
    for (int i = 0; i < numExpenses; i++) {
        totalExpenses += atoi(expenses[i].amount);
    }
    printf("\nTotal Expenses: $%d\n", totalExpenses);
}

int main() {
    int numExpenses = 0;
    Expense expenses[MAX_ITEMS];

    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);

    displayExpenses(expenses, numExpenses);
    displaySummary(expenses, numExpenses);

    return 0;
}