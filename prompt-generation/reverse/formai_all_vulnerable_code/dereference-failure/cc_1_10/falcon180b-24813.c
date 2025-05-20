//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    int category;
} Expense;

void addExpense(Expense *expenses, int numExpenses, char *name, float amount, int category) {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    strcpy(expenses[numExpenses].name, name);
    expenses[numExpenses].amount = amount;
    expenses[numExpenses].category = category;
    numExpenses++;
}

void displayExpenses(Expense *expenses, int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f (Category: %d)\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void addCategory(char *categories[], int numCategories, char *name) {
    if (numCategories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }
    strcpy(categories[numCategories], name);
    numCategories++;
}

void displayCategories(char *categories[], int numCategories) {
    printf("Categories:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char categories[MAX_CATEGORIES][50];
    int numCategories = 0;

    addCategory(categories, numCategories, "Food");
    addCategory(categories, numCategories, "Transportation");
    addCategory(categories, numCategories, "Entertainment");
    addCategory(categories, numCategories, "Shopping");

    addExpense(expenses, numExpenses, "Groceries", 100.50, 0);
    addExpense(expenses, numExpenses, "Gas", 50.00, 1);
    addExpense(expenses, numExpenses, "Movie Ticket", 12.00, 2);
    addExpense(expenses, numExpenses, "Clothing", 75.00, 3);

    displayExpenses(expenses, numExpenses);
    displayCategories(categories, numCategories);

    return 0;
}