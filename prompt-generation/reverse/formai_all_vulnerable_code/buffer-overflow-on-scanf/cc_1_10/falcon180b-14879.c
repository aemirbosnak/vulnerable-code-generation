//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_NAME 50
#define MAX_DESCRIPTION 100
#define MAX_AMOUNT 10

typedef struct {
    char name[MAX_NAME];
    char description[MAX_DESCRIPTION];
    float amount;
} expense;

void add_expense(expense* expenses, int* num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*num_expenses].name);
    printf("Enter expense description: ");
    scanf("%s", expenses[*num_expenses].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*num_expenses].amount);
    (*num_expenses)++;
}

void display_expenses(expense* expenses, int num_expenses) {
    printf("Expense Name\tExpense Description\tExpense Amount\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%.2f\n", expenses[i].name, expenses[i].description, expenses[i].amount);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Welcome to the Expense Tracker!\n");
    printf("Enter the number of expenses you want to track: ");
    scanf("%d", &num_expenses);

    printf("Enter expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        add_expense(expenses, &num_expenses);
    }

    printf("Expenses:\n");
    display_expenses(expenses, num_expenses);

    return 0;
}