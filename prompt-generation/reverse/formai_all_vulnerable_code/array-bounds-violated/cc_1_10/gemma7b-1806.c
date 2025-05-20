//Gemma-7B DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                           {0, 1, 0, 0, 0, 0},
                           {0, 0, 2, 0, 0, 0},
                           {0, 0, 0, 3, 0, 0},
                           {0, 0, 0, 0, 4, 0},
                           {0, 0, 0, 0, 0, 5}};

    int player_1_move = 0;
    int player_2_move = 0;

    // Game loop
    while (board[player_1_move][player_2_move] != 6)
    {
        // Get player 1's move
        printf("Enter player 1's move (x, y): ");
        scanf("%d %d", &player_1_move, &player_2_move);

        // Validate move
        if (board[player_1_move][player_2_move] != 0)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place piece on the board
        board[player_1_move][player_2_move] = 1;

        // Get player 2's move
        printf("Enter player 2's move (x, y): ");
        scanf("%d %d", &player_1_move, &player_2_move);

        // Validate move
        if (board[player_1_move][player_2_move] != 0)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place piece on the board
        board[player_1_move][player_2_move] = 2;
    }

    // Game over
    printf("Game over! Player %d won!", board[player_1_move][player_2_move]);

    return 0;
}