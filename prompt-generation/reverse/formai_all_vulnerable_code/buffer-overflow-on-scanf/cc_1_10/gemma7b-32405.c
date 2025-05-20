//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>
#include <stdlib.h>

int main()
{

    // Declare variables for expense tracking
    int numExpenses = 0;
    float totalExpense = 0.0f;
    char* expenseDescription[100];
    float expenseAmount[100];

    // Create a loop to collect expenses
    while (1)
    {
        // Get the expense description
        printf("Enter the expense description: ");
        expenseDescription[numExpenses] = malloc(20);
        scanf("%s", expenseDescription[numExpenses]);

        // Get the expense amount
        printf("Enter the expense amount: ");
        scanf("%f", &expenseAmount[numExpenses]);

        // Increment the number of expenses
        numExpenses++;

        // Check if the user wants to continue tracking expenses
        printf("Do you want to track another expense? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        // Break out of the loop if the user does not want to continue
        if (answer == 'N')
        {
            break;
        }
    }

    // Calculate the total expense
    for (int i = 0; i < numExpenses; i++)
    {
        totalExpense += expenseAmount[i];
    }

    // Print the total expense
    printf("Total expense: $%.2f\n", totalExpense);

    // Free memory allocated for expense descriptions
    for (int i = 0; i < numExpenses; i++)
    {
        free(expenseDescription[i]);
    }

    return 0;
}