//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char name[50];
    float amount;
    struct Expense* next;
} Expense;

Expense* head = NULL;

void addExpense(char* name, float amount) {
    Expense* newExpense = (Expense*)calloc(1, sizeof(Expense));
    strcpy(newExpense->name, name);
    newExpense->amount = amount;
    newExpense->next = head;
    head = newExpense;
}

void printExpenses() {
    Expense* current = head;
    while (current != NULL) {
        printf("%s: %.2f\n", current->name, current->amount);
        current = current->next;
    }
}

void searchExpenses(char* name) {
    Expense* current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            printf("%s: %.2f\n", current->name, current->amount);
            return;
        }
        current = current->next;
    }
    printf("Expense not found.\n");
}

int main() {
    char command[50];
    char name[50];
    float amount;

    while (1) {
        printf("\nExpense Tracker\n1. Add Expense\n2. Print Expenses\n3. Search Expenses\n4. Quit\nEnter command: ");
        scanf("%s", command);

        switch (*command) {
            case '1':
                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(name, amount);
                break;
            case '2':
                printExpenses();
                break;
            case '3':
                printf("Enter expense name to search: ");
                scanf("%s", name);
                searchExpenses(name);
                break;
            case '4':
                exit(0);
                break;
            default:
                printf("Invalid command.\n");
        }
    }

    return 0;
}