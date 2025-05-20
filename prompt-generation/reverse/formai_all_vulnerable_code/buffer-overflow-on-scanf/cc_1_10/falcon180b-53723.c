//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
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

void addExpense(Expense* expenses, int numExpenses, char* name, float amount, int category) {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Cannot add more expenses.\n");
        return;
    }

    strcpy(expenses[numExpenses].name, name);
    expenses[numExpenses].amount = amount;
    expenses[numExpenses].category = category;

    numExpenses++;
}

void displayExpenses(Expense* expenses, int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f (Category %d)\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void displayCategories(char* categories[], int numCategories) {
    printf("Categories:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    char categories[MAX_CATEGORIES][50];
    int numExpenses = 0;
    int numCategories = 0;

    printf("Welcome to the Expense Tracker!\n");

    // Add categories
    while (numCategories < MAX_CATEGORIES) {
        printf("Enter a category (max 50 characters): ");
        scanf("%s", categories[numCategories]);
        numCategories++;
    }

    // Add expenses
    while (1) {
        printf("Enter an expense name (max 50 characters) or type 'quit' to exit: ");
        scanf("%s", expenses[numExpenses].name);

        if (strcmp(expenses[numExpenses].name, "quit") == 0) {
            break;
        }

        printf("Enter the amount (in dollars): $");
        scanf("%f", &expenses[numExpenses].amount);

        int category;
        printf("Enter the category (0-%d): ", numCategories - 1);
        scanf("%d", &category);

        addExpense(expenses, numExpenses, expenses[numExpenses].name, expenses[numExpenses].amount, category);
        numExpenses++;
    }

    displayCategories(categories, numCategories);
    displayExpenses(expenses, numExpenses);

    return 0;
}