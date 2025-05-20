//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **expenses = NULL;
    int numExpenses = 0;
    int i = 0;

    printf("Welcome to the Expense Tracker!\n");

    // Loop to get the number of expenses
    printf("How many expenses do you have? ");
    scanf("%d", &numExpenses);

    // Allocate memory for the expenses
    expenses = (char**)malloc(numExpenses * sizeof(char*));

    // Loop to get the details of each expense
    for (i = 0; i < numExpenses; i++)
    {
        expenses[i] = (char*)malloc(50 * sizeof(char));

        printf("Enter the name of the expense: ");
        scanf("%s", expenses[i]);

        printf("Enter the cost of the expense: ");
        scanf("%f", &expenses[i][0]);

        printf("Enter the category of the expense: ");
        scanf("%s", expenses[i][10]);
    }

    // Print the expenses
    printf("Here is a list of your expenses:\n");
    for (i = 0; i < numExpenses; i++)
    {
        printf("Name: %s\n", expenses[i]);
        printf("Cost: %.2f\n", expenses[i][0]);
        printf("Category: %s\n", expenses[i][10]);
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < numExpenses; i++)
    {
        free(expenses[i]);
    }
    free(expenses);

    return 0;
}