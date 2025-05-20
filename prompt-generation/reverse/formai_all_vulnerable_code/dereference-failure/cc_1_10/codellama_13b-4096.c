//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: protected
/*
 * Expense Tracker Program
 * Written in a protected style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char description[50];
    float amount;
};

struct expense_tracker {
    struct expense* expenses;
    int num_expenses;
    int capacity;
};

void add_expense(struct expense_tracker* tracker, struct expense expense) {
    if (tracker->num_expenses == tracker->capacity) {
        tracker->capacity *= 2;
        tracker->expenses = realloc(tracker->expenses, tracker->capacity * sizeof(struct expense));
    }
    tracker->expenses[tracker->num_expenses] = expense;
    tracker->num_expenses++;
}

void print_expenses(struct expense_tracker* tracker) {
    printf("Expense Tracker\n");
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

int main() {
    struct expense_tracker tracker = {
        .expenses = NULL,
        .num_expenses = 0,
        .capacity = 10
    };

    struct expense expense1 = {
        .description = "Grocery shopping",
        .amount = 100.50
    };
    add_expense(&tracker, expense1);

    struct expense expense2 = {
        .description = "Dinner at restaurant",
        .amount = 50.25
    };
    add_expense(&tracker, expense2);

    struct expense expense3 = {
        .description = "Cinema ticket",
        .amount = 20.00
    };
    add_expense(&tracker, expense3);

    print_expenses(&tracker);

    return 0;
}