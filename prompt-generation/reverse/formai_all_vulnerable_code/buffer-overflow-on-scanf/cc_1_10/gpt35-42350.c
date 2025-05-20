//FormAI DATASET v1.0 Category: Expense Tracker ; Style: happy
#include <stdio.h>
#include <stdbool.h>

#define MAX_EXPENSES 50

int main()
{
    float expenses[MAX_EXPENSES];
    int numExpenses = 0;
    float totalExpenses = 0;
    float averageExpenses = 0;
    bool isHappy = true;

    printf("Welcome to your Expense Tracker!\n");

    while (isHappy && numExpenses < MAX_EXPENSES)
    {
        float expense;

        printf("Enter an expense: ");
        scanf("%f", &expense);

        if (expense == 0)
        {
            isHappy = false;
        }
        else
        {
            expenses[numExpenses] = expense;
            numExpenses++;
            totalExpenses += expense;
        }
    }

    if (numExpenses > 0)
    {
        averageExpenses = totalExpenses / numExpenses;
        printf("\nYou entered %d expenses.\n", numExpenses);
        printf("Your total expenses are $%.2f.\n", totalExpenses);
        printf("Your average expense is $%.2f.\n", averageExpenses);
    }
    else
    {
        printf("\nYou didn't enter any expenses.\n");
    }

    printf("\nThank you for using your Expense Tracker!\n");

    return 0;
}