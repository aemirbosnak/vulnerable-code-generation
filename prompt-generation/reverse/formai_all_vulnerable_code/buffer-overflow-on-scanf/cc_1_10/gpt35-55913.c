//FormAI DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

typedef struct Expense {
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
    char category[MAX_CATEGORY_LENGTH];
} Expense;

int numExpenses = 0;

void displayMenu();
void addExpense();
void viewExpenses();
void viewExpensesByCategory();
void deleteExpense();
int validateDouble(char *str);

Expense expenses[MAX_EXPENSES];

int main() {
    int choice = 0;

    printf("================================\n");
    printf(" Welcome to Retro Expense Tracker\n");
    printf("================================\n\n");

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                viewExpensesByCategory();
                break;
            case 4:
                deleteExpense();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("Please select an option:\n");
    printf("1. Add Expense\n");
    printf("2. View All Expenses\n");
    printf("3. View Expenses by Category\n");
    printf("4. Delete Expense\n");
    printf("5. Quit\n\n");
    printf("Choice: ");
}

void addExpense() {
    printf("\n");
    printf("=== Add New Expense ===\n");

    if (numExpenses == MAX_EXPENSES) {
        printf("Sorry, maximum number of expenses reached.\n");
        return;
    }

    Expense e;
    printf("Enter Description: ");
    scanf("%s", e.description);
    printf("Enter Amount: $");
    char amountStr[10];
    scanf("%s", amountStr);
    if (!validateDouble(amountStr)) {
        printf("Invalid amount format. Please try again.\n");
        return;
    }
    e.amount = atof(amountStr);
    printf("Enter Category: ");
    scanf("%s", e.category);

    expenses[numExpenses++] = e;

    printf("Expense added successfully!\n");
}

void viewExpenses() {
    printf("\n");
    printf("=== All Expenses ===\n");

    if (numExpenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    for (int i = 0; i < numExpenses; i++) {
        printf("Description: %s, Amount: $%.2f, Category: %s\n", expenses[i].description, expenses[i].amount, expenses[i].category);
    }
}

void viewExpensesByCategory() {
    printf("\n");
    printf("=== Expenses by Category ===\n");

    if (numExpenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    char category[MAX_CATEGORY_LENGTH];
    printf("Enter Category: ");
    scanf("%s", category);

    int count = 0;
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("Description: %s, Amount: $%.2f\n", expenses[i].description, expenses[i].amount);
            count++;
        }
    }

    if (count == 0) {
        printf("No expenses found in the %s category.\n", category);
    }
}

void deleteExpense() {
    printf("\n");
    printf("=== Delete Expense ===\n");

    if (numExpenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    char description[MAX_DESCRIPTION_LENGTH];
    printf("Enter Description: ");
    scanf("%s", description);

    int index = -1;
    for (int i = 0; i < numExpenses; i++) {
        if (strcmp(expenses[i].description, description) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Expense with description '%s' not found.\n", description);
        return;
    }

    for (int i = index; i < numExpenses - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    numExpenses--;
    printf("Expense with description '%s' deleted successfully!\n", description);
}

int validateDouble(char *str) {
    int decimals = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (isdigit(str[i])) {
            continue;
        } else if (str[i] == '.' && decimals == 0) {
            decimals++;
        } else {
            return 0;
        }
    }
    return 1;
}