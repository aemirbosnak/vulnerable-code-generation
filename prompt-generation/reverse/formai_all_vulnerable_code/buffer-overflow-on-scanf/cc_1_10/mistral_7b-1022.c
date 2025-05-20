//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 100

typedef struct Expense {
    char name[MAX_NAME_LEN];
    char desc[MAX_DESC_LEN];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void error(const char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

void add_expense(Expense *exp) {
    if (head == NULL) {
        head = exp;
        return;
    }

    Expense *current = head;
    while (current->next != NULL) current = current->next;

    current->next = exp;
}

void view_expenses() {
    Expense *current = head;

    printf("\nExpenses:\n");
    printf("--------------------------------------------------\n");

    while (current != NULL) {
        printf("%s\t%s\t%.2f\n", current->name, current->desc, current->amount);
        current = current->next;
    }

    printf("--------------------------------------------------\n");
}

void delete_expense(char *name) {
    Expense *current = head;
    Expense *prev = NULL;

    while (current != NULL && strcmp(current->name, name) != 0) {
        prev = current;
        current = current->next;
    }

    if (current == NULL) {
        error("Expense not found.");
    }

    if (prev == NULL) {
        head = current->next;
    } else {
        prev->next = current->next;
    }

    free(current);
}

int main() {
    Expense *new_expense;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Delete expense\n");
        printf("4. Quit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                new_expense = (Expense *) malloc(sizeof(Expense));
                if (new_expense == NULL) error("Memory allocation failed.");

                printf("Name: ");
                scanf("%s", new_expense->name);

                printf("Description: ");
                scanf("%s", new_expense->desc);

                printf("Amount: ");
                scanf("%f", &new_expense->amount);

                add_expense(new_expense);
                break;
            }
            case 2:
                view_expenses();
                break;
            case 3: {
                char name[MAX_NAME_LEN];
                printf("Name of expense to delete: ");
                scanf("%s", name);

                delete_expense(name);
                break;
            }
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}