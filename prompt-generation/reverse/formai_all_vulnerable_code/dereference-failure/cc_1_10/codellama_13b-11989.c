//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: modular
/*
 * expense_tracker.c
 *
 * A modular expense tracker program in C
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LENGTH 25
#define MAX_DESC_LENGTH 50
#define MAX_AMOUNT 999999999999

// Structures to store data
typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESC_LENGTH];
    int amount;
} Expense;

typedef struct {
    Expense *expenses;
    int num_expenses;
} ExpenseTracker;

// Functions to manipulate data
ExpenseTracker *expense_tracker_create();
void expense_tracker_add_expense(ExpenseTracker *tracker, const char *name, const char *description, int amount);
void expense_tracker_print(ExpenseTracker *tracker);

// Main function
int main() {
    ExpenseTracker *tracker = expense_tracker_create();

    // Add expenses to the tracker
    expense_tracker_add_expense(tracker, "Groceries", "Rice, Milk, Eggs, Bread", 500);
    expense_tracker_add_expense(tracker, "Transportation", "Gas, Car payment", 200);
    expense_tracker_add_expense(tracker, "Entertainment", "Movie tickets, Concert tickets", 250);

    // Print the expense tracker
    expense_tracker_print(tracker);

    // Free the memory
    free(tracker);

    return 0;
}

// Function definitions
ExpenseTracker *expense_tracker_create() {
    ExpenseTracker *tracker = malloc(sizeof(ExpenseTracker));
    tracker->num_expenses = 0;
    tracker->expenses = NULL;
    return tracker;
}

void expense_tracker_add_expense(ExpenseTracker *tracker, const char *name, const char *description, int amount) {
    // Check if the expense is valid
    if (amount < 0) {
        printf("Invalid expense amount: %d\n", amount);
        return;
    }

    // Allocate memory for the new expense
    Expense *expense = malloc(sizeof(Expense));
    strcpy(expense->name, name);
    strcpy(expense->description, description);
    expense->amount = amount;

    // Add the expense to the tracker
    tracker->expenses = realloc(tracker->expenses, (tracker->num_expenses + 1) * sizeof(Expense));
    tracker->expenses[tracker->num_expenses] = *expense;
    tracker->num_expenses++;

    // Free the memory for the expense
    free(expense);
}

void expense_tracker_print(ExpenseTracker *tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%s: %s (%d)\n", tracker->expenses[i].name, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}