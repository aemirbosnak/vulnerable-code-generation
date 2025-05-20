//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10

typedef struct Expense {
    char name[50];
    int amount;
    char category[50];
} Expense;

void addExpense(Expense *expenses, int *numExpenses) {
    *numExpenses++;

    expenses = (Expense *)realloc(expenses, *numExpenses * sizeof(Expense));

    printf("Enter expense name: ");
    scanf("%s", expenses[*numExpenses - 1].name);

    printf("Enter expense amount: ");
    scanf("%d", &expenses[*numExpenses - 1].amount);

    printf("Enter expense category: ");
    scanf("%s", expenses[*numExpenses - 1].category);
}

void printExpenses(Expense *expenses, int numExpenses) {
    for (int i = 0; i < numExpenses; i++) {
        printf("%s - %d - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    Expense *expenses = NULL;
    int numExpenses = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("Enter 'add' to add an expense, 'print' to print expenses, or 'exit' to exit: ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            addExpense(expenses, &numExpenses);
        } else if (strcmp(command, "print") == 0) {
            printExpenses(expenses, numExpenses);
        } else if (strcmp(command, "exit") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }
    }

    printf("Thank you for using the Expense Tracker!\n");

    return 0;
}