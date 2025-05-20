//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    Expense newExpense;
    printf("Enter description of the expense: ");
    scanf(" %[^\n]s", newExpense.description);
    printf("Enter amount of the expense: ");
    scanf("%f", &newExpense.amount);
    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void displayExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\nList of Expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0f;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void removeExpense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to remove.\n");
        return;
    }

    int index;
    printf("Enter the index of the expense to remove (1 to %d): ", tracker->count);
    scanf("%d", &index);

    if (index < 1 || index > tracker->count) {
        printf("Invalid index!\n");
        return;
    }

    index--; // Convert to zero-based index
    for (int i = index; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("Expense removed successfully!\n");
}

void clearExpenses(ExpenseTracker *tracker) {
    initTracker(tracker);
    printf("All expenses cleared successfully!\n");
}

void displayMenu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Remove Expense\n");
    printf("5. Clear All Expenses\n");
    printf("6. Exit\n");
}

int main() {
    ExpenseTracker tracker;
    initTracker(&tracker);
    int choice;

    do {
        displayMenu();
        printf("Select an option (1-6): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", calculateTotal(&tracker));
                break;
            case 4:
                removeExpense(&tracker);
                break;
            case 5:
                clearExpenses(&tracker);
                break;
            case 6:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}