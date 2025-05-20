//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct {
    char *name;
    float amount;
    time_t date;
} expense;

void add_expense(expense *expenses, int *num_expenses) {
    char input[100];
    printf("Enter expense name: ");
    scanf("%s", input);
    expenses[*num_expenses].name = strdup(input);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*num_expenses].amount);
    time_t now = time(NULL);
    expenses[*num_expenses].date = now;
    (*num_expenses)++;
}

void print_expenses(expense *expenses, int num_expenses) {
    printf("Expense Name\tAmount\tDate\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%s\n", expenses[i].name, expenses[i].amount, ctime(&expenses[i].date));
    }
}

void calculate_total_expense(expense *expenses, int num_expenses, float *total_expense) {
    for (int i = 0; i < num_expenses; i++) {
        *total_expense += expenses[i].amount;
    }
}

int main() {
    int num_expenses = 0;
    expense expenses[100];
    float total_expense = 0.0;

    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);

    print_expenses(expenses, num_expenses);

    calculate_total_expense(expenses, num_expenses, &total_expense);
    printf("Total Expense: %.2f\n", total_expense);

    return 0;
}