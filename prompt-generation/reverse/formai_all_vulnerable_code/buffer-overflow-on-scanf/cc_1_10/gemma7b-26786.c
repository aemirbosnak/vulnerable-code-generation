//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int main()
{
    // Game board
    int board[MAX_SIZE][MAX_SIZE] = {{0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0},
                                 {0, 0, 0, 0, 0}};

    // Player's move
    int move_row, move_col;

    // Game loop
    while (1)
    {
        // Display the game board
        for (int r = 0; r < MAX_SIZE; r++)
        {
            for (int c = 0; c < MAX_SIZE; c++)
            {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }

        // Get the player's move
        printf("Enter row: ");
        scanf("%d", &move_row);

        printf("Enter column: ");
        scanf("%d", &move_col);

        // Validate the move
        if (move_row < 0 || move_row >= MAX_SIZE)
        {
            printf("Invalid row.\n");
        }
        else if (move_col < 0 || move_col >= MAX_SIZE)
        {
            printf("Invalid column.\n");
        }
        else if (board[move_row][move_col] != 0)
        {
            printf("Position already occupied.\n");
        }
        else
        {
            // Place the player's piece on the board
            board[move_row][move_col] = 1;

            // Check if the player has won
            if (check_win(board, move_row, move_col))
            {
                printf("You have won!\n");
                break;
            }
            // If there are no more moves, it's a draw
            else if (is_board_full(board))
            {
                printf("It's a draw.\n");
                break;
            }
        }
    }

    return 0;
}

// Function to check if the player has won
int check_win(int **board, int move_row, int move_col)
{
    // Check rows
    for (int r = 0; r < MAX_SIZE; r++)
    {
        if (board[r][move_col] == 1 && board[r][move_col] == board[move_row][move_col] && board[r][move_col] == board[move_row][move_col])
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < MAX_SIZE; c++)
    {
        if (board[move_row][c] == 1 && board[move_row][c] == board[move_row][move_col] && board[move_row][c] == board[move_row][move_col])
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[move_row][move_col] == 1 && board[move_row][move_col] == board[move_row - 1][move_col + 1] && board[move_row][move_col] == board[move_row + 1][move_col - 1])
    {
        return 1;
    }

    return 0;
}

// Function to check if the board is full
int is_board_full(int **board)
{
    for (int r = 0; r < MAX_SIZE; r++)
    {
        for (int c = 0; c < MAX_SIZE; c++)
        {
            if (board[r][c] == 0)
            {
                return 0;
            }
        }
    }

    return 1;
}