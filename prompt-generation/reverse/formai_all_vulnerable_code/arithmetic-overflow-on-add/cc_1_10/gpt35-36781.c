//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int salary, rent, bills, groceries, transport, savings;

    printf("Welcome to your Personal Finance Planner!\n");
    printf("Please input your monthly salary: ");
    scanf("%d", &salary);

    printf("Please input your monthly rental: ");
    scanf("%d", &rent);

    printf("Please input your monthly bills: ");
    scanf("%d", &bills);

    printf("Please input your monthly groceries: ");
    scanf("%d", &groceries);

    printf("Please input your monthly transportation expenses: ");
    scanf("%d", &transport);

    savings = salary - (rent + bills + groceries + transport);

    printf("\n\nHere is your monthly budget breakdown:\n");
    printf("Your salary: %d\n", salary);
    printf("Your rental: %d\n", rent);
    printf("Your bills: %d\n", bills);
    printf("Your groceries: %d\n", groceries);
    printf("Your transportation expenses: %d\n", transport);
    printf("Your savings: %d\n", savings);

    if (savings >= (salary / 4))
    {
        printf("\nCongratulations! You are saving 25%% of your salary.\n");
    }
    else if (savings >= (salary / 6))
    {
        printf("\nGood job! You are saving at least 16.67%% of your salary.\n");
    }
    else if (savings >= (salary / 10))
    {
        printf("\nNot bad! You are saving at least 10%% of your salary.\n");
    }
    else
    {
        printf("\nYou need to work on your budgeting. Try to save at least 10%% of your salary.\n");
    }

    return 0;
}