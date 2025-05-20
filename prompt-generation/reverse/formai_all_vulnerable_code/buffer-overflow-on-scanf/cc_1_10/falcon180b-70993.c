//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_EXPENSE_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char expense_name[MAX_EXPENSE_NAME_LENGTH];
    double amount;
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    printf("Enter your name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].expense_name);

    printf("Enter expense amount: $");
    scanf("%lf", &expenses[num_expenses].amount);

    num_expenses++;
}

void view_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s spent $%.2f on %s\n", expenses[i].name, expenses[i].amount, expenses[i].expense_name);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", expenses[num_expenses].name);

    while (1) {
        printf("\nOptions:\n1. Add expense\n2. View expenses\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                printf("Goodbye, %s!\n", expenses[0].name);
                return 0;
            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}