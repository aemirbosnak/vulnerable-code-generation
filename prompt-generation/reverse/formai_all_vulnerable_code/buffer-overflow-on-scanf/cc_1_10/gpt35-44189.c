//FormAI DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Welcome to the Expense Tracker program!\n\n");

    // declare variables
    int numExpenses = 0;
    float totalExpenses = 0;

    // get user input for number of expenses
    printf("How many expenses would you like to enter? ");
    scanf("%d", &numExpenses);

    // check if valid number of expenses
    if (numExpenses > 0) {

        // create dynamic array to hold expenses
        float *expenses = malloc(numExpenses * sizeof(float));

        // loop through and input expenses
        for (int i = 0; i < numExpenses; i++) {
            float expense = 0;
            printf("Enter expense #%d: $", i+1);
            scanf("%f", &expense);
            expenses[i] = expense;
            totalExpenses += expense;
        }

        // display expenses entered
        printf("\nExpenses entered:\n");
        for (int i = 0; i < numExpenses; i++) {
            printf("$%.2f\n", expenses[i]);
        }
        printf("\n");

        // display total expenses
        printf("Total expenses for this period: $%.2f\n", totalExpenses);

        // free memory used for expenses array
        free(expenses);

        printf("\nThank you for using the Expense Tracker program!");
        return 0;

    } else {
        printf("Invalid input for number of expenses. Please enter a number greater than 0.\n");
        return 1;
    }
}