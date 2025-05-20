//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define two players
    char player1[20];
    char player2[20];

    // Get players' names
    printf("Enter player 1's name: ");
    scanf("%s", player1);

    printf("Enter player 2's name: ");
    scanf("%s", player2);

    // Initialize shared expense list
    int expenseList[100] = {0};
    int listSize = 0;

    // Main game loop
    while (1)
    {
        // Get expense amount
        int expenseAmount = 0;
        printf("%s, enter the expense amount: ", player1);
        scanf("%d", &expenseAmount);

        // Check if expense is valid
        if (expenseAmount < 0)
        {
            printf("Invalid expense amount. Please try again.\n");
            continue;
        }

        // Add expense to list
        expenseList[listSize++] = expenseAmount;

        // Calculate total expense
        int totalExpense = 0;
        for (int i = 0; i < listSize; i++)
        {
            totalExpense += expenseList[i];
        }

        // Print total expense
        printf("Total expense: $%d\n", totalExpense);

        // Check if players want to continue
        char continueChoice;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continueChoice);

        // Break out of loop if players do not want to continue
        if (continueChoice != 'Y')
        {
            break;
        }
    }

    // Print final summary
    printf("Thank you for playing, %s and %s. See you next time!\n", player1, player2);

    return 0;
}