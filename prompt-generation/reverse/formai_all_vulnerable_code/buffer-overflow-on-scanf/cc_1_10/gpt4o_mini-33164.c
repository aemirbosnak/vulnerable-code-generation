//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define TITLE_LENGTH 50
#define DESC_LENGTH 100

typedef struct {
    char title[TITLE_LENGTH];
    char description[DESC_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached!\n");
        return;
    }

    Expense newExpense;
    printf("Enter title: ");
    fgets(newExpense.title, TITLE_LENGTH, stdin);
    strtok(newExpense.title, "\n"); // Remove the newline

    printf("Enter description: ");
    fgets(newExpense.description, DESC_LENGTH, stdin);
    strtok(newExpense.description, "\n"); // Remove the newline

    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);
    getchar(); // Clear newline character from buffer

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Expense %d:\n", i + 1);
        printf("  Title: %s\n", tracker->expenses[i].title);
        printf("  Description: %s\n", tracker->expenses[i].description);
        printf("  Amount: %.2f\n", tracker->expenses[i].amount);
    }
    printf("\n");
}

void viewTotalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0f;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total expenses: %.2f\n", total);
}

void deleteExpense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int expenseNum;
    printf("Enter the expense number to delete (1 - %d): ", tracker->count);
    scanf("%d", &expenseNum);
    getchar(); // Clear newline character from buffer

    if (expenseNum < 1 || expenseNum > tracker->count) {
        printf("Invalid expense number!\n");
        return;
    }

    // Shift expenses down one position
    for (int i = expenseNum - 1; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("Expense deleted successfully!\n");
}

void displayMenu() {
    printf("Expense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. View Total Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;

    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);
        getchar(); // Clear newline character from buffer

        switch (option) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                viewTotalExpenses(&tracker);
                break;
            case 4:
                deleteExpense(&tracker);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
        printf("\n");
    }

    return 0;
}