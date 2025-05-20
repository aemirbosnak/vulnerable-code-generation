//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSE_SIZE 10

typedef struct Expense {
    char name[50];
    int amount;
    struct Expense* next;
} Expense;

Expense* insertExpense(Expense* head, char* name, int amount) {
    Expense* newExpense = malloc(sizeof(Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
    } else {
        head->next = newExpense;
    }

    return head;
}

void printExpenses(Expense* head) {
    while (head) {
        printf("%s: %d\n", head->name, head->amount);
        head = head->next;
    }
}

int main() {
    Expense* head = NULL;

    // Multiplayer interaction
    printf("Enter expense name:");
    char name[50];
    scanf("%s", name);

    printf("Enter expense amount:");
    int amount;
    scanf("%d", &amount);

    insertExpense(head, name, amount);

    printf("List of expenses:");
    printExpenses(head);

    return 0;
}