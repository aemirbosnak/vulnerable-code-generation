//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 20

typedef struct {
    char name[50];
    int amount;
    int category;
} Expense;

Expense expenses[MAX_EXPENSES];
char categories[MAX_CATEGORIES][50];
int numExpenses = 0;
int numCategories = 0;

void addExpense() {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);

    printf("Enter expense amount: ");
    scanf("%d", &expenses[numExpenses].amount);

    printf("Enter expense category (0-19): ");
    scanf("%d", &expenses[numExpenses].category);

    numExpenses++;
}

void viewExpenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%d. %s: $%d (Category: %d)\n", i+1, expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void addCategory() {
    if (numCategories >= MAX_CATEGORIES) {
        printf("Maximum number of categories reached.\n");
        return;
    }

    printf("Enter category name: ");
    scanf("%s", categories[numCategories]);

    numCategories++;
}

void viewCategories() {
    printf("\nCategories:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%d. %s\n", i+1, categories[i]);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Add category\n");
        printf("4. View categories\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                addCategory();
                break;
            case 4:
                viewCategories();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}