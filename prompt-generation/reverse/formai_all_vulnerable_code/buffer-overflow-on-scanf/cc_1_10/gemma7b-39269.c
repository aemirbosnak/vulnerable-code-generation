//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define an array to store expense data
int main()
{
    int expenses[100];
    int i = 0;
    char name[20];
    char description[100];
    float amount;

    // Loop to get expense data
    printf("Enter the name of the expense:");
    scanf("%s", name);

    printf("Enter the description of the expense:");
    scanf("%s", description);

    printf("Enter the amount of the expense:");
    scanf("%f", &amount);

    // Store the expense data in the array
    expenses[i] = amount;
    i++;

    // Repeat the above steps for all expenses
    while (expenses[i - 1] != -1)
    {
        printf("Enter the name of the expense:");
        scanf("%s", name);

        printf("Enter the description of the expense:");
        scanf("%s", description);

        printf("Enter the amount of the expense:");
        scanf("%f", &amount);

        // Store the expense data in the array
        expenses[i] = amount;
        i++;
    }

    // Calculate the total expense
    float total_expense = 0;
    for (int j = 0; j < i; j++)
    {
        total_expense += expenses[j];
    }

    // Print the total expense
    printf("The total expense is: $%.2f", total_expense);

    return 0;
}