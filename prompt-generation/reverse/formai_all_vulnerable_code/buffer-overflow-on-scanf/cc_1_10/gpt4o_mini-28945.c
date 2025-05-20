//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int expense_count = 0;

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Expense limit reached, cannot add more expenses.\n");
        return;
    }
    Expense new_expense;
    printf("Enter expense description: ");
    getchar(); // clear newline
    fgets(new_expense.description, DESCRIPTION_LENGTH, stdin);
    new_expense.description[strcspn(new_expense.description, "\n")] = 0; // Remove newline
    printf("Enter amount: ");
    scanf("%f", &new_expense.amount);
    expenses[expense_count++] = new_expense;
    printf("Expense added successfully!\n");
}

void view_expenses() {
    if (expense_count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\n--- List of Expenses ---\n");
    for (int i = 0; i < expense_count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

void delete_expense() {
    if (expense_count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    int index;
    printf("Enter the index of the expense to delete (1-%d): ", expense_count);
    scanf("%d", &index);
    if (index < 1 || index > expense_count) {
        printf("Invalid index.\n");
        return;
    }
    expense_count--;
    for (int i = index - 1; i < expense_count; i++) {
        expenses[i] = expenses[i + 1];
    }
    printf("Expense deleted successfully!\n");
}

void total_expenses() {
    float total = 0.0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }
    printf("Total expenses: $%.2f\n", total);
}

void display_menu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Total Expenses\n");
    printf("5. Exit\n");
    printf("Select an option (1-5): ");
}

int main() {
    int choice;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                total_expenses();
                break;
            case 5:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please choose between 1 and 5.\n");
        }
    }
    return 0;
}