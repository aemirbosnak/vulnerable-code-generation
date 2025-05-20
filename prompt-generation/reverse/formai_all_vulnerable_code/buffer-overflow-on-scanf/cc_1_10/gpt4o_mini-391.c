//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void add_expense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Cannot add more expenses, limit reached.\n");
        return;
    }

    Expense expense;
    printf("Enter the description of expense: ");
    scanf(" %[^\n]", expense.description);
    printf("Enter the amount of expense: ");
    scanf("%f", &expense.amount);

    tracker->expenses[tracker->count] = expense;
    tracker->count++;

    printf("Expense added successfully!\n");
}

void view_expenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpense Report:\n");
    printf("--------------------------------------------------\n");
    printf("%-30s | %-10s\n", "Description", "Amount");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%-30s | $%-9.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("--------------------------------------------------\n");
}

void calculate_total(ExpenseTracker *tracker) {
    float total = 0.0;
    
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }

    printf("Total Expenses: $%.2f\n", total);
}

void delete_expense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete. Your list is empty.\n");
        return;
    }

    printf("Enter the index of expense to delete (1 to %d): ", tracker->count);
    int index;
    scanf("%d", &index);
    index--; // Adjust for 0-based index

    if (index < 0 || index >= tracker->count) {
        printf("Invalid index.\n");
        return;
    }

    for (int i = index; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }

    tracker->count--;
    printf("Expense deleted successfully!\n");
}

void clear_expenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses have been cleared!\n");
}

void show_menu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Clear All Expenses\n");
    printf("6. Exit\n");
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;

    int choice;

    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(&tracker);
                break;
            case 2:
                view_expenses(&tracker);
                break;
            case 3:
                calculate_total(&tracker);
                break;
            case 4:
                delete_expense(&tracker);
                break;
            case 5:
                clear_expenses(&tracker);
                break;
            case 6:
                printf("Exiting Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}