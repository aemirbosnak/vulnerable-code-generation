//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void printMenu() {
    printf("\n----- Expense Tracker -----\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. View Total Expenses\n");
    printf("4. Clear All Expenses\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
    printf("Select an option: ");
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Error: Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    
    Expense new_expense;
    printf("Enter description (max %d characters): ", MAX_DESC_LEN - 1);
    getchar(); // consume newline
    fgets(new_expense.description, MAX_DESC_LEN, stdin);
    new_expense.description[strcspn(new_expense.description, "\n")] = 0; // remove newline

    printf("Enter amount: ");
    scanf("%f", &new_expense.amount);
    
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", new_expense.date);

    tracker->expenses[tracker->count] = new_expense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n----- Your Expenses -----\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Description: %s | Amount: %.2f | Date: %s\n",
               tracker->expenses[i].description,
               tracker->expenses[i].amount,
               tracker->expenses[i].date);
    }
}

void viewTotalExpenses(ExpenseTracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void clearAllExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses cleared!\n");
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;

    int choice;
    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
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
                clearAllExpenses(&tracker);
                break;
            case 5:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}