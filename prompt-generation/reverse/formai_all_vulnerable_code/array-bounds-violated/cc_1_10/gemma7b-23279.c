//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char board[6][6] = {{0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0}};

    int player1_piece = 1;
    int player2_piece = 2;

    int game_turn = 0;

    // Game loop
    while (!board[3][3] && game_turn < 20)
    {
        // Get player move
        int row, column;
        printf("Enter row: ");
        scanf("%d", &row);
        printf("Enter column: ");
        scanf("%d", &column);

        // Validate move
        if (board[row][column] != 0)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place piece
        board[row][column] = player1_piece;

        // Change turn
        game_turn++;

        // Show board
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                printf("%c ", board[i][j]);
            }
            printf("\n");
        }

        // Check if player 1 has won
        if (board[3][3] == player1_piece)
        {
            printf("Player 1 has won!\n");
            break;
        }
    }

    // Game over
    if (game_turn == 20)
    {
        printf("Game over.\n");
    }

    return 0;
}