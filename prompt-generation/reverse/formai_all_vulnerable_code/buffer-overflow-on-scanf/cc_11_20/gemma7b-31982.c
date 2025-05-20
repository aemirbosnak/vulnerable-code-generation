//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: minimalist
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

    int player = 1;
    int game_over = 0;

    // Game loop
    while (!game_over)
    {
        // Get player's move
        int move_x, move_y;
        printf("Enter move (x, y): ");
        scanf("%d %d", &move_x, &move_y);

        // Validate move
        if (move_x < 0 || move_x >= 6)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }
        if (move_y < 0 || move_y >= 6)
        {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Place piece
        board[move_x][move_y] = player;

        // Check if game is over
        game_over = check_game_over(board, player);

        // Switch player
        player = (player == 1) ? 2 : 1;
    }

    // Game over message
    printf("Game over! The winner is: ");
    printf((board[0][0] == 1) ? "Player 1" : "Player 2");
    return 0;
}

int check_game_over(int **board, int player)
{
    // Check rows
    for (int i = 0; i < 6; i++)
    {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player && board[3][i] == player && board[4][i] == player && board[5][i] == player)
        {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 6; j++)
    {
        if (board[j][0] == player && board[j][1] == player && board[j][2] == player && board[j][3] == player && board[j][4] == player && board[j][5] == player)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player && board[3][3] == player && board[4][4] == player && board[5][5] == player)
    {
        return 1;
    }

    // Check if board is full
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (board[i][j] == 0)
            {
                return 0;
            }
        }
    }

    // No winner or full board
    return 0;
}