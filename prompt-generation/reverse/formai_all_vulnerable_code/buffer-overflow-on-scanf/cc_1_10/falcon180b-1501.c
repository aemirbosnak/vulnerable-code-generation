//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int amount;
    int category;
} Expense;

Expense expenses[MAX_ITEMS];
char categories[MAX_CATEGORIES][50];
int numExpenses = 0;
int numCategories = 0;

void addExpense() {
    if (numExpenses >= MAX_ITEMS) {
        printf("Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);

    printf("Enter expense amount: ");
    scanf("%d", &expenses[numExpenses].amount);

    printf("Enter expense category (1-%d): ", numCategories);
    scanf("%d", &expenses[numExpenses].category);

    numExpenses++;
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

void viewExpenses() {
    if (numExpenses == 0) {
        printf("No expenses added yet.\n");
        return;
    }

    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - $%d - %s\n", expenses[i].name, expenses[i].amount, categories[expenses[i].category]);
    }
}

int main() {
    int choice;

    while (1) {
        printf("1. Add expense\n2. Add category\n3. View expenses\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addExpense();
            break;
        case 2:
            addCategory();
            break;
        case 3:
            viewExpenses();
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}