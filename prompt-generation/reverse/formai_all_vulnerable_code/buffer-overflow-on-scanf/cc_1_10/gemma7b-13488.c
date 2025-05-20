//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    char board[4][4] = {{0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0},
                              {0, 0, 0, 0}};

    int player_1_turn = 1;
    int game_over = 0;

    // Game Loop
    while (!game_over)
    {
        // Get the player's move
        int row, column;
        printf("Enter row (1-3): ");
        scanf("%d", &row);
        printf("Enter column (1-3): ");
        scanf("%d", &column);

        // Check if the move is valid
        if (board[row][column] != 0)
        {
            printf("Invalid move.\n");
            continue;
        }

        // Place the player's mark on the board
        board[row][column] = player_1_turn;

        // Check if the player has won
        if (check_win(board, player_1_turn))
        {
            game_over = 1;
            printf("Player %d has won!\n", player_1_turn);
        }

        // Switch turns
        player_1_turn *= -1;
    }

    // End Game
    system("clear");
    printf("Thank you for playing! See you next time.\n");

    return 0;
}

int check_win(char **board, int player_1_turn)
{
    // Check rows
    for (int r = 0; r < 4; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] == board[r][3] && board[r][0] == player_1_turn)
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < 4; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] == board[3][c] && board[0][c] == player_1_turn)
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] == board[3][3] && board[0][0] == player_1_turn)
    {
        return 1;
    }

    // If all checks fail, the game is not over
    return 0;
}