//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    int category;
} ExpenseItem;

typedef struct {
    char name[MAX_NAME_LENGTH];
    float total;
} Category;

ExpenseItem expenses[MAX_ITEMS];
Category categories[MAX_CATEGORIES];
int numExpenses = 0;
int numCategories = 0;

void addCategory() {
    if (numCategories == MAX_CATEGORIES) {
        printf("Error: Cannot add more categories.\n");
        return;
    }

    printf("Enter category name: ");
    scanf("%s", categories[numCategories].name);
    numCategories++;
}

void addExpense() {
    if (numExpenses == MAX_ITEMS) {
        printf("Error: Cannot add more expenses.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[numExpenses].amount);

    printf("Enter expense category (0-9): ");
    scanf("%d", &expenses[numExpenses].category);

    numExpenses++;
}

void displayCategories() {
    int i;
    float total = 0.0;

    printf("\nCategories:\n");
    for (i = 0; i < numCategories; i++) {
        printf("%s - Total: $%.2f\n", categories[i].name, categories[i].total);
        total += categories[i].total;
    }

    printf("\nTotal: $%.2f\n", total);
}

void displayExpenses() {
    int i;

    printf("\nExpenses:\n");
    for (i = 0; i < numExpenses; i++) {
        printf("%s - $%.2f (%d)\n", expenses[i].name, expenses[i].amount, expenses[i].category + 1);
    }
}

void calculateTotals() {
    int i;

    for (i = 0; i < numCategories; i++) {
        categories[i].total = 0.0;
    }

    for (i = 0; i < numExpenses; i++) {
        categories[expenses[i].category].total += expenses[i].amount;
    }
}

int main() {
    int choice;

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Add category\n");
        printf("2. Add expense\n");
        printf("3. Display categories\n");
        printf("4. Display expenses\n");
        printf("5. Calculate totals\n");
        printf("6. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCategory();
                break;
            case 2:
                addExpense();
                break;
            case 3:
                displayCategories();
                break;
            case 4:
                displayExpenses();
                break;
            case 5:
                calculateTotals();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}