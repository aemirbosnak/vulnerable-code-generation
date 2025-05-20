//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

// Function to initialize the Expense Tracker.
void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

// Function to add an expense.
void addExpense(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->count < MAX_EXPENSES) {
        snprintf(tracker->expenses[tracker->count].description, 50, "%s", description);
        tracker->expenses[tracker->count].amount = amount;
        tracker->count++;
    } else {
        printf("Error: Maximum expense limit reached.\n");
    }
}

// Function to view all expenses.
void viewExpenses(const ExpenseTracker *tracker) {
    printf("\n=== Expense Report ===\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Expense %d: %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("=======================\n");
}

// Function to calculate total expenses.
float totalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

// Function to find the highest expense category.
void highestExpenseCategory(const ExpenseTracker *tracker) {
    float highestAmount = 0;
    char highestDescription[50];

    for (int i = 0; i < tracker->count; i++) {
        if (tracker->expenses[i].amount > highestAmount) {
            highestAmount = tracker->expenses[i].amount;
            snprintf(highestDescription, 50, "%s", tracker->expenses[i].description);
        }
    }
    
    if (highestAmount > 0) {
        printf("Highest Expense: %s - $%.2f\n", highestDescription, highestAmount);
    } else {
        printf("No expenses recorded.\n");
    }
}

// Main entry function to run the expense tracker.
int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    
    char choice;
    do {
        printf("\n=== Expense Tracker ===\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Highest Expense Category\n");
        printf("5. Exit\n");
        printf("Select an option (1-5): ");
        choice = getchar();
        getchar(); // Consume newline character after choice input.

        switch (choice) {
            case '1': {
                char description[50];
                float amount;

                printf("Enter Description: ");
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                
                printf("Enter Amount: ");
                scanf("%f", &amount);
                getchar(); // Consume newline character after amount input.

                addExpense(&tracker, description, amount);
                printf("Expense added!\n");
                break;
            }
            case '2':
                viewExpenses(&tracker);
                break;
            case '3': {
                float total = totalExpenses(&tracker);
                printf("Total Expenses: $%.2f\n", total);
                break;
            }
            case '4':
                highestExpenseCategory(&tracker);
                break;
            case '5':
                printf("Exiting Expense Tracker. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != '5');

    return 0;
}