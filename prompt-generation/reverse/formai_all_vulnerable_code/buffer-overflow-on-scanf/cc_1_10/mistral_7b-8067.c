//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define EXPENSE_NAME_LENGTH 50

typedef struct Expense {
    char name[EXPENSE_NAME_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense(const char* name, float amount) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Whoa, you've reached the maximum number of expenses! Try to keep it under control.\n");
        return;
    }
    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    num_expenses++;
}

void print_expenses() {
    printf("\nCurrent Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s: $%.2f\n", i+1, expenses[i].name, expenses[i].amount);
    }
}

int main() {
    char input[100];
    float amount;
    int choice;

    while (1) {
        printf("\nWelcome to the Surprising Expense Tracker!\n");
        printf("1. Add Expense\n");
        printf("2. Print Expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", input);
                input[strlen(input) - 1] = '\0'; // remove trailing newline character
                sscanf(input, "%f", &amount); // read expense amount
                add_expense(input, amount);
                printf("Expense added successfully!\n");
                break;

            case 2:
                print_expenses();
                break;

            case 3:
                printf("Goodbye and happy expense tracking!\n");
                exit(0);

            default:
                printf("Uh, I don't understand that choice. Please try again.\n");
        }
    }

    return 0;
}