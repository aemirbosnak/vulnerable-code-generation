//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    
    Expense newExpense;

    printf("Enter expense name: ");
    scanf("%s", newExpense.name);
    
    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Expense #%d:\n", i + 1);
        printf("Name: %s\n", tracker->expenses[i].name);
        printf("Amount: %.2f\n", tracker->expenses[i].amount);
        printf("Date: %s\n", tracker->expenses[i].date);
        printf("-----------------------------------------\n");
    }
}

void deleteExpense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    viewExpenses(tracker);
    int index;
    printf("Enter the expense number to delete: ");
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

void displayMenu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;
    int choice;

    do {
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
                printf("Exiting. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 4);

    return 0;
}