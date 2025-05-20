//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10

typedef struct Expense {
    char name[50];
    double amount;
    struct Expense* next;
} Expense;

void addExpense(Expense** head) {
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    scanf("%s", newExpense->name);
    scanf("%lf", &newExpense->amount);

    if (*head == NULL) {
        *head = newExpense;
    } else {
        (*head)->next = newExpense;
        *head = newExpense;
    }
}

void printExpenses(Expense* head) {
    while (head) {
        printf("%s: %.2lf\n", head->name, head->amount);
        head = head->next;
    }
}

int main() {
    Expense* head = NULL;

    printf("Welcome to the Expense Tracker!\n");
    printf("Enter 'add' to add an expense, 'print' to print all expenses, or 'exit' to exit:\n");

    char command[20];
    scanf("%s", command);

    while (strcmp(command, "exit") != 0) {
        if (strcmp(command, "add") == 0) {
            addExpense(&head);
        } else if (strcmp(command, "print") == 0) {
            printExpenses(head);
        } else {
            printf("Invalid command.\n");
        }

        scanf("%s", command);
    }

    printf("Goodbye!\n");

    return 0;
}