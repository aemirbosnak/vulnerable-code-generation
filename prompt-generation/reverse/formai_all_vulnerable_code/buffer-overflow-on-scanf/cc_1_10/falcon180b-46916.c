//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 20
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
    char category[MAX_CATEGORIES];
} expense;

void add_expense(expense* expenses, int* num_expenses) {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORIES];
    double amount;

    printf("Enter expense name: ");
    scanf("%s", name);

    printf("Enter expense amount: $");
    scanf("%lf", &amount);

    printf("Enter expense category (e.g. Food, Rent, Utilities): ");
    scanf("%s", category);

    strcpy(expenses[*num_expenses].name, name);
    expenses[*num_expenses].amount = amount;
    strcpy(expenses[*num_expenses].category, category);

    (*num_expenses)++;
}

void print_expenses(expense* expenses, int num_expenses) {
    printf("Expense Name           | Expense Amount | Expense Category\n");
    printf("-----------------------+---------------+-----------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-30s $%-9.2f %-20s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (num_expenses < MAX_EXPENSES) {
        add_expense(expenses, &num_expenses);
    }

    print_expenses(expenses, num_expenses);

    return 0;
}