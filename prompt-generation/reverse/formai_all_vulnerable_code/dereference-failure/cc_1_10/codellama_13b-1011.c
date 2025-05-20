//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
/*
 * Expense Tracker Program
 */

#include <stdio.h>
#include <stdlib.h>

struct expense {
    char* name;
    float amount;
};

struct expense* create_expense(char* name, float amount) {
    struct expense* e = malloc(sizeof(struct expense));
    e->name = name;
    e->amount = amount;
    return e;
}

void print_expense(struct expense* e) {
    printf("Name: %s\n", e->name);
    printf("Amount: %.2f\n", e->amount);
}

void add_expense(struct expense** expenses, int* num_expenses, char* name, float amount) {
    struct expense* e = create_expense(name, amount);
    expenses[*num_expenses] = e;
    (*num_expenses)++;
}

void print_expenses(struct expense** expenses, int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        print_expense(expenses[i]);
    }
}

int main() {
    struct expense** expenses = malloc(10 * sizeof(struct expense*));
    int num_expenses = 0;

    add_expense(&expenses, &num_expenses, "Groceries", 50.50);
    add_expense(&expenses, &num_expenses, "Rent", 1000.00);
    add_expense(&expenses, &num_expenses, "Car Insurance", 150.00);
    add_expense(&expenses, &num_expenses, "Gas", 30.00);
    add_expense(&expenses, &num_expenses, "Entertainment", 100.00);

    print_expenses(expenses, num_expenses);

    return 0;
}