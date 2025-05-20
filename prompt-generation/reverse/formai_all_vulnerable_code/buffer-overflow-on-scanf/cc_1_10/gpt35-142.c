//FormAI DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 20

struct Expense {
    char name[MAX_NAME_LENGTH];
    float amount;
    char date[11]; // format MM/DD/YYYY
};

struct ExpenseTracker {
    int numExpenses;
    struct Expense expenses[MAX_EXPENSES];
};

void addExpense(struct ExpenseTracker *tracker) {
    if (tracker->numExpenses == MAX_EXPENSES) {
        printf("Can't add more expenses!\n");
        return;
    }

    struct Expense expense;

    // get name
    printf("Enter expense name: ");
    scanf("%s", expense.name);

    // get amount
    printf("Enter expense amount: ");
    scanf("%f", &expense.amount);

    // get date
    printf("Enter date (MM/DD/YYYY): ");
    scanf("%s", expense.date);

    // add expense to tracker
    tracker->expenses[tracker->numExpenses] = expense;
    tracker->numExpenses++;

    printf("Expense added successfully!\n");
}

void viewExpenses(struct ExpenseTracker tracker) {
    if (tracker.numExpenses == 0) {
        printf("No expenses to display!\n");
        return;
    }

    printf("%-20s %-10s %-10s\n", "Name", "Amount", "Date");

    for (int i = 0; i < tracker.numExpenses; i++) {
        printf("%-20s $%-9.2f %s\n", tracker.expenses[i].name, tracker.expenses[i].amount, tracker.expenses[i].date);
    }
}

int main() {
    struct ExpenseTracker tracker;
    tracker.numExpenses = 0;

    while (1) {
        printf("\n1. Add expense\n2. View expenses\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(tracker);
                break;
            case 3:
                printf("Exiting..\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}