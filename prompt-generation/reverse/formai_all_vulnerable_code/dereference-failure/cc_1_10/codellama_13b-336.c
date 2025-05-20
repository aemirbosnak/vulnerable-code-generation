//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
// Expense Tracker Example Program

#include <stdio.h>
#include <stdlib.h>

struct expense {
    char* description;
    float amount;
};

int main() {
    struct expense* expenses = NULL;
    int num_expenses = 0;

    // Print welcome message
    printf("Welcome to the Expense Tracker!\n");

    // Add expenses
    while (1) {
        printf("Enter an expense description: ");
        char* description = malloc(100 * sizeof(char));
        scanf("%s", description);

        printf("Enter the expense amount: ");
        float amount;
        scanf("%f", &amount);

        // Add expense to array
        struct expense* new_expense = malloc(sizeof(struct expense));
        new_expense->description = description;
        new_expense->amount = amount;
        expenses = realloc(expenses, (num_expenses + 1) * sizeof(struct expense));
        expenses[num_expenses] = *new_expense;
        num_expenses++;

        // Print expense
        printf("Added expense: %s - $%.2f\n", new_expense->description, new_expense->amount);
    }

    // Calculate total expenses
    float total_expenses = 0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
    }

    // Print total expenses
    printf("Total expenses: $%.2f\n", total_expenses);

    return 0;
}