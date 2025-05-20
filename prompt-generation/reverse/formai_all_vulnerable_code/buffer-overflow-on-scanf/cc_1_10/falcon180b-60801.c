//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
} expense;

void add_expense(expense* expenses, int num_expenses, char* name, double amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    num_expenses++;
}

void print_expenses(expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void calculate_total(expense* expenses, int num_expenses, double* total) {
    for (int i = 0; i < num_expenses; i++) {
        *total += expenses[i].amount;
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    double total = 0.0;
    char name[50];
    double amount;

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("Enter expense name: ");
        scanf("%s", name);
        printf("Enter expense amount: $");
        scanf("%lf", &amount);
        add_expense(expenses, num_expenses, name, amount);
    }

    print_expenses(expenses, num_expenses);
    calculate_total(expenses, num_expenses, &total);

    printf("\nTotal expenses: $%.2f\n", total);

    return 0;
}