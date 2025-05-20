//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int num_expenses = 0;
    float total_expenses = 0.0f;
    char expense_name[20];
    float expense_amount;

    // Welcome the user
    printf("Hello, and thank you for using my expense tracker!\n");

    // Loop until the user enters an expense or chooses to quit
    while (1)
    {
        // Get the expense name and amount
        printf("Enter the name of the expense: ");
        scanf("%s", expense_name);

        printf("Enter the amount of the expense: ");
        scanf("%f", &expense_amount);

        // Calculate the total expense
        total_expenses += expense_amount;

        // Increment the number of expenses
        num_expenses++;

        // Check if the user wants to continue or quit
        printf("Do you want to enter another expense? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        // If the user wants to quit, break out of the loop
        if (answer == 'N')
        {
            break;
        }
    }

    // Calculate the average expense
    float average_expense = total_expenses / num_expenses;

    // Print the total and average expenses
    printf("Total expenses: $%.2f\n", total_expenses);
    printf("Average expense: $%.2f\n", average_expense);

    // Thank the user
    printf("Thank you for using my expense tracker! Have a nice day!\n");

    return 0;
}