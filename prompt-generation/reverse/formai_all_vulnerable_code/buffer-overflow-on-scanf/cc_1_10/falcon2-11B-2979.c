//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char name[50];
    int amount;
    bool is_paid;
} expense_t;

int main() {
    expense_t expenses[10];
    int num_expenses = 0;
    char input[100];

    while (true) {
        printf("Enter expense name (or 'quit' to exit): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "quit") == 0) {
            break;
        }

        expense_t new_expense = {
           .name = strdup(input),
           .amount = 0,
           .is_paid = false,
        };

        printf("Enter expense amount: ");
        scanf("%d", &new_expense.amount);

        expenses[num_expenses++] = new_expense;
        if (num_expenses == sizeof(expenses) / sizeof(expense_t)) {
            printf("Too many expenses! Cannot add any more.\n");
        }
    }

    for (int i = 0; i < num_expenses; i++) {
        expense_t expense = expenses[i];
        if (expense.is_paid) {
            printf("%s ($%d) is paid!\n", expense.name, expense.amount);
        } else {
            printf("%s ($%d) is not paid yet.\n", expense.name, expense.amount);
        }
    }

    return 0;
}