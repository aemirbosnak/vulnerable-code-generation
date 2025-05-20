//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_AMOUNT_LEN 20

typedef struct expense {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char amount[MAX_AMOUNT_LEN];
} expense;

void add_expense(expense* expenses, int num_expenses, char* name, char* category, char* amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Cannot add more expenses.\n");
        return;
    }

    int i;
    for (i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            printf("Error: Expense with name '%s' already exists.\n", name);
            return;
        }
    }

    strcpy(expenses[num_expenses].name, name);
    strcpy(expenses[num_expenses].category, category);
    strcpy(expenses[num_expenses].amount, amount);

    num_expenses++;
}

void print_expenses(expense* expenses, int num_expenses) {
    if (num_expenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("Expense Name\tCategory\tAmount\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-50s\t%-50s\t%s\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    char name[MAX_NAME_LEN], category[MAX_CATEGORY_LEN], amount[MAX_AMOUNT_LEN];

    while (1) {
        printf("Enter expense name (leave blank to exit): ");
        scanf("%s", name);

        if (strcmp(name, "") == 0) {
            break;
        }

        printf("Enter expense category: ");
        scanf("%s", category);

        printf("Enter expense amount: ");
        scanf("%s", amount);

        add_expense(expenses, num_expenses, name, category, amount);
    }

    printf("Expenses:\n");
    print_expenses(expenses, num_expenses);

    return 0;
}