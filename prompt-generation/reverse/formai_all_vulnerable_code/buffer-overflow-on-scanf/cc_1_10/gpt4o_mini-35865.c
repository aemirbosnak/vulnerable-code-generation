//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 100

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void displayMenu() {
    printf("\n******* Welcome to the Exciting Expense Tracker! *******\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Exit\n");
    printf("**********************************************\n");
    printf("Please select an option (1-4): ");
}

void addExpense(ExpenseTracker* tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Oops! Can't add more expenses, limit reached!\n");
        return;
    }

    Expense newExpense;
    printf("Enter description of the expense: ");
    scanf(" %[^\n]", newExpense.description);
    printf("Enter the amount for the expense: ");
    scanf("%f", &newExpense.amount);
    
    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    
    printf("Yay! You've successfully added an expense: %s - $%.2f\n", newExpense.description, newExpense.amount);
}

void viewExpenses(ExpenseTracker tracker) {
    if (tracker.count == 0) {
        printf("Oh no! There are no expenses to display!\n");
        return;
    }

    printf("\n**** Your Expenses ****\n");
    for (int i = 0; i < tracker.count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker.expenses[i].description, tracker.expenses[i].amount);
    }
}

void totalExpenses(ExpenseTracker tracker) {
    float total = 0;
    for (int i = 0; i < tracker.count; i++) {
        total += tracker.expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(tracker);
                break;
            case 3:
                totalExpenses(tracker);
                break;
            case 4:
                printf("Thank you for using the Expense Tracker! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please select a valid one.\n");
        }
    }

    return 0;
}