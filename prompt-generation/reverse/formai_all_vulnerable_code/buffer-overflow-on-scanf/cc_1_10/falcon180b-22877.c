//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];
} expense;

void add_expense(expense expenses[], int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    printf("Enter expense amount: ");
    scanf("%s", expenses[num_expenses].amount);

    num_expenses++;
}

void display_expenses(expense expenses[], int num_expenses) {
    printf("\nExpenses:\n");
    printf("Name\tCategory\tAmount\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%s\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter your expenses below:\n");

    while (num_expenses < MAX_EXPENSES) {
        add_expense(expenses, num_expenses);
    }

    display_expenses(expenses, num_expenses);

    return 0;
}