//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXPENSES 100
#define MAX_EXPENSE_NAME_LENGTH 50
#define MAX_EXPENSE_AMOUNT_LENGTH 10

struct expense {
    char name[MAX_EXPENSE_NAME_LENGTH];
    char amount[MAX_EXPENSE_AMOUNT_LENGTH];
    time_t date;
};

void add_expense(struct expense *expenses, int num_expenses, char *name, char *amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    strcpy(expenses[num_expenses].amount, amount);
    time(&expenses[num_expenses].date);

    num_expenses++;
}

void display_expenses(struct expense *expenses, int num_expenses) {
    printf("Expenses:\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %s - %s\n", expenses[i].name, expenses[i].amount, ctime(&expenses[i].date));
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    char name[MAX_EXPENSE_NAME_LENGTH];
    char amount[MAX_EXPENSE_AMOUNT_LENGTH];

    while (1) {
        printf("Enter expense name: ");
        scanf("%s", name);

        printf("Enter expense amount: ");
        scanf("%s", amount);

        add_expense(expenses, num_expenses, name, amount);
    }

    return 0;
}