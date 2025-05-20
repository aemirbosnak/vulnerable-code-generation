//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define EXPENSE_SIZE 100

typedef struct {
    char name[EXPENSE_SIZE];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char *name, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        fprintf(stderr, "Max number of expenses reached\n");
        return;
    }
    strncpy(expenses[num_expenses].name, name, EXPENSE_SIZE);
    expenses[num_expenses].amount = amount;
    num_expenses++;
}

void print_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: %.2f\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    char command[10];
    while (1) {
        printf("> ");
        scanf("%s", command);
        if (strcmp(command, "add") == 0) {
            char name[EXPENSE_SIZE];
            float amount;
            printf("Name: ");
            scanf("%s", name);
            printf("Amount: ");
            scanf("%f", &amount);
            add_expense(name, amount);
        } else if (strcmp(command, "print") == 0) {
            print_expenses();
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unknown command\n");
        }
    }
    return 0;
}