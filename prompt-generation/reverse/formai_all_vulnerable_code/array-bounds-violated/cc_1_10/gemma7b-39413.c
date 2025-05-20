//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_ROLLS 5

int main()
{
    int numPlayers = 2;
    int rollsPerPlayer = 3;
    int playerTurn = 0;
    int totalSum = 0;
    int currentRoll = 0;
    int diceRoll[MAX_ROLLS];

    // Initialize the game
    for (int i = 0; i < numPlayers; i++)
    {
        diceRoll[i] = 0;
    }

    // Begin the game loop
    while (totalSum < 200)
    {
        // Roll the dice for the current player
        for (int i = 0; i < rollsPerPlayer; i++)
        {
            diceRoll[playerTurn] = rand() % 6 + 1;
        }

        // Calculate the total sum for the current player
        currentRoll = 0;
        for (int i = 0; i < rollsPerPlayer; i++)
        {
            currentRoll += diceRoll[playerTurn];
        }

        // Add the current roll to the total sum
        totalSum += currentRoll;

        // Increment the player's turn
        playerTurn++;

        // Print the results of the roll
        printf("Player %d rolled a total of %d.\n", playerTurn, currentRoll);
    }

    // End the game
    printf("The game is over. The total sum is %d.\n", totalSum);

    return 0;
}