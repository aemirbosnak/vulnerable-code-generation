//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

// Structure to hold individual expense data
typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

// Structure to hold all expenses
typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

// Function prototypes
void addExpense(ExpenseTracker *tracker);
void viewExpenses(const ExpenseTracker *tracker);
void calculateTotal(const ExpenseTracker *tracker);
void displayMenu();
void clearInputBuffer();

int main() {
    ExpenseTracker tracker;
    tracker.count = 0; // Start with zero expenses
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                calculateTotal(&tracker);
                break;
            case 4:
                printf("Exiting the Expense Tracker. Keep your spending in check!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}

// Function to add an expense
void addExpense(ExpenseTracker *tracker) {
    if (tracker->count < MAX_EXPENSES) {
        printf("Enter description of expense: ");
        fgets(tracker->expenses[tracker->count].description, DESCRIPTION_LENGTH, stdin);
        strtok(tracker->expenses[tracker->count].description, "\n"); // Remove newline character

        printf("Enter amount: $");
        scanf("%f", &tracker->expenses[tracker->count].amount);
        clearInputBuffer();

        tracker->count++;
        printf("Expense added successfully! Keep tracking your budget!\n");
    } else {
        printf("Sorry, you cannot add more than %d expenses!\n", MAX_EXPENSES);
    }
}

// Function to view all expenses
void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet! Go ahead and add some!\n");
    } else {
        printf("\n--- Expenses Recorded ---\n");
        for (int i = 0; i < tracker->count; i++) {
            printf("Expense %d: %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
        }
        printf("-------------------------\n");
    }
}

// Function to calculate total expenses
void calculateTotal(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to calculate!\n");
        return;
    }
    float total = 0.0f;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\nKeep saving for that vacation!\n", total);
}

// Function to display menu options
void displayMenu() {
    printf("\n--- Welcome to the Energetic Expense Tracker! ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
}

// Function to clear input buffer
void clearInputBuffer() {
    while (getchar() != '\n');
}