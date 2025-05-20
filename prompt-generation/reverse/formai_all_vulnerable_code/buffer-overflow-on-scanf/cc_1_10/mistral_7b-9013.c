//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define EXPENSE_NAME_LENGTH 50
#define EXPENSE_AMOUNT_LENGTH 10

typedef struct {
    char name[EXPENSE_NAME_LENGTH];
    int amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int current_expense = 0;

void add_expense(char *name, int amount) {
    if (current_expense >= MAX_EXPENSES) {
        printf("Max number of expenses reached.\n");
        return;
    }
    strcpy(expenses[current_expense].name, name);
    expenses[current_expense].amount = amount;
    current_expense++;
}

void display_expenses() {
    printf("\nCurrent Expenses:\n");
    for (int i = 0; i < current_expense; i++) {
        printf("%s: %d\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    char input_name[EXPENSE_NAME_LENGTH];
    char input_amount[EXPENSE_AMOUNT_LENGTH];

    while (1) {
        printf("\nWelcome traveler, please enter an expense name and amount in the following format: 'name amount'\n");
        scanf("%s%s", input_name, input_amount);

        int amount = atoi(input_amount);
        if (strlen(input_name) > EXPENSE_NAME_LENGTH - 1) {
            printf("Name too long.\n");
            continue;
        }

        add_expense(input_name, amount);

        printf("Expense added successfully.\n");

        int choice;
        printf("\nDo you want to add another expense? (1) yes, (0) no: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break;
        }
    }

    display_expenses();

    return 0;
}