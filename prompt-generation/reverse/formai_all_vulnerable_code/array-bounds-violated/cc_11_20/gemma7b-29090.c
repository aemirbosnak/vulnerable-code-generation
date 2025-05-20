//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: high level of detail
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

    int player_1_color = 1;
    int player_2_color = 2;

    int game_over = 0;

    int move_number = 0;

    // Game Loop
    while (!game_over)
    {
        // Get the player's move
        int row;
        int column;

        printf("Enter the row: ");
        scanf("%d", &row);

        printf("Enter the column: ");
        scanf("%d", &column);

        // Validate the move
        if (board[row][column] != 0)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the piece on the board
        board[row][column] = player_1_color;

        // Increment the move number
        move_number++;

        // Check if the player has won
        if (check_win(board, player_1_color) || move_number == 64)
        {
            game_over = 1;
            printf("Player 1 has won!\n");
        }

        // Switch to the next player
        player_1_color = player_2_color;
        player_2_color = 1 - player_1_color;
    }

    return 0;
}

int check_win(int **board, int color)
{
    // Check rows
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (board[i][j] == color && board[i][j] == board[i][j-1] && board[i][j] == board[i][j-2] && board[i][j] == board[i][j-3])
            {
                return 1;
            }
        }
    }

    // Check columns
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (board[i][j] == color && board[i-1][j] == board[i-2][j] && board[i-3][j] == board[i-4][j] && board[i][j] == board[i-5][j])
            {
                return 1;
            }
        }
    }

    // Check diagonals
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (board[i][j] == color && board[i+1][j+1] == board[i+2][j+2] && board[i+3][j+3] == board[i+4][j+4] && board[i][j] == board[i+5][j+5])
            {
                return 1;
            }
        }
    }

    return 0;
}