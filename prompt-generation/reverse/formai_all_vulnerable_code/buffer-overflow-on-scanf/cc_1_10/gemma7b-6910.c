//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PILES 5

int main()
{
    int piles[MAX_PILES] = {0};
    int player_pile = 0;
    int game_state = 0;

    // Initialize the game
    for (int i = 0; i < MAX_PILES; i++)
    {
        piles[i] = rand() % 10 + 1;
    }

    // Select the player's pile
    player_pile = rand() % MAX_PILES;

    // Start the game loop
    while (game_state != 1)
    {
        // Display the game state
        printf("Piles:\n");
        for (int i = 0; i < MAX_PILES; i++)
        {
            printf("%d ", piles[i]);
        }

        // Get the player's move
        int move = 0;
        printf("\nEnter your move (e.g. 1, 2, 3): ");
        scanf("%d", &move);

        // Validate the move
        if (move < 1 || move > MAX_PILES)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Take the player's move
        piles[player_pile] -= move;

        // Check if the game is over
        for (int i = 0; i < MAX_PILES; i++)
        {
            if (piles[i] == 0)
            {
                game_state = 1;
            }
        }

        // Update the player's pile
        player_pile = (player_pile + 1) % MAX_PILES;
    }

    // Game over
    printf("Game over!\n");

    return 0;
}