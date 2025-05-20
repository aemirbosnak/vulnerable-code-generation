//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void main()
{
    // Define an array of structures to store expense data
    struct Expense
    {
        char name[50];
        double amount;
        char category[50];
    } expense[100];

    // Initialize the number of expenses
    int numExpenses = 0;

    // Loop to get expense data from the user
    printf("Enter the name of the expense: ");
    scanf("%s", expense[numExpenses].name);

    // Get the amount of the expense
    printf("Enter the amount of the expense: ");
    scanf("%lf", &expense[numExpenses].amount);

    // Get the category of the expense
    printf("Enter the category of the expense: ");
    scanf("%s", expense[numExpenses].category);

    // Increment the number of expenses
    numExpenses++;

    // Calculate the total expense
    double totalExpense = 0.0;
    for (int i = 0; i < numExpenses; i++)
    {
        totalExpense += expense[i].amount;
    }

    // Calculate the average expense
    double averageExpense = totalExpense / numExpenses;

    // Print the expense data
    printf("Here is a list of your expenses:\n");
    for (int i = 0; i < numExpenses; i++)
    {
        printf("Name: %s\n", expense[i].name);
        printf("Amount: %.2lf\n", expense[i].amount);
        printf("Category: %s\n", expense[i].category);
        printf("\n");
    }

    // Print the total expense
    printf("Total expense: %.2lf\n", totalExpense);

    // Print the average expense
    printf("Average expense: %.2lf\n", averageExpense);

    return;
}