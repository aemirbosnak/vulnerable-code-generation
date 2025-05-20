//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main()
{
    // Initialize variables
    char name[50];
    int age, income, expenses[100];
    double total_expenses = 0.0;
    int num_expenses = 0;

    // Get user input
    printf("Welcome to the Expense Tracker!\n");
    printf("Enter your name: ");
    fgets(name, sizeof(name), stdin);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your monthly income: ");
    scanf("%d", &income);

    // Create a list of expenses
    printf("Enter your expenses (or 0 to finish):\n");
    for(int i = 0; i < 100; i++)
    {
        scanf("%d", &expenses[i]);
        if(expenses[i] == 0)
        {
            break;
        }
        num_expenses++;
    }

    // Calculate total expenses
    for(int i = 0; i < num_expenses; i++)
    {
        total_expenses += expenses[i];
    }

    // Print results
    printf("Total expenses: %d\n", num_expenses);
    printf("Average expense: %f\n", total_expenses / num_expenses);
    printf("You are %d years old and have an income of %d.\n", age, income);
    printf("Your expenses are: ");
    for(int i = 0; i < num_expenses; i++)
    {
        printf("%d ", expenses[i]);
    }
    printf("\n");

    // Generate random numbers for creativity
    srand(time(NULL));
    int rand_num[10];
    for(int i = 0; i < 10; i++)
    {
        rand_num[i] = rand() % 100;
    }

    // Print random numbers
    printf("Here are some random numbers for creativity: ");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", rand_num[i]);
    }
    printf("\n");

    return 0;
}