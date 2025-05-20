//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSE_NUM 10

typedef struct Expense {
    char name[20];
    float amount;
    struct Expense* next;
} Expense;

void addExpense(Expense** head) {
    Expense* newExpense = malloc(sizeof(Expense));
    printf("Enter expense name: ");
    scanf("%s", newExpense->name);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense->amount);

    if (*head == NULL) {
        *head = newExpense;
    } else {
        ((*head)->next = newExpense);
        *head = newExpense;
    }
}

void printExpenses(Expense* head) {
    while (head) {
        printf("Name: %s, Amount: %.2f\n", head->name, head->amount);
        head = head->next;
    }
}

int main() {
    Expense* head = NULL;
    int choice = 0;

    while (choice != 3) {
        printf("Enter 1 to add an expense, 2 to print expenses, 3 to exit: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&head);
                break;
            case 2:
                printExpenses(head);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}