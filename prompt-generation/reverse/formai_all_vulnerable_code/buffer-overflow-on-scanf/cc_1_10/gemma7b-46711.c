//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    int score = 0, lives = 3;
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

    // Game loop
    while (lives > 0)
    {
        // Display the board
        for (int r = 0; r < 3; r++)
        {
            for (int c = 0; c < 3; c++)
            {
                printf("%c ", board[r][c]);
            }
            printf("\n");
        }

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

        // Place the player's piece on the board
        board[move / 3][move % 3] = 'X';

        // Check if the player has won or lost
        if (checkWin(board) || checkLoss(board))
        {
            break;
        }

        // Increment the score
        score++;

        // End of the turn
        printf("End of turn.\n");
    }

    // Game over message
    system("clear");
    printf("Game over! Your score is: %d", score);

    return 0;
}

// Function to check if the player has won
int checkWin(char board[][3])
{
    // Check rows
    for (int r = 0; r < 3; r++)
    {
        if (board[r][0] == board[r][1] && board[r][0] == board[r][2] && board[r][0] != ' ')
        {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < 3; c++)
    {
        if (board[0][c] == board[1][c] && board[0][c] == board[2][c] && board[0][c] != ' ')
        {
            return 1;
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != ' ')
    {
        return 1;
    }

    // No winner
    return 0;
}

// Function to check if the player has lost
int checkLoss(char board[][3])
{
    // Check if the board is full
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < 3; c++)
        {
            if (board[r][c] == ' ')
            {
                return 0;
            }
        }
    }

    // No moves left, loss
    return 1;
}