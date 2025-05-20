//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker);
void viewExpenses(const ExpenseTracker *tracker);
void calculateTotalExpenses(const ExpenseTracker *tracker);
void clearExpenses(ExpenseTracker *tracker);

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;

    int choice;

    while (1) {
        printf("\n=== Personal Finance Planner ===\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Clear All Expenses\n");
        printf("5. Exit\n");
        printf("===============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                calculateTotalExpenses(&tracker);
                break;
            case 4:
                clearExpenses(&tracker);
                break;
            case 5:
                printf("Exiting the planner. Have a great day!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense tracker is full. Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense name: ");
    scanf("%s", newExpense.name);
    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n=== Recorded Expenses ===\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, tracker->expenses[i].name, tracker->expenses[i].amount);
    }
    printf("=========================\n");
}

void calculateTotalExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    float total = 0.0f;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }

    printf("Total Expenses: $%.2f\n", total);
}

void clearExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses cleared successfully!\n");
}