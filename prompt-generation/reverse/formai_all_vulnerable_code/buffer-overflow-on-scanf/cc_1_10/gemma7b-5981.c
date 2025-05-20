//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 10

int main()
{
    int num_players = 2;
    int current_player = 0;
    int board[MAX_NUM][MAX_NUM] = {{0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0}};

    // Game setup
    for (int i = 0; i < num_players; i++)
    {
        board[0][i] = i + 1;
    }

    // Game loop
    while (!board[MAX_NUM - 1][current_player])
    {
        // Display the board
        for (int i = 0; i < MAX_NUM; i++)
        {
            for (int j = 0; j < MAX_NUM; j++)
            {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }

        // Get the player's move
        int move = 0;
        printf("Enter your move (1-5): ");
        scanf("%d", &move);

        // Validate the move
        if (move < 1 || move > MAX_NUM)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        board[move - 1][current_player] = 1;

        // Switch to the next player
        current_player = (current_player + 1) % num_players;
    }

    // Game over
    printf("Game over! The winner is player %d.", board[MAX_NUM - 1][current_player]);

    return 0;
}