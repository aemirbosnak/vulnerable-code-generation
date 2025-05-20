//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSE 10

typedef struct Expense {
    char name[20];
    int amount;
    struct Expense* next;
} Expense;

void addExpense(Expense** head) {
    Expense* newExpense = (Expense*)malloc(sizeof(Expense));
    printf("Enter expense name: ");
    scanf("%s", newExpense->name);
    printf("Enter expense amount: ");
    scanf("%d", &newExpense->amount);

    if (*head == NULL) {
        *head = newExpense;
    } else {
        (*head)->next = newExpense;
    }
    *head = newExpense;
}

void displayExpenses(Expense* head) {
    printf("List of expenses:\n");
    while (head) {
        printf("%s - %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main() {
    Expense* head = NULL;

    while (1) {
        printf("Enter 'add' to add an expense, 'display' to display expenses, or 'exit' to exit: ");
        char command[20];
        scanf("%s", command);

        if (strcmp(command, "add") == 0) {
            addExpense(&head);
        } else if (strcmp(command, "display") == 0) {
            displayExpenses(head);
        } else if (strcmp(command, "exit") == 0) {
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}