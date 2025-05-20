//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i, n, total = 0, choice;
    char name[MAX][20];
    float amount[MAX];

    printf("Welcome to the Expense Tracker!\n");

    // Allocate memory for the data structures
    n = 0;
    while (n < MAX && 1)
    {
        printf("Enter the name of the expense: ");
        scanf("%s", name[n]);

        printf("Enter the amount of the expense: ");
        scanf("%f", &amount[n]);

        n++;
    }

    // Calculate the total expense
    for (i = 0; i < n; i++)
    {
        total += amount[i];
    }

    // Display the total expense
    printf("The total expense is: $%.2f", total);

    // Offer a choice to display detailed expenses
    printf("\nDo you want to see a detailed list of expenses? (Y/N) ");
    scanf(" %c", &choice);

    // Display the detailed expenses
    if (choice == 'Y')
    {
        for (i = 0; i < n; i++)
        {
            printf("Name: %s, Amount: $%.2f\n", name[i], amount[i]);
        }
    }

    return 0;
}