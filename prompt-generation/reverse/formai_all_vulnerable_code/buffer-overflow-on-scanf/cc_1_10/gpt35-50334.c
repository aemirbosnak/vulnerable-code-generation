//FormAI DATASET v1.0 Category: Expense Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_DESCRIPTION_LENGTH 50
#define MAX_NUM_EXPENSES 100

struct Expense {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
};

struct ExpenseTracker {
    struct Expense expenses[MAX_NUM_EXPENSES];
    int numExpenses;
};

void printMainMenu() {
    printf("\nExpense Tracker\n");
    printf("1. Add Expense\n");
    printf("2. View Total Expenses\n");
    printf("3. View Expenses by Description\n");
    printf("4. Exit\n");
}

void addExpense(struct ExpenseTracker *tracker) {
    struct Expense newExpense;
    printf("\nEnter description: ");
    fgets(newExpense.description, MAX_DESCRIPTION_LENGTH, stdin);
    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);
    getchar(); //get rid of the newline character that's in the input buffer
    tracker->expenses[tracker->numExpenses++] = newExpense;
    printf("\nExpense added successfully!\n");
}

float getTotalExpenses(struct ExpenseTracker tracker) {
    float total = 0;
    for (int i = 0; i < tracker.numExpenses; i++) {
        total += tracker.expenses[i].amount;
    }
    return total;
}

void viewTotalExpenses(struct ExpenseTracker tracker) {
    float total = getTotalExpenses(tracker);
    printf("\nTotal expenses: $%.2f\n", total);
}

void viewExpensesByDescription(struct ExpenseTracker tracker) {
    char searchTerm[MAX_DESCRIPTION_LENGTH];
    printf("\nEnter description to search for: ");
    fgets(searchTerm, MAX_DESCRIPTION_LENGTH, stdin);
    printf("\nExpenses with \"%s\" in description:\n", searchTerm);
    for (int i = 0; i < tracker.numExpenses; i++) {
        if (strstr(tracker.expenses[i].description, searchTerm) != NULL) {
            printf("$%.2f - %s", tracker.expenses[i].amount, tracker.expenses[i].description);
        }
    }
}

int main() {
    struct ExpenseTracker tracker;
    tracker.numExpenses = 0;

    int choice = 0;
    while (choice != 4) {
        printMainMenu();
        printf("Enter choice: ");
        scanf("%d", &choice);
        getchar(); //get rid of the newline character that's in the input buffer

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewTotalExpenses(tracker);
                break;
            case 3:
                viewExpensesByDescription(tracker);
                break;
            case 4:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}