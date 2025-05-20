//Gemma-7B DATASET v1.0 Category: Table Game ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int board[6][6] = {{0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0}};

    int player1_turn = 1;
    int player1_piece = 1;
    int player2_turn = 0;
    int player2_piece = 2;

    // Game loop
    while (board[5][5] == 0)
    {
        // Player 1's turn
        printf("It is player 1's turn.\n");
        printf("Enter the row and column of the piece you want to move (e.g. 2 3): ");
        int row1, col1;
        scanf("%d %d", &row1, &col1);

        // Validate move
        if (board[row1][col1] == 0 || board[row1][col1] != player1_piece)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Move piece
        board[row1][col1] = 0;
        board[row1][col1] = player1_piece;

        // Player 2's turn
        player1_turn = 0;
        player2_turn = 1;
        player2_piece = 2;

        // Same steps as above for player 2
        printf("It is player 2's turn.\n");
        printf("Enter the row and column of the piece you want to move (e.g. 2 3): ");
        int row2, col2;
        scanf("%d %d", &row2, &col2);

        // Validate move
        if (board[row2][col2] == 0 || board[row2][col2] != player2_piece)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Move piece
        board[row2][col2] = 0;
        board[row2][col2] = player2_piece;

        // Check if player 1 has won
        if (board[5][5] == player1_piece)
        {
            printf("Player 1 has won!\n");
            break;
        }

        // Check if player 2 has won
        else if (board[5][5] == player2_piece)
        {
            printf("Player 2 has won!\n");
            break;
        }
    }

    // Game over
    printf("Game over.\n");

    return 0;
}