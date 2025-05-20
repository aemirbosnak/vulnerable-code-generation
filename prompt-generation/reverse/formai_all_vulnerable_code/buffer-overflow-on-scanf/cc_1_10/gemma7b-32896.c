//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num_expenses = 0;
    float total_expenses = 0.0f;
    char category[20];

    // Create an array to store expense details
    struct Expense
    {
        char description[50];
        float amount;
        char category[20];
    } expenses[100];

    // Loop to collect expense details
    while (1)
    {
        // Get the expense description
        printf("Enter expense description: ");
        scanf("%s", expenses[num_expenses].description);

        // Get the expense amount
        printf("Enter expense amount: ");
        scanf("%f", &expenses[num_expenses].amount);

        // Get the expense category
        printf("Enter expense category: ");
        scanf("%s", expenses[num_expenses].category);

        // Increment the number of expenses
        num_expenses++;

        // Check if the user wants to continue
        char continue_yn;
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &continue_yn);

        if (continue_yn == 'N')
            break;
    }

    // Calculate the total expenses
    for (int i = 0; i < num_expenses; i++)
    {
        total_expenses += expenses[i].amount;
    }

    // Print the total expenses
    printf("Total expenses: $%.2f\n", total_expenses);

    return 0;
}