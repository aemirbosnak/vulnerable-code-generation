//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int num_expenses = 0;
    float total_expense = 0.0f;
    char category[50];
    float amount;

    // Loop to collect expenses
    while (1)
    {
        // Get the expense category
        printf("Enter the expense category: ");
        scanf("%s", category);

        // Get the expense amount
        printf("Enter the expense amount: ");
        scanf("%f", &amount);

        // Increment the number of expenses
        num_expenses++;

        // Add the expense amount to the total expense
        total_expense += amount;

        // Check if the user wants to continue
        printf("Do you want to continue? (Y/N): ");
        char continue_char;
        scanf("%c", &continue_char);

        // If the user does not want to continue, break out of the loop
        if (continue_char != 'Y')
        {
            break;
        }
    }

    // Calculate the average expense
    float average_expense = total_expense / num_expenses;

    // Print the results
    printf("\nTotal number of expenses: %d", num_expenses);
    printf("\nTotal expense: %.2f", total_expense);
    printf("\nAverage expense: %.2f", average_expense);

    return 0;
}