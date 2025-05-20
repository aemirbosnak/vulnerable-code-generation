//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[20];
    char description[50];
    float amount;
    struct Expense *next;
};

struct ExpenseTracker {
    struct Expense *expenses;
    int num_expenses;
};

void print_expense_tracker(struct ExpenseTracker *tracker) {
    struct Expense *current = tracker->expenses;
    while (current != NULL) {
        printf("%s - %s - $%.2f\n", current->category, current->description, current->amount);
        current = current->next;
    }
}

void add_expense(struct ExpenseTracker *tracker, char *category, char *description, float amount) {
    struct Expense *new_expense = malloc(sizeof(struct Expense));
    strcpy(new_expense->category, category);
    strcpy(new_expense->description, description);
    new_expense->amount = amount;
    new_expense->next = tracker->expenses;
    tracker->expenses = new_expense;
    tracker->num_expenses++;
}

void remove_expense(struct ExpenseTracker *tracker, int index) {
    if (index < 0 || index >= tracker->num_expenses) {
        return;
    }
    struct Expense *current = tracker->expenses;
    struct Expense *previous = NULL;
    while (current != NULL && index > 0) {
        previous = current;
        current = current->next;
        index--;
    }
    if (current == tracker->expenses) {
        tracker->expenses = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    tracker->num_expenses--;
}

void clear_expense_tracker(struct ExpenseTracker *tracker) {
    struct Expense *current = tracker->expenses;
    while (current != NULL) {
        struct Expense *next = current->next;
        free(current);
        current = next;
    }
    tracker->expenses = NULL;
    tracker->num_expenses = 0;
}

int main() {
    struct ExpenseTracker tracker;
    tracker.expenses = NULL;
    tracker.num_expenses = 0;

    add_expense(&tracker, "Groceries", "Milk", 2.50);
    add_expense(&tracker, "Groceries", "Eggs", 3.50);
    add_expense(&tracker, "Groceries", "Bread", 5.00);
    add_expense(&tracker, "Entertainment", "Movie tickets", 15.00);
    add_expense(&tracker, "Entertainment", "Concert tickets", 50.00);

    print_expense_tracker(&tracker);

    remove_expense(&tracker, 1);
    print_expense_tracker(&tracker);

    clear_expense_tracker(&tracker);
    print_expense_tracker(&tracker);

    return 0;
}