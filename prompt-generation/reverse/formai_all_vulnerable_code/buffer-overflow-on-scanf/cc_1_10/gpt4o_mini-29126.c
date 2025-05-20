//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void add_expense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    Expense expense;
    printf("Enter expense description: ");
    getchar(); // Consume newline from previous input
    fgets(expense.description, MAX_DESCRIPTION_LENGTH, stdin);
    expense.description[strcspn(expense.description, "\n")] = 0; // Remove newline
    
    printf("Enter expense amount: ");
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
    printf("\nExpenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

void calculate_total(ExpenseTracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total expenses: $%.2f\n", total);
}

void delete_expense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    view_expenses(tracker);
    printf("Enter the expense number to delete: ");
    int index;
    scanf("%d", &index);
    
    if (index < 1 || index > tracker->count) {
        printf("Invalid expense number.\n");
        return;
    }

    for (int i = index - 1; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("Expense deleted successfully!\n");
}

void display_menu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Exit\n");
}

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;

    while (1) {
        display_menu();
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
                printf("Exiting Expense Tracker. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}