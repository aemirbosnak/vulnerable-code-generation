//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int i, n, choice, total = 0, flag = 0;
    char name[MAX];
    struct expense
    {
        char name[MAX];
        int amount;
    } expenses[MAX];

    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter the number of expenses you want to track:");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the name of the expense:");
        scanf("%s", expenses[i].name);

        printf("Enter the amount of the expense:");
        scanf("%d", &expenses[i].amount);

        total += expenses[i].amount;
    }

    printf("Here is a summary of your expenses:");
    for (i = 0; i < n; i++)
    {
        printf("Name: %s, Amount: %d\n", expenses[i].name, expenses[i].amount);
    }

    printf("Total Expenses: %d\n", total);

    if (total > 500)
    {
        flag = 1;
        printf("WARNING: Total expenses exceed $500!\n");
    }

    if (flag)
    {
        printf("Please consider reducing your expenses.\n");
    }

    return 0;
}