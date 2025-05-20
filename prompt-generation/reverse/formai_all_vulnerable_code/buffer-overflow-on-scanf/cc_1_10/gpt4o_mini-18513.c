//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Expense {
    char description[100];
    float amount;
    struct Expense *next;
} Expense;

Expense *head = NULL;

void addExpense(const char *description, float amount) {
    Expense *newExpense = (Expense *)malloc(sizeof(Expense));
    if (newExpense == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    strcpy(newExpense->description, description);
    newExpense->amount = amount;
    newExpense->next = head;
    head = newExpense;
    printf("Expense added: %s - $%.2f\n", description, amount);
}

void deleteExpense(const char *description) {
    Expense *current = head;
    Expense *previous = NULL;

    while (current != NULL) {
        if (strcmp(current->description, description) == 0) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            free(current);
            printf("Expense deleted: %s\n", description);
            return;
        }
        previous = current;
        current = current->next;
    }
    printf("Expense not found: %s\n", description);
}

void viewExpenses() {
    Expense *current = head;
    printf("\nExpenses List:\n");
    if (current == NULL) {
        printf("No expenses found.\n");
        return;
    }
    while (current != NULL) {
        printf("Description: %s, Amount: $%.2f\n", current->description, current->amount);
        current = current->next;
    }
}

void freeExpenses() {
    Expense *current = head;
    Expense *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    int choice;
    char description[100];
    float amount;

    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Delete Expense\n");
        printf("3. View Expenses\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter description: ");
                scanf("%s", description);
                printf("Enter amount: ");
                scanf("%f", &amount);
                addExpense(description, amount);
                break;
            case 2:
                printf("Enter description to delete: ");
                scanf("%s", description);
                deleteExpense(description);
                break;
            case 3:
                viewExpenses();
                break;
            case 0:
                freeExpenses();
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}