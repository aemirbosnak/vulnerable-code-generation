//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

// Function prototypes
void addExpense(ExpenseTracker *tracker);
void viewExpenses(const ExpenseTracker *tracker);
void displayMenu();
void clearBuffer(); // Helper function to clear input buffer

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;

    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        clearBuffer(); // Clear newline character from input buffer

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 3);

    return 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense description: ");
    fgets(newExpense.description, DESCRIPTION_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    clearBuffer(); // Clear newline character from input buffer

    tracker->expenses[tracker->count++] = newExpense;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpenses:\n");
    printf("%-25s %10s\n", "Description", "Amount");
    printf("--------------------------------------\n");

    for (int i = 0; i < tracker->count; i++) {
        printf("%-25s $%9.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }

    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("--------------------------------------\n");
    printf("Total Expenses: $%.2f\n\n", total);
}

void displayMenu() {
    printf("Expense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}