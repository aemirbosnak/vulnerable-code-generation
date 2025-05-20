//Gemma-7B DATASET v1.0 Category: Table Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, j, k, l, m, p, q;
    printf("Enter the number of players: ");
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

    // Set up the players' moves
    printf("Enter the moves of each player (separated by commas): ");
    scanf("%d", &l);

    // Make the players' moves
    for (i = 0; i < l; i++)
    {
        scanf("%d %d", &m, &p);
        board[m][p] = 1;
    }

    // Check if any player has won
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (board[i][j] == n)
            {
                printf("Player %d has won!", i + 1);
                return 0;
            }
        }
    }

    // If no one has won, it's a draw
    printf("It's a draw!");
    return 0;
}