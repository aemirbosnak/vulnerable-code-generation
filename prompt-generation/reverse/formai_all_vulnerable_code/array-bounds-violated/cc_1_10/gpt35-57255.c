//FormAI DATASET v1.0 Category: Table Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void displayBoard(int board[3][3]);
int checkWinner(int board[3][3]);
void makeMove(int board[3][3], int row, int col, int player);

int main()
{
    int board[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int currentPlayer = 1;
    int row, col;
    int winner = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Display the empty board
    displayBoard(board);

    // Loop until a winner is found or the board is full
    while (winner == 0)
    {
        // Switch players
        currentPlayer = (currentPlayer == 1) ? 2 : 1;

        // Prompt the current player for their move
        printf("Player %d, enter your move (row column): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check if the move is valid
        if (board[row - 1][col - 1] != 0)
        {
            printf("Invalid move, try again.\n");
            continue;
        }

        // Make the current player's move
        makeMove(board, row - 1, col - 1, currentPlayer);

        // Display the updated board
        displayBoard(board);

        // Check if a player has won
        winner = checkWinner(board);

        // If there is a winner, break out of the loop
        if (winner != 0)
        {
            break;
        }

        // Check if the board is full (i.e. a draw)
        int draw = 1;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == 0)
                {
                    draw = 0;
                    break;
                }
            }
            if (!draw)
            {
                break;
            }
        }
        if (draw)
        {
            printf("It's a draw!\n");
            winner = -1;
            break;
        }
    }

    // Display the winner
    switch (winner)
    {
    case 1:
        printf("Player 1 wins!\n");
        break;
    case 2:
        printf("Player 2 wins!\n");
        break;
    case -1:
        printf("It's a draw!\n");
        break;
    }

    return 0;
}

// Function definitions

void displayBoard(int board[3][3])
{
    printf("\n");

    for (int i = 0; i < 3; i++)
    {
        printf(" ");
        for (int j = 0; j < 3; j++)
        {
            switch (board[i][j])
            {
            case 0:
                printf("   ");
                break;
            case 1:
                printf(" X ");
                break;
            case 2:
                printf(" O ");
                break;
            }
            if (j != 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i != 2)
        {
            printf(" -----------\n");
        }
    }

    printf("\n");
}

int checkWinner(int board[3][3])
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return board[0][2];
    }

    // No winner found
    return 0;
}

void makeMove(int board[3][3], int row, int col, int player)
{
    board[row][col] = player;
}