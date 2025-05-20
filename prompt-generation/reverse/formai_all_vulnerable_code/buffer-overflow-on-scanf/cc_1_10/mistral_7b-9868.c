//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_NAME_LEN 30
#define MAX_AMOUNT 99999.99

typedef struct {
    char name[MAX_NAME_LEN + 1];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char* name, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Max number of expenses reached.\n");
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    num_expenses++;
}

void print_expenses() {
    printf("\nExpenses:\n");
    printf("----------------------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("| %-*s | %8.2f |\n", (int)(MAX_NAME_LEN - strlen(expenses[i].name)), expenses[i].name, expenses[i].amount);
    }

    printf("----------------------------------\n");
}

int main() {
    char name[MAX_NAME_LEN + 1];
    float amount;

    while (1) {
        printf("\nExpense Tracker > ");
        scanf("%s", name);

        if (strcmp(name, "quit") == 0) {
            break;
        }

        printf("Amount: ");
        scanf("%f", &amount);

        if (amount <= 0 || amount > MAX_AMOUNT) {
            printf("Invalid amount.\n");
            continue;
        }

        add_expense(name, amount);
    }

    print_expenses();

    return 0;
}