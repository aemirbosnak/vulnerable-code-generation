//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXPENSES 1000

typedef struct expense {
    char name[50];
    float amount;
    time_t time;
} expense_t;

expense_t expenses[MAX_EXPENSES];
int num_expenses = 0;

void print_expenses() {
    int i;
    printf("\nExpenses:\n");
    for (i = 0; i < num_expenses; i++) {
        printf("%d. %s: %.2f\n", i+1, expenses[i].name, expenses[i].amount);
    }
}

void add_expense(char *name, float amount) {
    time_t now;
    expense_t new_expense;

    strcpy(new_expense.name, name);
    new_expense.amount = amount;
    time(&now);
    new_expense.time = now;

    if (num_expenses < MAX_EXPENSES) {
        expenses[num_expenses] = new_expense;
        num_expenses++;
    } else {
        printf("Error: Max number of expenses reached.\n");
    }
}

int main() {
    char input[100];
    float amount;
    int choice;

    while (1) {
        printf("\nExpense Tracker v1.0\n");
        printf("1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", input);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                add_expense(input, amount);
                break;
            case 2:
                print_expenses();
                break;
            case 3:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}