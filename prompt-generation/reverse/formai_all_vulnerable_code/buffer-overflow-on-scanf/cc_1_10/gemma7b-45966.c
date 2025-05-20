//Gemma-7B DATASET v1.0 Category: Table Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define NUM_CARDS 52

int main()
{
    int cards[NUM_CARDS] = {0};
    int i, j, round, bet, winner = 0, pot = 0;

    for (i = 0; i < NUM_CARDS; i++)
    {
        cards[i] = rand() % 13 + 1;
    }

    printf("Welcome to the Crazy Card Game!\n");
    printf("Let's see if you can win a pot of gold!\n");

    round = 1;
    while (winner == 0)
    {
        printf("Round %d: ", round);

        // Place your bets
        printf("Enter your bet: $");
        scanf("%d", &bet);

        // Check if the bet is valid
        if (bet < 1 || bet > pot)
        {
            printf("Invalid bet. Please try again.\n");
            continue;
        }

        // Deal the cards
        for (i = 0; i < 2; i++)
        {
            printf("Card %d: ", cards[i]);
        }

        // Compare the cards and determine the winner
        if (cards[0] == cards[1])
        {
            winner = 1;
            printf("Congratulations! You won $%d!\n", bet);
            pot += bet;
        }
        else
        {
            printf("Sorry, you lost. Better luck next time.\n");
        }

        round++;
    }

    printf("Thank you for playing! The total pot is $%d.\n", pot);

    return 0;
}