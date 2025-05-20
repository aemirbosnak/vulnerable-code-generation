//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main()
{
    int i, j, n, cash, total = 0;
    char name[MAX];

    printf("Welcome to your Personal Finance Planner!\n");
    printf("Please provide your name: ");
    scanf("%s", name);

    printf("Hey, %s, let's manage your finances!\n", name);
    printf("Please tell me the number of transactions you want to record: ");
    scanf("%d", &n);

    cash = 0;
    for (i = 0; i < n; i++)
    {
        int amount, type;

        printf("Enter the transaction amount: ");
        scanf("%d", &amount);

        printf("Choose the transaction type:\n");
        printf("1. Income\n");
        printf("2. Expense\n");
        scanf("%d", &type);

        if (type == 1)
        {
            cash += amount;
        }
        else if (type == 2)
        {
            cash -= amount;
        }

        total += amount;
    }

    printf("Here's a summary of your finances, %s:\n", name);
    printf("Total cash: $%d\n", cash);
    printf("Total transactions: %d\n", n);
    printf("Total amount: $%d\n", total);

    return 0;
}