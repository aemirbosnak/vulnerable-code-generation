//FormAI DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_DESC_LENGTH 50

struct Expense {
    char description[MAX_DESC_LENGTH];
    float amount;
};

struct ExpenseTracker {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses;
    float totalExpenses;
};

void printMenu() {
    printf("Welcome to Expense Tracker\n");
    printf("--------------------------\n");
    printf("1. Add an expense\n");
    printf("2. View all expenses\n");
    printf("3. View total expenses\n");
    printf("4. Quit\n");
    printf("Enter your choice: ");
}

void addExpense(struct ExpenseTracker *tracker) {
    if (tracker->numExpenses == MAX_EXPENSES) {
        printf("Error: maximum number of expenses reached.\n");
        return;
    }

    struct Expense expense;
    printf("Enter expense description: ");
    fgets(expense.description, MAX_DESC_LENGTH, stdin);
    expense.description[strcspn(expense.description, "\n")] = '\0'; // remove newline character
    printf("Enter expense amount: ");
    scanf("%f", &expense.amount);
    getchar(); // move to next line
    tracker->expenses[tracker->numExpenses] = expense;
    tracker->numExpenses++;
    tracker->totalExpenses += expense.amount;
    printf("Expense added successfully.\n");
}

void viewAllExpenses(struct ExpenseTracker *tracker) {
    printf("All expenses:\n");
    for (int i = 0; i < tracker->numExpenses; i++) {
        printf("%s: $%.2f\n", tracker->expenses[i].description, 
            tracker->expenses[i].amount);
    }
}

void viewTotalExpenses(struct ExpenseTracker *tracker) {
    printf("Total expenses: $%.2f\n", tracker->totalExpenses);
}

int main() {
    struct ExpenseTracker tracker;
    tracker.numExpenses = 0;
    tracker.totalExpenses = 0;

    while (1) {
        printMenu();
        int choice;
        scanf("%d", &choice);
        getchar(); // move to next line
        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewAllExpenses(&tracker);
                break;
            case 3:
                viewTotalExpenses(&tracker);
                break;
            case 4:
                printf("Quitting...");
                exit(EXIT_SUCCESS);
            default:
                printf("Invalid choice. Please enter a valid choice.\n");
        }
    }
    return 0;
}