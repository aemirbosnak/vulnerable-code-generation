//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define an array of structures to store expense data
    struct expense
    {
        char name[20];
        int amount;
        char category[20];
    } expenses[100];

    // Initialize the number of expenses
    int numExpenses = 0;

    // Loop to get expense data from the user
    while (1)
    {
        // Get the expense name, amount, and category
        printf("Enter expense name: ");
        scanf("%s", expenses[numExpenses].name);

        printf("Enter expense amount: ");
        scanf("%d", &expenses[numExpenses].amount);

        printf("Enter expense category: ");
        scanf("%s", expenses[numExpenses].category);

        // Increment the number of expenses
        numExpenses++;

        // Check if the user wants to continue
        char continue_yn;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_yn);

        // If the user does not want to continue, break out of the loop
        if (continue_yn == 'N')
            break;
    }

    // Print the expense data
    for (int i = 0; i < numExpenses; i++)
    {
        printf("%s: %d, Category: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }

    // Calculate the total expense
    int totalExpense = 0;
    for (int i = 0; i < numExpenses; i++)
    {
        totalExpense += expenses[i].amount;
    }

    // Print the total expense
    printf("Total expense: %d\n", totalExpense);

    return 0;
}