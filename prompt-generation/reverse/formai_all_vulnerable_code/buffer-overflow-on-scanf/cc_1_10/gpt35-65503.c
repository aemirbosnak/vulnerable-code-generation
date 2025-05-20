//FormAI DATASET v1.0 Category: Expense Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

struct Expense {
    char name[MAX_LEN];
    double amount;
};

int main() {
    int numExpenses = 0;
    double totalSpent = 0.0;
    struct Expense* expenses = malloc(sizeof(struct Expense));

    if(expenses == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Welcome to Expense Tracker!\n");

    while(1) {
        printf("Enter expense name (or 'exit' to quit): ");
        char name[MAX_LEN];
        scanf("%s", name);

        if(strcmp(name, "exit") == 0) {
            break;
        }

        printf("Enter amount spent: ");
        double amount;
        scanf("%lf", &amount);

        struct Expense expense = { "", 0.0 };
        strncpy(expense.name, name, MAX_LEN);
        expense.amount = amount;

        numExpenses++;
        totalSpent += expense.amount;
        expenses = realloc(expenses, numExpenses * sizeof(struct Expense));
        expenses[numExpenses - 1] = expense;
    }

    printf("\nExpenses:\n");
    printf("--------------------------------\n");
    for(int i = 0; i < numExpenses; i++) {
        struct Expense expense = expenses[i];
        printf("%s: $%.2lf\n", expense.name, expense.amount);
    }

    printf("--------------------------------\n");
    printf("Total spent: $%.2lf\n", totalSpent);

    free(expenses);

    return 0;
}