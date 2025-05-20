//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LENGTH 20
#define DESCRIPTION_LENGTH 50

typedef struct {
    char category[CATEGORY_LENGTH];
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense();
void view_expenses();
void total_expenses();
void display_menu();

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                total_expenses();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n=== Expense Tracker ===\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Exit\n");
}

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Expense e;
    printf("Enter category: ");
    scanf("%s", e.category);
    printf("Enter description: ");
    scanf(" %[^\n]", e.description);  // Allows for space in description
    printf("Enter amount: ");
    scanf("%f", &e.amount);

    expenses[expense_count] = e;
    expense_count++;
    printf("Expense added successfully!\n");
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n=== Recorded Expenses ===\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Expense %d:\n", i + 1);
        printf("Category: %s\n", expenses[i].category);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: %.2f\n", expenses[i].amount);
    }
}

void total_expenses() {
    if (expense_count == 0) {
        printf("No expenses to calculate total.\n");
        return;
    }

    float total = 0.0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }

    printf("Total expenses: %.2f\n", total);
}