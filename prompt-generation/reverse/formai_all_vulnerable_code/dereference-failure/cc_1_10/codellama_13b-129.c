//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: realistic
// Expense Tracker program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char category[50];
    char description[50];
    float amount;
};

struct ExpenseTracker {
    int num_expenses;
    struct Expense* expenses;
};

struct ExpenseTracker* create_expense_tracker() {
    struct ExpenseTracker* tracker = malloc(sizeof(struct ExpenseTracker));
    tracker->num_expenses = 0;
    tracker->expenses = NULL;
    return tracker;
}

void add_expense(struct ExpenseTracker* tracker, char* category, char* description, float amount) {
    struct Expense* new_expense = malloc(sizeof(struct Expense));
    strcpy(new_expense->category, category);
    strcpy(new_expense->description, description);
    new_expense->amount = amount;

    tracker->num_expenses++;
    tracker->expenses = realloc(tracker->expenses, tracker->num_expenses * sizeof(struct Expense));
    tracker->expenses[tracker->num_expenses - 1] = *new_expense;
}

void print_expense_tracker(struct ExpenseTracker* tracker) {
    printf("Expense Tracker:\n");
    for (int i = 0; i < tracker->num_expenses; i++) {
        printf("%d. %s - %s - $%.2f\n", i + 1, tracker->expenses[i].category, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

int main() {
    struct ExpenseTracker* tracker = create_expense_tracker();
    add_expense(tracker, "Groceries", "Apples", 2.50);
    add_expense(tracker, "Groceries", "Bread", 3.00);
    add_expense(tracker, "Rent", "January Rent", 1500.00);
    print_expense_tracker(tracker);
    return 0;
}