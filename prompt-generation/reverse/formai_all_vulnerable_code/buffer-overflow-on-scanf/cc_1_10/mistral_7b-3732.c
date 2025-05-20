//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10
#define MAX_NAME_LEN 20
#define MAX_COST 100

typedef struct Expense {
    char name[MAX_NAME_LEN + 1];
    int cost;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(char *name, int cost) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Not enough space to add expense: '%s'\n", name);
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].cost = cost;
    num_expenses++;
}

void print_expenses() {
    int total = 0;

    printf("\nCurrent expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: %d\n", expenses[i].name, expenses[i].cost);
        total += expenses[i].cost;
    }

    printf("\nTotal expenses: %d\n", total);
}

int main() {
    char name[MAX_NAME_LEN + 1];
    int cost;

    while (1) {
        printf("\nMax's Expense Tracker\n");
        printf("Enter expense name (or 'quit' to exit): ");
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        printf("Enter expense cost: ");
        scanf("%d", &cost);

        add_expense(name, cost);
    }

    printf("\nExpenses added successfully.\n");
    print_expenses();

    return 0;
}