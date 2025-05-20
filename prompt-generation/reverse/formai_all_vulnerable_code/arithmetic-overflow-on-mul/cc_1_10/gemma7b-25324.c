//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i, n, choice, budget, total = 0;
    char name[MAX];

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Welcome, %s. Let's plan your budget!\n", name);

    printf("How many categories do you want to budget for? ");
    scanf("%d", &n);

    int categories[n];
    char category[n][MAX];

    for (i = 0; i < n; i++)
    {
        printf("Enter the name of category %d: ", i + 1);
        scanf("%s", category[i]);

        printf("Enter the budget for category %d: ", i + 1);
        scanf("%d", &categories[i]);
    }

    printf("Please enter your total monthly income: ");
    scanf("%d", &budget);

    for (i = 0; i < n; i++)
    {
        total += categories[i];
    }

    if (total > budget)
    {
        printf("Your total budget exceeds your income. Please re-enter your categories and budget.\n");
    }
    else
    {
        printf("Your budget is within your income. You can allocate your funds as follows:\n");

        for (i = 0; i < n; i++)
        {
            printf("%s: %.2f%% of your income\n", category[i], (categories[i] / total) * 100);
        }

        printf("Your remaining income is: %.2f%% of your income\n", (budget - total) * 100 / budget);
    }

    return 0;
}