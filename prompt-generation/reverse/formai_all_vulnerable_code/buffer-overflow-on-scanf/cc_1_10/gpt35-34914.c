//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

struct Expense {
    char item[50];
    float cost;
};

int main() {
    int numExpenses;
    float totalExpenses = 0.0;

    printf("Welcome to your Personal Finance Planner!\n");

    // Ask user for number of expenses
    printf("How many expenses would you like to add? ");
    scanf("%d", &numExpenses);

    // Create dynamic array to store expenses
    struct Expense *expenses = malloc(numExpenses * sizeof(struct Expense));

    // Ask user for each expense and cost, and add it to totalExpenses
    for (int i = 0; i < numExpenses; i++) {
        printf("Enter item #%d: ", i + 1);
        scanf("%s", expenses[i].item);

        printf("Enter cost for %s: ", expenses[i].item);
        scanf("%f", &expenses[i].cost);

        totalExpenses += expenses[i].cost;
    }

    // Display all expenses and total expenses
    printf("\nYour expenses are:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].item, expenses[i].cost);
    }

    printf("\nTotal expenses: $%.2f\n", totalExpenses);

    // Ask user for their monthly income and calculate savings
    float monthlyIncome;
    printf("\nWhat is your monthly income? $");
    scanf("%f", &monthlyIncome);

    float savings = monthlyIncome - totalExpenses;
    printf("Your monthly savings: $%.2f\n", savings);

    free(expenses);

    return 0;
}