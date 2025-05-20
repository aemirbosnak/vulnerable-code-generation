//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: creative
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

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter the description of the expense: ");
    getchar(); // Clear the newline character left by previous input
    fgets(newExpense.description, sizeof(newExpense.description), stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    printf("Enter the amount of the expense: ");
    scanf("%f", &newExpense.amount);

    tracker->expenses[tracker->count++] = newExpense;
    printf("Expense added successfully!\n");
}

void listExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n------- Expense List -------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("[%d] %s: $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("----------------------------\n");
}

void calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void displayMenu() {
    printf("\n--- Welcome to the Expense Tracker! ---\n");
    printf("1. Add an Expense\n");
    printf("2. List Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
    printf("Please select an option (1-4): ");
}

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                listExpenses(&tracker);
                break;
            case 3:
                calculateTotal(&tracker);
                break;
            case 4:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}