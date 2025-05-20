//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 50

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

// Function prototypes
void addExpense(ExpenseTracker *tracker);
void viewExpenses(const ExpenseTracker *tracker);
void deleteExpense(ExpenseTracker *tracker);
void displayMenu();
void clearInputBuffer();

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();  // Clear the input buffer before taking string inputs

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
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to add an expense
void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    Expense newExpense;
    printf("Enter the description of the expense: ");
    fgets(newExpense.description, MAX_DESCRIPTION, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    printf("Enter the amount of the expense: ");
    scanf("%f", &newExpense.amount);
    clearInputBuffer(); // Clear the input buffer for next input

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

// Function to view all expenses
void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }
    printf("\nList of Expenses:\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("------------------------------------------------\n");
}

// Function to delete an expense by index
void deleteExpense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    int index;
    viewExpenses(tracker);
    printf("Enter the expense number to delete: ");
    scanf("%d", &index);
    clearInputBuffer(); // Clear the input buffer

    if (index < 1 || index > tracker->count) {
        printf("Invalid expense number!\n");
        return;
    }

    // Shift expenses to the left to remove the selected expense
    for (int i = index - 1; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("Expense deleted successfully!\n");
}

// Function to display menu options
void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
}

// Function to clear the input buffer
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}