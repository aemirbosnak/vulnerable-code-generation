//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Define an array of structures to store expense data
    struct Expense
    {
        char name[50];
        float amount;
        char category[50];
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
        scanf("%f", &expenses[numExpenses].amount);

        printf("Enter expense category: ");
        scanf("%s", expenses[numExpenses].category);

        // Increment the number of expenses
        numExpenses++;

        // Check if the user wants to continue
        printf("Do you want to add another expense? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        if (answer == 'N' || answer == 'n')
        {
            break;
        }
    }

    // Calculate the total expense
    float totalExpense = 0;
    for (int i = 0; i < numExpenses; i++)
    {
        totalExpense += expenses[i].amount;
    }

    // Print the total expense
    printf("Total expense: $%.2f", totalExpense);

    // Print the expense data
    printf("\nExpenses:\n");
    for (int i = 0; i < numExpenses; i++)
    {
        printf("%s: $%.2f, Category: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }

    return 0;
}