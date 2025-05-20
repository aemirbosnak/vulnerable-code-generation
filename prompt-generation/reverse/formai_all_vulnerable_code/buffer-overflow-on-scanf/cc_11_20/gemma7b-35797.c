//Gemma-7B DATASET v1.0 Category: Table Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0}};

    int player1_piece = 2;
    int player2_piece = 3;

    int game_over = 0;

    // Player 1 turn
    printf("Enter move for player 1 (x, y): ");
    int x1, y1;
    scanf("%d %d", &x1, &y1);

    // Validate move
    if (x1 < 0 || x1 >= 6 || y1 < 0 || y1 >= 6)
    {
        printf("Invalid move!\n");
        return;
    }

    // Place piece on board
    board[x1][y1] = player1_piece;

    // Check if player 1 has won
    if (board[x1][y1] == player1_piece)
    {
        game_over = 1;
    }

    // Player 2 turn
    printf("Enter move for player 2 (x, y): ");
    int x2, y2;
    scanf("%d %d", &x2, &y2);

    // Validate move
    if (x2 < 0 || x2 >= 6 || y2 < 0 || y2 >= 6)
    {
        printf("Invalid move!\n");
        return;
    }

    // Place piece on board
    board[x2][y2] = player2_piece;

    // Check if player 2 has won
    if (board[x2][y2] == player2_piece)
    {
        game_over = 1;
    }

    // Game over
    if (game_over)
    {
        printf("Game over! Winner: ");
        if (board[x1][y1] == player1_piece)
        {
            printf("Player 1\n");
        }
        else if (board[x2][y2] == player2_piece)
        {
            printf("Player 2\n");
        }
    }
    else
    {
        printf("Next turn...\n");
    }

    return;
}