//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LENGTH 30
#define DESC_LENGTH 50

typedef struct {
    char category[CATEGORY_LENGTH];
    char description[DESC_LENGTH];
    float amount;     
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Maximum expense record reached!\n");
        return;
    }

    printf("Enter Category: ");
    scanf(" %29[^\n]", expenses[expense_count].category);
    printf("Enter Description: ");
    scanf(" %49[^\n]", expenses[expense_count].description);
    printf("Enter Amount: ");
    scanf("%f", &expenses[expense_count].amount);
    
    expense_count++;
    printf("Expense added successfully!\n");
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("ID: %d\n", i + 1);
        printf("Category: %s\n", expenses[i].category);
        printf("Description: %s\n", expenses[i].description);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("--------------------\n");
    }
}

void total_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded to calculate total.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void edit_expense() {
    int id;
    printf("Enter the Expense ID you want to edit: ");
    scanf("%d", &id);
    
    if (id < 1 || id > expense_count) {
        printf("Invalid ID!\n");
        return;
    }

    id--;  // Convert to zero-based index
    printf("Editing Expense ID %d:\n", id + 1);

    printf("Enter new Category (current: %s): ", expenses[id].category);
    scanf(" %29[^\n]", expenses[id].category);
    printf("Enter new Description (current: %s): ", expenses[id].description);
    scanf(" %49[^\n]", expenses[id].description);
    printf("Enter new Amount (current: %.2f): ", expenses[id].amount);
    scanf("%f", &expenses[id].amount);

    printf("Expense updated successfully!\n");
}

void delete_expense() {
    int id;
    printf("Enter the Expense ID you want to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > expense_count) {
        printf("Invalid ID!\n");
        return;
    }

    id--;  // Convert to zero-based index
    for (int i = id; i < expense_count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    expense_count--;

    printf("Expense ID %d deleted successfully!\n", id + 1);
}

int main() {
    int choice;

    do {
        printf("\n--- Expense Tracker Menu ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Edit Expense\n");
        printf("5. Delete Expense\n");
        printf("6. Exit\n");
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
                edit_expense();
                break;
            case 5:
                delete_expense();
                break;
            case 6:
                printf("Exiting Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 6);

    return 0;
}