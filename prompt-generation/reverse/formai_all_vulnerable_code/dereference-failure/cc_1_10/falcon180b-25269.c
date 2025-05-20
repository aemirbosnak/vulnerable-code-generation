//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int amount;
    char category[20];
} Expense;

void addExpense(Expense expenses[], int numExpenses, char category[]) {
    if (numExpenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }
    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);
    printf("Enter expense amount: ");
    scanf("%d", &expenses[numExpenses].amount);
    strcpy(expenses[numExpenses].category, category);
    numExpenses++;
}

void displayExpenses(Expense expenses[], int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount/100, expenses[i].category);
    }
}

void addCategory(char categories[], int numCategories) {
    if (numCategories >= MAX_CATEGORIES) {
        printf("Maximum number of categories reached.\n");
        return;
    }
    printf("Enter category name: ");
    scanf("%s", categories[numCategories]);
    numCategories++;
}

void displayCategories(char categories[], int numCategories) {
    printf("\nCategories:\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    char categories[MAX_CATEGORIES][20];
    int numCategories = 0;

    printf("Welcome to the Expense Tracker!\n");
    addCategory(categories, numCategories);
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. Add category\n");
        printf("3. Display expenses\n");
        printf("4. Display categories\n");
        printf("5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense(expenses, numExpenses, categories[numCategories-1]);
                break;
            case 2:
                addCategory(categories, numCategories);
                break;
            case 3:
                displayExpenses(expenses, numExpenses);
                break;
            case 4:
                displayCategories(categories, numCategories);
                break;
            case 5:
                printf("Thank you for using the Expense Tracker.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}