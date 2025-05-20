//Gemma-7B DATASET v1.0 Category: Table Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM_PLAYER 4

typedef struct Player
{
    char name[20];
    int score;
} Player;

int main()
{
    int numPlayer;
    printf("Enter the number of players (max: %d): ", MAX_NUM_PLAYER);
    scanf("%d", &numPlayer);

    Player players[numPlayer];

    // Initialize players
    for (int i = 0; i < numPlayer; i++)
    {
        players[i].name[0] = '\0';
        players[i].score = 0;
    }

    // Game loop
    while (1)
    {
        // Roll the dice
        int roll = rand() % 6 + 1;

        // Calculate the player's turn
        for (int i = 0; i < numPlayer; i++)
        {
            // Check if the player is active
            if (players[i].score > 0)
            {
                // Calculate the player's move
                int move = roll + players[i].score;

                // Check if the player has won
                if (move >= MAX_NUM_PLAYER)
                {
                    players[i].score = MAX_NUM_PLAYER;
                    printf("%s has won the game!\n", players[i].name);
                }
                else
                {
                    // Update the player's score
                    players[i].score += move;
                    printf("%s has rolled a %d and has a total score of %d.\n", players[i].name, roll, players[i].score);
                }
            }
        }

        // Check if the game is over
        if (numPlayer - 1 == players[0].score)
        {
            printf("The game is over.\n");
            break;
        }

        // Pause the game
        printf("Press any key to continue...");
        getchar();
    }

    return 0;
}