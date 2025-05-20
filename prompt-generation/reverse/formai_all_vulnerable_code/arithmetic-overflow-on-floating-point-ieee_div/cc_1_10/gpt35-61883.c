//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float currentSavings = 0, initialSavings, monthlyIncome, monthlyExpenses;
    float monthlySavings, totalSavings, remainingMonths;
    int savingsGoal, monthsToSave;
    char response;

    printf("Welcome to the Personal Finance Planner!\n\n");

    // Obtaining user inputs
    printf("What is your initial savings amount? ");
    scanf("%f", &initialSavings);

    printf("What is your monthly income? ");
    scanf("%f", &monthlyIncome);

    printf("What are your monthly expenses? ");
    scanf("%f", &monthlyExpenses);

    printf("What is your savings goal? ");
    scanf("%d", &savingsGoal);

    // Calculating savings plan
    monthlySavings = monthlyIncome - monthlyExpenses;
    totalSavings = initialSavings;

    if (monthlySavings < 0)
    {
        printf("\nSorry, your monthly expenses are higher than your income. Please try again.");
    }
    else
    {
        monthsToSave = (savingsGoal - initialSavings) / monthlySavings;

        printf("\nIf you save %.2f per month, you will reach your savings goal of $%d in %d months.\n", monthlySavings, savingsGoal, monthsToSave);

        // Checking if user wants to create a savings plan
        printf("\nWould you like to create a savings plan? (y/n) ");
        scanf(" %c", &response);

        if (response == 'y' || response == 'Y')
        {
            printf("\nHow many months would you like to save for? ");
            scanf("%f", &remainingMonths);

            // Generating the savings plan
            printf("\nMonthly Savings\t\tTotal Savings\n");
            printf("------------------\t\t-------------\n");
            for (int i = 1; i <= remainingMonths; i++)
            {
                currentSavings += monthlySavings;
                totalSavings += monthlySavings;
                printf("$%.2f\t\t\t\t$%.2f\n", monthlySavings, totalSavings);
            }
        }
        else
        {
            printf("Please come back again if you need any help with personal finance planning.\n");
        }
    }
    return 0;
}