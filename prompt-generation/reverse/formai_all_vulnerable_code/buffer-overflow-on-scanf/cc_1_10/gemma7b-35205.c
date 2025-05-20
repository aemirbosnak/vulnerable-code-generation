//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int main()
{
    int board[MAX_SIZE][MAX_SIZE] = { 0 };
    int player_1_pos = 0, player_2_pos = MAX_SIZE - 1, turn = 0;

    // Initialize the board
    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            board[i][j] = 0;
        }
    }

    // Place the initial pieces
    board[player_1_pos][player_1_pos] = 1;
    board[player_2_pos][player_2_pos] = 2;

    // Game loop
    while (!board[player_1_pos][player_2_pos])
    {
        // Get the player's move
        int move = 0;
        printf("Enter your move (1-9): ");
        scanf("%d", &move);

        // Validate the move
        if (move < 1 || move > 9)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Make the move
        switch (turn)
        {
            case 0:
                player_1_pos = move - 1;
                board[player_1_pos][player_1_pos] = 1;
                break;
            case 1:
                player_2_pos = move - 1;
                board[player_2_pos][player_2_pos] = 2;
                break;
        }

        // Check if the game is over
        if (board[player_1_pos][player_2_pos] != 0)
        {
            printf("Game over! Player %d won.\n", board[player_1_pos][player_2_pos]);
            break;
        }

        // Switch turns
        turn = (turn + 1) % 2;
    }

    return 0;
}