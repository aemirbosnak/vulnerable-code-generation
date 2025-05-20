//Gemma-7B DATASET v1.0 Category: Table Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, x, y;
    printf("Enter the number of players:");
    scanf("%d", &n);

    // Allocate memory for the game board
    int **board = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(n * sizeof(int));
    }

    // Initialize the game board
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            board[i][j] = 0;
        }
    }

    // Get the coordinates of the two players
    printf("Enter the coordinates of the first player:");
    scanf("%d %d", &x, &y);

    // Place the first player's piece on the board
    board[x][y] = 1;

    // Get the coordinates of the second player
    printf("Enter the coordinates of the second player:");
    scanf("%d %d", &x, &y);

    // Place the second player's piece on the board
    board[x][y] = 2;

    // Check if the game is over
    if (board[x][y] == 1)
    {
        printf("The first player won!");
    }
    else if (board[x][y] == 2)
    {
        printf("The second player won!");
    }
    else
    {
        printf("It's a draw!");
    }

    // Free the memory allocated for the game board
    for (i = 0; i < n; i++)
    {
        free(board[i]);
    }
    free(board);

    return 0;
}