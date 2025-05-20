//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

void gameOfLife(int **board, int n, int m)
{
    int i, j, k, l;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            int neighbors = 0;
            for (k = -1; k <= 1; k++)
            {
                for (l = -1; l <= 1; l++)
                {
                    if (k == 0 && l == 0)
                        continue;
                    if (i + k >= 0 && i + k < n && j + l >= 0 && j + l < m)
                    {
                        neighbors++;
                        if (board[i + k][j + l] == 2)
                            neighbors++;
                    }
                }
            }
            if (board[i][j] == 1 && neighbors < 2)
                board[i][j] = 0;
            else if (board[i][j] == 0 && neighbors == 2)
                board[i][j] = 1;
        }
    }
    gameOfLife(board, n, m);
}

int main()
{
    int n, m;
    scanf("Enter the number of rows:", &n);
    scanf("Enter the number of columns:", &m);

    int **board = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        board[i] = (int *)malloc(m * sizeof(int));
    }

    // Initialize the board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            board[i][j] = 0;
        }
    }

    // Set the initial state of the board
    board[1][1] = board[2][2] = board[2][3] = 1;

    // Play the game of life
    gameOfLife(board, n, m);

    // Print the final state of the board
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}