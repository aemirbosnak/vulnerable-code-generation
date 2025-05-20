//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 10

typedef struct Expense {
    char name[50];
    float amount;
    struct Expense* next;
} Expense;

Expense* insertExpense(Expense* head) {
    Expense* newExpense = malloc(sizeof(Expense));
    printf("Enter expense name: ");
    scanf("%s", newExpense->name);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense->amount);
    newExpense->next = NULL;

    if (head == NULL) {
        head = newExpense;
    } else {
        head->next = newExpense;
    }

    return head;
}

void displayExpenses(Expense* head) {
    printf("List of expenses:\n");
    while (head) {
        printf("%s - %.2f\n", head->name, head->amount);
        head = head->next;
    }
}

int main() {
    Expense* head = NULL;

    printf("Welcome to your expense tracker!\n");
    printf("Enter 'add' to add a new expense, 'display' to see your expenses, or 'quit' to quit: ");

    char command;
    scanf("%c", &command);

    while (command != 'quit') {
        switch (command) {
            case 'add':
                head = insertExpense(head);
                break;
            case 'display':
                displayExpenses(head);
                break;
            default:
                printf("Invalid command.\n");
        }

        printf("Enter 'add' to add a new expense, 'display' to see your expenses, or 'quit' to quit: ");
        scanf("%c", &command);
    }

    printf("Thank you for using your expense tracker.\n");

    return 0;
}