//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define EXPENSE_NAME_LENGTH 50
#define EXPENSE_AMOUNT_LENGTH 10

struct Expense {
    char name[EXPENSE_NAME_LENGTH];
    float amount;
};

void addExpense(struct Expense expenses[], char name[], float amount, int* numExpenses) {
    if (*numExpenses < MAX_EXPENSES) {
        strcpy(expenses[*numExpenses].name, name);
        expenses[*numExpenses].amount = amount;
        (*numExpenses)++;
    } else {
        printf("Maximum number of expenses reached.\n");
    }
}

void printExpenses(struct Expense expenses[], int numExpenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: %.2f\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    int numExpenses = 0;
    struct Expense expenses[MAX_EXPENSES];

    char name[EXPENSE_NAME_LENGTH];
    float amount;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense name: ");
                scanf("%s", name);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(expenses, name, amount, &numExpenses);
                break;

            case 2:
                printExpenses(expenses, numExpenses);
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}