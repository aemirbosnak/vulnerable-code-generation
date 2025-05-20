//Gemma-7B DATASET v1.0 Category: Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
    int i, j, n, m;
    char board[MAX][MAX];

    // Initialize the board
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            board[i][j] = ' ';
        }
    }

    // Get the number of players
    printf("Enter the number of players (2-4): ");
    scanf("%d", &n);

    // Get the number of moves
    printf("Enter the number of moves: ");
    scanf("%d", &m);

    // Make the moves
    for (i = 0; i < m; i++)
    {
        int row, column;

        printf("Enter the row and column of the move: ");
        scanf("%d %d", &row, &column);

        // Check if the move is valid
        if (row < 0 || row >= MAX || column < 0 || column >= MAX || board[row][column] != ' ')
        {
            printf("Invalid move.\n");
            i--;
        }
        else
        {
            board[row][column] = 'X';
        }
    }

    // Print the board
    for (i = 0; i < MAX; i++)
    {
        for (j = 0; j < MAX; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Check if the player won
    for (i = 0; i < MAX; i++)
    {
        // Check if the player won in a row
        for (j = 0; j < MAX; j++)
        {
            if (board[i][j] == 'X' && board[i][0] == board[i][MAX - 1] && board[i][0] != ' ')
            {
                printf("Player %d won!\n", n);
                return 0;
            }
        }

        // Check if the player won in a column
        for (j = 0; j < MAX; j++)
        {
            if (board[0][j] == 'X' && board[MAX - 1][j] == board[0][j] && board[0][j] != ' ')
            {
                printf("Player %d won!\n", n);
                return 0;
            }
        }

        // Check if the player won in a diagonal
        if (board[0][0] == 'X' && board[MAX - 1][MAX - 1] == board[0][MAX - 1] && board[0][0] != ' ')
        {
            printf("Player %d won!\n", n);
            return 0;
        }
    }

    // If there is no winner, print a draw
    printf("Draw!\n");

    return 0;
}