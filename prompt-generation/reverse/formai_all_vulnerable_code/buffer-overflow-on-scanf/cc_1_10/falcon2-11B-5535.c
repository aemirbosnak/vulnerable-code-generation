//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char* name, const char* amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Too many expenses\n");
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    strcpy(expenses[num_expenses].amount, amount);
    num_expenses++;
}

void print_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %s\n", expenses[i].amount);
    }
}

int main() {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];

    while (1) {
        printf("Add expense? (y/n): ");
        char input[2];
        scanf(" %s", input);

        if (strcmp(input, "n") == 0) {
            break;
        }

        printf("Enter name: ");
        scanf(" %s", name);

        printf("Enter amount: ");
        scanf(" %s", amount);

        add_expense(name, amount);
    }

    printf("Expenses:\n");
    print_expenses();

    return 0;
}