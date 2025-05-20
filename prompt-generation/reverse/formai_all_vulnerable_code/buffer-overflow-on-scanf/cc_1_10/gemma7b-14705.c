//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int i = 0;
    char name[20];
    float amount;
    char category[20];

    printf("Welcome to the Surprise Expense Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", name);

    printf("Hi, %s, let's track your expenses!\n", name);

    // Allocate memory for the expense list
    float *expenses = (float *)malloc(10 * sizeof(float));

    // Get the number of expenses
    printf("How many expenses do you want to track? ");
    scanf("%d", &i);

    // Loop to get the expense details
    for (int j = 0; j < i; j++)
    {
        printf("Enter the expense name: ");
        scanf("%s", category);

        printf("Enter the expense amount: ");
        scanf("%f", &amount);

        // Store the expense details in the list
        expenses[j] = amount;
    }

    // Calculate the total expense
    float total_expense = 0;
    for (int j = 0; j < i; j++)
    {
        total_expense += expenses[j];
    }

    // Display the total expense
    printf("Your total expense is: $%.2f", total_expense);

    // Free the memory allocated for the expense list
    free(expenses);

    return;
}