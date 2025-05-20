//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSE_NUM 10

struct Expense {
    char name[50];
    double amount;
    int category;
};

void validate_expense(struct Expense*);

int main() {
    struct Expense expenses[MAX_EXPENSE_NUM];
    int i = 0;

    // Loop to get expenses
    while (expenses[i].name[0] != '\0') {
        printf("Enter expense name: ");
        scanf("%s", expenses[i].name);

        printf("Enter expense amount: ");
        scanf("%lf", &expenses[i].amount);

        printf("Enter expense category (1-3): ");
        scanf("%d", &expenses[i].category);

        validate_expense(&expenses[i]);

        i++;
    }

    // Print expenses
    printf("List of expenses:\n");
    for (i = 0; expenses[i].name[0] != '\0'; i++) {
        printf("Name: %s, Amount: %.2lf, Category: %d\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }

    return 0;
}

void validate_expense(struct Expense* expense) {
    // Check if expense name is valid
    if (strlen(expense->name) > 50) {
        printf("Error: Expense name is too long.\n");
        exit(1);
    }

    // Check if expense amount is valid
    if (expense->amount < 0) {
        printf("Error: Expense amount is invalid.\n");
        exit(1);
    }

    // Check if expense category is valid
    if (expense->category < 1 || expense->category > 3) {
        printf("Error: Expense category is invalid.\n");
        exit(1);
    }
}