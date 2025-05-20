//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: recursive
/*
 * Unique C Expense Tracker example program in a recursive style
 */

#include <stdio.h>

struct Expense {
    int amount;
    struct Expense* next;
};

struct Expense* addExpense(struct Expense* head, int amount) {
    struct Expense* newExpense = (struct Expense*) malloc(sizeof(struct Expense));
    newExpense->amount = amount;
    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
    } else {
        struct Expense* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newExpense;
    }

    return head;
}

struct Expense* removeExpense(struct Expense* head, int amount) {
    struct Expense* current = head;
    struct Expense* previous = NULL;

    while (current != NULL) {
        if (current->amount == amount) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            break;
        }
        previous = current;
        current = current->next;
    }

    return head;
}

int totalExpenses(struct Expense* head) {
    int total = 0;
    while (head != NULL) {
        total += head->amount;
        head = head->next;
    }
    return total;
}

int main() {
    struct Expense* head = NULL;
    head = addExpense(head, 100);
    head = addExpense(head, 200);
    head = addExpense(head, 300);
    head = addExpense(head, 400);

    printf("Total expenses: %d\n", totalExpenses(head));

    head = removeExpense(head, 200);
    head = removeExpense(head, 400);

    printf("Total expenses after removing 200 and 400: %d\n", totalExpenses(head));

    return 0;
}