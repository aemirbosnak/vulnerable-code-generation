//FormAI DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 10
#define MAX_LENGTH 20

struct Expense {
    char name[MAX_LENGTH];
    float amount;
};

void printExpenses(struct Expense *expenses, int count) {
    printf("Expenses\n");
    printf("--------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t$%.2f\n", expenses[i].name, expenses[i].amount);
    }
    printf("--------\n");
}

void addExpense(struct Expense *expenses, int *count) {
    if (*count == MAX_EXPENSES) {
        printf("You have reached the maximum number of expenses.\n");
        return;
    }

    struct Expense expense;
    printf("Enter expense name: ");
    scanf("%s", expense.name);
    printf("Enter expense amount: ");
    scanf("%f", &expense.amount);

    expenses[*count] = expense;
    (*count)++;

    printf("%s added to expenses.\n", expense.name);
}

int main() {
    struct Expense expenses[MAX_EXPENSES];
    int count = 0;
    char choice[MAX_LENGTH];
    do {
        printf("\nMENU\n");
        printf("=====\n");
        printf("1. View Expenses\n");
        printf("2. Add Expense\n");
        printf("3. Exit\n");

        printf("Enter choice: ");
        scanf("%s", choice);

        if (strcmp(choice, "1") == 0) {
            printExpenses(expenses, count);
        } else if (strcmp(choice, "2") == 0) {
            addExpense(expenses, &count);
        } else if (strcmp(choice, "3") != 0) {
            printf("Invalid choice.\n");
        }
    } while (strcmp(choice, "3") != 0);

    return 0;
}