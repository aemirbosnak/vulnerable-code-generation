//FormAI DATASET v1.0 Category: Expense Tracker ; Style: funny
#include <stdio.h>

int main()
{
    int numTransactions;
    float totalExpense = 0;
    printf("Welcome to the Expense Tracker!\nHow many transactions did you make today? ");
    scanf("%d", &numTransactions);

    if(numTransactions == 0)
    {
        printf("What? Did you forget your wallet at home or something?\n");
    }
    else if(numTransactions < 0)
    {
        printf("Negative transactions? You must be a bank!\n");
    }
    else
    {
        for(int i = 1; i <= numTransactions; i++)
        {
            float expense;
            printf("Transaction #%d: $", i);
            scanf("%f", &expense);
            if(expense < 0)
            {
                printf("What kind of sorcery is this? A negative expense?\n");
                continue;
            }
            totalExpense += expense;
        }

        printf("\n----------------------\n");
        printf("Total expense: $%.2f\n", totalExpense);

        if(totalExpense > 200)
        {
            printf("Wow, you really went all out today! Did you win the lottery or something?\n");
        }
        else if(totalExpense > 100)
        {
            printf("Looks like someone's treating themselves today!\n");
        }
        else if(totalExpense < 50)
        {
            printf("Saving up for something big, eh? Keep it up!\n");
        }
        else
        {
            printf("Just an ordinary day, spending-wise.\n");
        }
    }

    return 0;
}