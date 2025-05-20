//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: Romeo and Juliet
#include <stdio.h>
#include <string.h>

#define MAX_EXPENSES 10

typedef struct Expense {
    char name[20];
    int amount;
    char category[20];
} Expense;

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    // Create a Romeo and Juliet style expense tracker
    printf("Welcome to the Capulet-Montague Expense Tracker!\n");
    printf("Please enter the name of the expense:");
    scanf("%s", expenses[numExpenses].name);

    printf("Enter the amount of the expense:");
    scanf("%d", &expenses[numExpenses].amount);

    printf("Enter the category of the expense:");
    scanf("%s", expenses[numExpenses].category);

    numExpenses++;

    // Repeat for as many expenses as the user wants
    while (numExpenses < MAX_EXPENSES) {
        printf("Please enter the name of the expense:");
        scanf("%s", expenses[numExpenses].name);

        printf("Enter the amount of the expense:");
        scanf("%d", &expenses[numExpenses].amount);

        printf("Enter the category of the expense:");
        scanf("%s", expenses[numExpenses].category);

        numExpenses++;
    }

    // Print a list of all expenses
    printf("Here is a list of your expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %d\n", expenses[i].amount);
        printf("Category: %s\n", expenses[i].category);
        printf("\n");
    }

    // Calculate the total cost of all expenses
    int totalCost = 0;
    for (int i = 0; i < numExpenses; i++) {
        totalCost += expenses[i].amount;
    }

    // Print the total cost of all expenses
    printf("Total cost of expenses: %d\n", totalCost);

    return 0;
}