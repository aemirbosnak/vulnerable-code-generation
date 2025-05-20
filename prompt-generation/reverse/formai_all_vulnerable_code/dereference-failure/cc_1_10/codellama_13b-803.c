//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char name[256];
    float amount;
};

struct ExpenseTracker {
    struct Expense* expenses;
    int num_expenses;
};

struct ExpenseTracker* create_expense_tracker() {
    struct ExpenseTracker* tracker = malloc(sizeof(struct ExpenseTracker));
    tracker->expenses = malloc(sizeof(struct Expense) * 10);
    tracker->num_expenses = 0;
    return tracker;
}

void add_expense(struct ExpenseTracker* tracker, char* name, float amount) {
    struct Expense* expense = &tracker->expenses[tracker->num_expenses];
    strcpy(expense->name, name);
    expense->amount = amount;
    tracker->num_expenses++;
}

float get_total_expenses(struct ExpenseTracker* tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->num_expenses; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void print_expenses(struct ExpenseTracker* tracker) {
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%s: %f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
    }
}

int main() {
    struct ExpenseTracker* tracker = create_expense_tracker();

    add_expense(tracker, "Rent", 1500.00);
    add_expense(tracker, "Groceries", 50.00);
    add_expense(tracker, "Coffee", 2.50);

    printf("Total expenses: %f\n", get_total_expenses(tracker));

    print_expenses(tracker);

    free(tracker->expenses);
    free(tracker);

    return 0;
}