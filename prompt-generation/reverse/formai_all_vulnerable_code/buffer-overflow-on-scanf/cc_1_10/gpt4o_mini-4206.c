//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker* tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker* tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense description: ");
    getchar(); // Clear input buffer
    fgets(newExpense.description, MAX_DESC_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("Expenses Recorded:\n");
    printf("%-25s %-10s\n", "Description", "Amount");
    for (int i = 0; i < tracker->count; i++) {
        printf("%-25s $%-9.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

void deleteExpense(ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    viewExpenses(tracker);
    int index;
    printf("Enter the index of the expense to delete (0 to %d): ", tracker->count - 1);
    scanf("%d", &index);

    if (index < 0 || index >= tracker->count) {
        printf("Invalid index. No expense deleted.\n");
        return;
    }

    for (int i = index; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("Expense deleted successfully!\n");
}

void totalExpenses(ExpenseTracker* tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void displayMenu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Total Expenses\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                deleteExpense(&tracker);
                break;
            case 4:
                totalExpenses(&tracker);
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