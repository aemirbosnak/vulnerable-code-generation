//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    double amount;
} expense;

void add_expense(expense* expenses, int* num_expenses) {
    printf("Enter expense name: ");
    fgets(expenses[*num_expenses].name, MAX_NAME_LENGTH, stdin);
    printf("Enter expense category: ");
    fgets(expenses[*num_expenses].category, MAX_CATEGORY_LENGTH, stdin);
    printf("Enter expense amount: $");
    scanf("%lf", &expenses[*num_expenses].amount);
    (*num_expenses)++;
}

void print_expenses(expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %s - $%.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void calculate_total_expenses(expense* expenses, int num_expenses, double* total_expenses) {
    *total_expenses = 0;
    for (int i = 0; i < num_expenses; i++) {
        *total_expenses += expenses[i].amount;
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;
    double total_expenses = 0;

    printf("Welcome to the expense tracker!\n");
    printf("How many expenses do you want to add? ");
    scanf("%d", &num_expenses);

    for (int i = 0; i < num_expenses; i++) {
        add_expense(expenses, &num_expenses);
    }

    print_expenses(expenses, num_expenses);

    printf("Total expenses: $%.2f\n", total_expenses);

    return 0;
}