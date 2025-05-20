//FormAI DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 10

// define the structure for an expense
struct Expense {
    int day;
    int month;
    int year;
    float amount;
    char description[50];
};

// define the main function
int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    float totalExpenses = 0.0;

    printf("Welcome to the Expense Tracker!\n\n");
    printf("Enter your expenses and keep track of your spending.\n");
    printf("Press Ctrl + C to exit at any time.\n\n");

    while (1) {
        // prompt the user to enter a new expense
        printf("Enter the day (1-31) of the expense: ");
        scanf("%i", &expenses[numExpenses].day);

        printf("Enter the month (1-12) of the expense: ");
        scanf("%i", &expenses[numExpenses].month);

        printf("Enter the year (e.g. 2021) of the expense: ");
        scanf("%i", &expenses[numExpenses].year);

        printf("Enter the amount of the expense: ");
        scanf("%f", &expenses[numExpenses].amount);

        printf("Enter a brief description of the expense: ");
        scanf("%s", expenses[numExpenses].description);

        // increment the number of expenses
        numExpenses++;

        // check if the maximum number of expenses has been reached
        if (numExpenses == MAX_EXPENSES) {
            printf("\nMaximum number of expenses reached!\n\n");
            break;
        }
    }

    // print a summary of the expenses
    printf("\n----------------------------------------\n");
    printf("Summary of Expenses:\n");
    printf("----------------------------------------\n");

    for (int i = 0; i < numExpenses; i++) {
        printf("- Date: %i/%i/%i\n", expenses[i].day, expenses[i].month, expenses[i].year);
        printf("- Amount: $%.2f\n", expenses[i].amount);
        printf("- Description: %s\n", expenses[i].description);

        // calculate the total expenses
        totalExpenses += expenses[i].amount;

        printf("\n");
    }

    // print the total expenses
    printf("----------------------------------------\n");
    printf("Total expenses: $%.2f\n", totalExpenses);

    return 0;
}