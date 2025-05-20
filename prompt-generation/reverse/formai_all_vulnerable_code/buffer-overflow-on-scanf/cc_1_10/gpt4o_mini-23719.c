//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[50];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Whoa there! Maximum expense limit reached!\n");
        return;
    }

    Expense newExpense;

    printf("Enter expense description (max 50 characters): ");
    fgets(newExpense.description, sizeof(newExpense.description), stdin);
    // Remove newline character
    newExpense.description[strcspn(newExpense.description, "\n")] = 0;

    printf("Enter expense amount: ");
    if (scanf("%f", &newExpense.amount) != 1) {
        printf("Wait, what? Please enter a valid number!\n");
        // Clear the input buffer
        while (getchar() != '\n');
        return;
    }
    // Clear the input buffer
    while (getchar() != '\n');

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void displayExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("Hold on! You have no expenses recorded yet!\n");
        return;
    }

    printf("\n=== Your Expenses ===\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

void calculateTotalExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("Uh-oh! No expenses to calculate!\n");
        return;
    }

    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void clearExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses cleared! You can start fresh now!!\n");
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;

    int choice;
    char input[10];

    while (1) {
        printf("\n=== Expense Tracker ===\n");
        printf("1. Add an Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Clear All Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        fgets(input, sizeof(input), stdin);
        choice = atoi(input);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                calculateTotalExpenses(&tracker);
                break;
            case 4:
                clearExpenses(&tracker);
                break;
            case 5:
                printf("Goodbye! Don't spend too much!\n");
                exit(0);
            default:
                printf("Oops! That's not a valid choice!\n");
                break;
        }
    }

    return 0;
}