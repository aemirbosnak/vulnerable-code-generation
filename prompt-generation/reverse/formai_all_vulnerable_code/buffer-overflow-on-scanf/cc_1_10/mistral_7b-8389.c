//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH + 1];
    char category[MAX_CATEGORY_LENGTH + 1];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(char *name, char *category, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Expense tracker is full.\n");
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    strcpy(expenses[num_expenses].category, category);
    expenses[num_expenses].amount = amount;

    num_expenses++;
}

void display_expenses() {
    if (num_expenses == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("%-20s %-20s %10s\n", "Name", "Category", "Amount");
    printf("--------------------------------------------\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s %-20s %10.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

bool search_expense(char *name, char *category) {
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0 && strcmp(expenses[i].category, category) == 0) {
            return true;
        }
    }

    return false;
}

int main() {
    char command[MAX_NAME_LENGTH + MAX_CATEGORY_LENGTH + 10];
    char name[MAX_NAME_LENGTH + 1];
    char category[MAX_CATEGORY_LENGTH + 1];
    float amount;

    while (true) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        } else if (strcmp(command, "add") == 0) {
            scanf("%s %s %f", name, category, &amount);
            add_expense(name, category, amount);
        } else if (strcmp(command, "display") == 0) {
            display_expenses();
        } else if (strcmp(command, "search") == 0) {
            scanf("%s %s", name, category);
            if (search_expense(name, category)) {
                printf("Expense found.\n");
            } else {
                printf("Expense not found.\n");
            }
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}