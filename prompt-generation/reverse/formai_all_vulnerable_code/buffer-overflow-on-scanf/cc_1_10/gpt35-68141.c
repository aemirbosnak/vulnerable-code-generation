//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char category[50];
    double amount;
};

void addExpense(struct expense *expenses, const char *category, double amount, int *numExpenses) {
    int index = *numExpenses;
    strcpy(expenses[index].category, category);
    expenses[index].amount = amount;
    (*numExpenses)++;
}

double getTotal(struct expense *expenses, int numExpenses) {
    double total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

int main() {
    int numExpenses = 0;
    struct expense expenses[100];

    // Welcome message
    printf("Welcome to the Personal Finance Planner!\n");

    // Get user input
    while (1) {
        char input[50];
        char category[50];
        double amount;

        printf("\nEnter an expense category (or 'quit' to exit): ");
        fgets(input, 50, stdin);
        sscanf(input, "%s", category);

        if (strcmp(category, "quit") == 0) {
            break;
        }

        printf("Enter the amount spent: ");
        scanf("%lf", &amount);
        getchar();

        // Add expense
        addExpense(expenses, category, amount, &numExpenses);
    }

    // Display report
    printf("\n\nExpense Report\n");
    printf("---------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-20s $%.2f\n", expenses[i].category, expenses[i].amount);
    }
    printf("---------------\n");
    printf("Total: $%.2f\n", getTotal(expenses, numExpenses));

    return 0;
}