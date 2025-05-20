//FormAI DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    char name[50];
    float amount;
    char category[50];
    char date[20];
};

int main() {
    int numOfExpenses = 0;
    struct Expense *expenses = malloc(numOfExpenses * sizeof(struct Expense));
    int i;
    char input[50];

    while (1) {
        printf("Enter expense name or type 'quit' to exit: ");
        scanf("%s", input);

        if (strcmp(input, "quit") == 0) {
            break;
        }

        numOfExpenses++;
        expenses = realloc(expenses, numOfExpenses * sizeof(struct Expense));
        strcpy(expenses[numOfExpenses-1].name, input);

        printf("Enter expense amount: ");
        scanf("%f", &expenses[numOfExpenses-1].amount);

        printf("Enter expense category: ");
        scanf("%s", expenses[numOfExpenses-1].category);

        printf("Enter expense date: ");
        scanf("%s", expenses[numOfExpenses-1].date);
    }

    float totalExpenses = 0;
    printf("\nExpenses:\n");
    for (i = 0; i < numOfExpenses; i++) {
        printf("%s | $%.2f | %s | %s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
        totalExpenses += expenses[i].amount;
    }

    printf("\nTotal Expenses: $%.2f", totalExpenses);

    free(expenses);
    return 0;
}