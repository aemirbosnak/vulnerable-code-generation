//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSE 10

int main()
{
    // Declare an array of structures to store expenses
    struct Expense
    {
        char name[50];
        int amount;
        char category[50];
    } expenses[MAX_EXPENSE];

    // Initialize the array of structures
    for (int i = 0; i < MAX_EXPENSE; i++)
    {
        expenses[i].name[0] = '\0';
        expenses[i].amount = 0;
        expenses[i].category[0] = '\0';
    }

    // Get the number of expenses from the user
    int numExpenses;
    printf("Enter the number of expenses: ");
    scanf("%d", &numExpenses);

    // Loop over the number of expenses and get the information for each expense
    for (int i = 0; i < numExpenses; i++)
    {
        // Get the expense name
        printf("Enter the name of the expense: ");
        scanf("%s", expenses[i].name);

        // Get the expense amount
        printf("Enter the amount of the expense: ");
        scanf("%d", &expenses[i].amount);

        // Get the expense category
        printf("Enter the category of the expense: ");
        scanf("%s", expenses[i].category);
    }

    // Print the expenses
    printf("Here is a list of your expenses:\n");
    for (int i = 0; i < numExpenses; i++)
    {
        printf("Name: %s, Amount: %d, Category: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
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