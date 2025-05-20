//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSE_ITEMS 10

typedef struct ExpenseItem {
    char name[50];
    int amount;
    struct ExpenseItem* next;
} ExpenseItem;

void addExpenseItem(ExpenseItem** head) {
    ExpenseItem* newExpenseItem = malloc(sizeof(ExpenseItem));
    newExpenseItem->next = NULL;

    printf("Enter expense item name: ");
    scanf("%s", newExpenseItem->name);

    printf("Enter expense item amount: ");
    scanf("%d", &newExpenseItem->amount);

    if (*head == NULL) {
        *head = newExpenseItem;
    } else {
        (*head)->next = newExpenseItem;
    }
}

void printExpenseItems(ExpenseItem* head) {
    printf("List of expense items:\n");
    while (head) {
        printf("Item name: %s\n", head->name);
        printf("Item amount: %d\n", head->amount);
        printf("\n");
        head = head->next;
    }
}

int main() {
    ExpenseItem* head = NULL;

    // Add expense items
    addExpenseItem(&head);
    addExpenseItem(&head);
    addExpenseItem(&head);

    // Print expense items
    printExpenseItems(head);

    return 0;
}