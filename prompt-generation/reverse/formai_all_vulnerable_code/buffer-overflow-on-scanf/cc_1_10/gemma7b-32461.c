//Gemma-7B DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_PLAYER 4

int main()
{
    int numPlayers = 0;
    char **players = NULL;
    int playerTurn = 0;
    int rollResult = 0;

    printf("Welcome to the Dice Roller Tournament!\n");

    // Get the number of players
    printf("Enter the number of players (up to %d): ", MAX_PLAYER);
    scanf("%d", &numPlayers);

    // Allocate memory for the players
    players = (char**)malloc(numPlayers * sizeof(char*));
    for (int i = 0; i < numPlayers; i++)
    {
        players[i] = (char*)malloc(20 * sizeof(char));
    }

    // Initialize the players
    for (int i = 0; i < numPlayers; i++)
    {
        printf("Enter the name of player %d: ", i + 1);
        scanf("%s", players[i]);
    }

    // Start the game loop
    while (numPlayers > 0)
    {
        // Determine the player's turn
        playerTurn = (playerTurn + 1) % numPlayers;

        // Get the player's roll result
        rollResult = rollTheDice();

        // Print the player's roll result
        printf("%s rolled a %d.\n", players[playerTurn], rollResult);

        // Check if the player has won
        if (rollResult == 6)
        {
            printf("%s has won the game!\n", players[playerTurn]);
            numPlayers--;
        }
    }

    // Free the memory allocated for the players
    for (int i = 0; i < numPlayers; i++)
    {
        free(players[i]);
    }
    free(players);

    return 0;
}

int rollTheDice()
{
    return rand() % 6 + 1;
}