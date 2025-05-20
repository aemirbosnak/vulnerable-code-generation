//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
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
        printf("Cannot add more expenses. Maximum limit reached.\n");
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

void addCategory() {
    if (numCategories >= MAX_CATEGORIES) {
        printf("Cannot add more categories. Maximum limit reached.\n");
        return;
    }

    printf("Enter category name: ");
    scanf("%s", categories[numCategories]);

    numCategories++;
}

void viewExpenses() {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %d - %s\n", expenses[i].name, expenses[i].amount, categories[expenses[i].category]);
    }
}

void viewCategories() {
    printf("Categories:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    printf("Welcome to Expense Tracker!\n");

    addCategory();
    addCategory();
    addCategory();

    int choice;
    while (1) {
        printf("\n1. Add expense\n2. View expenses\n3. Add category\n4. View categories\n5. Exit\n");
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
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}