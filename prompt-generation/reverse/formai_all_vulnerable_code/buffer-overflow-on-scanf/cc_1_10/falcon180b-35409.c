//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} expense_t;

void add_expense(expense_t* expenses, int num_expenses, char* name, char* amount) {
    if (num_expenses >= MAX_ITEMS) {
        printf("Error: Cannot add more expenses. Maximum limit reached.\n");
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    strcpy(expenses[num_expenses].amount, amount);
    num_expenses++;
}

void view_expenses(expense_t* expenses, int num_expenses) {
    if (num_expenses == 0) {
        printf("No expenses added yet.\n");
        return;
    }

    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: %s\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    expense_t expenses[MAX_ITEMS];
    int num_expenses = 0;

    char input[100];
    while (1) {
        printf("Enter expense name: ");
        scanf("%s", input);
        if (strcmp(input, "exit") == 0) {
            break;
        }

        char amount[MAX_AMOUNT_LEN];
        printf("Enter expense amount: ");
        scanf("%s", amount);

        add_expense(expenses, num_expenses, input, amount);
    }

    view_expenses(expenses, num_expenses);

    return 0;
}