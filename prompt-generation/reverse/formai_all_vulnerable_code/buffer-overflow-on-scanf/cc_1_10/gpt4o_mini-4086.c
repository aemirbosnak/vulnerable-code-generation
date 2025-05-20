//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50
#define CATEGORY_LENGTH 20

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
    char category[CATEGORY_LENGTH];
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

// Function prototypes
void add_expense();
void view_expenses();
void remove_expense();
void export_expenses();
void display_menu();

int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume the newline character

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                remove_expense();
                break;
            case 4:
                export_expenses();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void display_menu() {
    printf("\n--- Expense Tracker ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Remove Expense\n");
    printf("4. Export Expenses to File\n");
    printf("5. Exit\n");
}

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Cannot add more expenses. Maximum limit reached.\n");
        return;
    }

    Expense new_expense;
    printf("Enter description: ");
    fgets(new_expense.description, DESCRIPTION_LENGTH, stdin);
    new_expense.description[strcspn(new_expense.description, "\n")] = 0; // Remove newline character

    printf("Enter amount: ");
    scanf("%f", &new_expense.amount);
    getchar(); // Consume the newline character

    printf("Enter category: ");
    fgets(new_expense.category, CATEGORY_LENGTH, stdin);
    new_expense.category[strcspn(new_expense.category, "\n")] = 0; // Remove newline character

    expenses[expense_count++] = new_expense;
    printf("Expense added successfully!\n");
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\n--- List of Expenses ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("Expense %d: %s | Amount: %.2f | Category: %s\n", 
               i + 1, expenses[i].description, expenses[i].amount, expenses[i].category);
    }
}

void remove_expense() {
    if (expense_count == 0) {
        printf("No expenses to remove.\n");
        return;
    }

    int index;
    printf("Enter the index of the expense to remove (1 to %d): ", expense_count);
    scanf("%d", &index);
    getchar(); // Consume the newline character

    if (index < 1 || index > expense_count) {
        printf("Invalid index. Please try again.\n");
        return;
    }

    // Shift expenses down
    for (int i = index - 1; i < expense_count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    
    expense_count--;
    printf("Expense removed successfully!\n");
}

void export_expenses() {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Failed to open file for writing.\n");
        return;
    }

    for (int i = 0; i < expense_count; i++) {
        fprintf(file, "Expense %d: %s | Amount: %.2f | Category: %s\n", 
                i + 1, expenses[i].description, expenses[i].amount, expenses[i].category);
    }

    fclose(file);
    printf("Expenses exported successfully to expenses.txt!\n");
}