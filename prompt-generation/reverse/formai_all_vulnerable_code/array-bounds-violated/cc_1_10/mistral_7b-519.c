//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_EXPENSES 100

typedef struct expense {
    char name[50];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char *name, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Max number of expenses reached.\n");
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    num_expenses++;
}

void list_expenses() {
    if (num_expenses == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s: $%.2f\n", i+1, expenses[i].name, expenses[i].amount);
    }
}

int main() {
    char command[50];
    float amount;

    while (1) {
        printf("\nExpense Tracker v1.0\n");
        printf("Command: ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';

        switch (*command) {
            case 'A':
            case 'a': {
                printf("Enter expense name: ");
                fgets(command, sizeof(command), stdin);
                command[strlen(command) - 1] = '\0';
                printf("Enter expense amount: $");
                scanf("%f", &amount);
                add_expense(command, amount);
                break;
            }

            case 'L':
            case 'l': list_expenses(); break;

            case 'Q':
            case 'q': exit(0);

            default: printf("Invalid command. Use 'A' to add an expense, 'L' to list expenses, or 'Q' to quit.\n");
        }
    }

    return 0;
}