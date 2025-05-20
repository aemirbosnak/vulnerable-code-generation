//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50

typedef struct {
    char description[50];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(char *description, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Max number of expenses reached.\n");
        return;
    }

    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    num_expenses++;
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("Error: No expenses to display.\n");
        return;
    }

    printf("\nExpense List:\n");
    printf("--------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("| %-45s | $%.2f |\n", expenses[i].description, expenses[i].amount);
    }
    printf("--------------------\n");
}

void remove_expense(char *description) {
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].description, description) == 0) {
            for (int j = i; j < num_expenses - 1; j++) {
                expenses[j] = expenses[j + 1];
            }
            num_expenses--;
            printf("Expense '%s' removed.\n", description);
            return;
        }
    }

    printf("Error: Expense not found.\n");
}

int main() {
    char description[50];
    float amount;

    while (1) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Remove Expense\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense description: ");
                scanf("%s", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                add_expense(description, amount);
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                printf("Enter expense description to remove: ");
                scanf("%s", description);
                remove_expense(description);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}