//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 20
#define MAX_EXPENSES 50
#define MAX_NAME_LENGTH 50
#define MAX_EXPENSE_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
    float balance;
} Category;

typedef struct {
    char name[MAX_EXPENSE_LENGTH];
    Category* category;
    float amount;
} Expense;

Category categories[MAX_CATEGORIES];
int numCategories = 0;

Expense expenses[MAX_EXPENSES];
int numExpenses = 0;

void addCategory() {
    printf("Enter category name: ");
    scanf("%s", categories[numCategories].name);
    categories[numCategories].id = numCategories + 1;
    categories[numCategories].balance = 0.0;
    numCategories++;
}

void deleteCategory() {
    int id;
    printf("Enter category ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < numCategories; i++) {
        if (categories[i].id == id) {
            for (int j = i; j < numCategories - 1; j++) {
                categories[j] = categories[j + 1];
            }
            numCategories--;
            break;
        }
    }
}

void addExpense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[numExpenses].name);
    printf("Enter category ID: ");
    scanf("%d", &expenses[numExpenses].category->id);
    expenses[numExpenses].category = &categories[expenses[numExpenses].category->id - 1];
    printf("Enter expense amount: ");
    scanf("%f", &expenses[numExpenses].amount);
    numExpenses++;
}

void deleteExpense() {
    printf("Enter expense ID to delete: ");
    scanf("%d", &expenses[numExpenses - 1].category->id);
    for (int i = 0; i < numExpenses - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    numExpenses--;
}

void viewCategories() {
    printf("\n");
    for (int i = 0; i < numCategories; i++) {
        printf("%d. %s ($%.2f)\n", categories[i].id, categories[i].name, categories[i].balance);
    }
}

void viewExpenses() {
    printf("\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - $%.2f (%s)\n", expenses[i].name, expenses[i].amount, expenses[i].category->name);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter your name: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    printf("\nHello, %s! Let's get started.\n", name);

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add category\n");
        printf("2. Delete category\n");
        printf("3. Add expense\n");
        printf("4. Delete expense\n");
        printf("5. View categories\n");
        printf("6. View expenses\n");
        printf("7. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addCategory();
            break;
        case 2:
            deleteCategory();
            break;
        case 3:
            addExpense();
            break;
        case 4:
            deleteExpense();
            break;
        case 5:
            viewCategories();
            break;
        case 6:
            viewExpenses();
            break;
        case 7:
            printf("\nThank you for using the Expense Tracker, %s!\n", name);
            return 0;
        default:
            printf("\nInvalid choice. Please try again.\n");
        }
    }

    return 0;
}