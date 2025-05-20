//FormAI DATASET v1.0 Category: Table Game ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); // initialize random seed

    int playerCount; // number of players
    printf("Enter number of players: ");
    scanf("%d", &playerCount);

    int tableSize; // size of table
    printf("Enter size of table: ");
    scanf("%d", &tableSize);

    int playerPos[playerCount]; // array of player positions
    for (int i = 0; i < playerCount; i++)
    {
        playerPos[i] = 0;
    }

    int diceRoll; // the result of rolling the dice

    int currentPlayer = 0; // index of current player
    while (1)
    {
        printf("Player %d's turn:\n", currentPlayer+1);
        printf("Press enter to roll dice...");
        getchar();
        diceRoll = (rand() % 6) + 1; // roll the dice
        printf("Dice roll: %d\n", diceRoll);

        // check if player goes out of bounds
        if (playerPos[currentPlayer] + diceRoll >= tableSize)
        {
            printf("Player %d has won!\n", currentPlayer+1);
            break;
        }

        // update player's position
        playerPos[currentPlayer] += diceRoll;

        // check if player lands on a special tile
        switch (playerPos[currentPlayer])
        {
            case 3:
                printf("Player %d landed on a ladder! Going up to tile 15!\n", currentPlayer+1);
                playerPos[currentPlayer] = 15;
                break;
            case 7:
                printf("Player %d landed on a snake! Going down to tile 4!\n", currentPlayer+1);
                playerPos[currentPlayer] = 4;
                break;
            case 11:
                printf("Player %d landed on a ladder! Going up to tile 25!\n", currentPlayer+1);
                playerPos[currentPlayer] = 25;
                break;
            case 20:
                printf("Player %d landed on a snake! Going down to tile 9!\n", currentPlayer+1);
                playerPos[currentPlayer] = 9;
                break;
            case 24:
                printf("Player %d landed on a ladder! Going up to tile 35!\n", currentPlayer+1);
                playerPos[currentPlayer] = 35;
                break;
            case 29:
                printf("Player %d landed on a snake! Going down to tile 12!\n", currentPlayer+1);
                playerPos[currentPlayer] = 12;
                break;
        }

        // print the state of the game
        printf("State of the game:\n");
        for (int i = 0; i < playerCount; i++)
        {
            printf("Player %d is on tile %d\n", i+1, playerPos[i]);
        }
        printf("\n");

        // move on to next player
        currentPlayer++;
        if (currentPlayer == playerCount)
        {
            currentPlayer = 0;
        }
    }

    return 0;
}