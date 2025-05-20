//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSE_AMOUNT 1000000
#define MAX_EXPENSE_NAME_LENGTH 100

typedef struct {
    int amount;
    char name[MAX_EXPENSE_NAME_LENGTH];
} Expense;

void addExpense(Expense* expenses, int size, int amount, char* name) {
    if (size >= MAX_EXPENSE_AMOUNT) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    strncpy(expenses[size].name, name, MAX_EXPENSE_NAME_LENGTH);
    expenses[size].amount = amount;
    size++;
}

void displayExpenses(Expense* expenses, int size) {
    for (int i = 0; i < size; i++) {
        printf("Name: %s, Amount: %d\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    Expense expenses[MAX_EXPENSE_AMOUNT];
    int size = 0;

    while (1) {
        printf("Enter the amount of the expense (0 to exit): ");
        int amount;
        scanf("%d", &amount);

        if (amount == 0) {
            break;
        }

        printf("Enter the name of the expense: ");
        char name[MAX_EXPENSE_NAME_LENGTH];
        fgets(name, MAX_EXPENSE_NAME_LENGTH, stdin);

        if (strlen(name) > MAX_EXPENSE_NAME_LENGTH) {
            printf("Error: Name is too long.\n");
            continue;
        }

        addExpense(expenses, size, amount, name);
        size++;
    }

    displayExpenses(expenses, size);

    return 0;
}