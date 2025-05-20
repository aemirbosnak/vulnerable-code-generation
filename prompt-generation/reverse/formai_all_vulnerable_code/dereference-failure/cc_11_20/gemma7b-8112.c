//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 9

int main()
{
    int **board = (int **)malloc(N * sizeof(int *)), i, j, k, l, r, c;
    int solved = 0, attempts = 0, seed, rands[N], tmp[N], count = 0;

    for (i = 0; i < N; i++)
    {
        board[i] = (int *)malloc(N * sizeof(int));
        for (j = 0; j < N; j++)
            board[i][j] = 0;
    }

    srand(time(NULL));
    seed = rand() % 1000;
    for (i = 0; i < N; i++)
        rands[i] = seed / 1000 * i + seed % 1000;

    for (l = 0; l < N; l++)
    {
        for (r = 0; r < N; r++)
        {
            for (c = 0; c < N; c++)
            {
                if (board[r][c] == 0)
                {
                    count++;
                    tmp[count] = rands[l] % N;
                }
            }
        }
    }

    for (k = 1; !solved && attempts < 10000; k++)
    {
        attempts++;
        for (i = 0; i < count; i++)
        {
            board[tmp[i]][rands[l] % N] = tmp[i];
        }

        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
            {
                if (board[i][j] == 0)
                {
                    for (l = 0; l < N; l++)
                    {
                        if (board[l][j] != 0 && board[l][j] == board[i][j])
                            board[i][j] = tmp[k];
                    }
                }
            }
        }

        if (check(board))
            solved = 1;
    }

    if (solved)
    {
        printf("Solved! \n");
        for (i = 0; i < N; i++)
        {
            for (j = 0; j < N; j++)
                printf("%d ", board[i][j]);
            printf("\n");
        }
    }
    else
    {
        printf("No solution found.\n");
    }

    return 0;
}

int check(int **board)
{
    for (int i = 0; i < N; i++)
    {
        // Check rows
        for (int j = 0; j < N; j++)
        {
            int num = board[i][j];
            if (num != 0)
            {
                for (int k = 0; k < N; k++)
                {
                    if (board[i][k] != num && board[i][k] != 0)
                        return 0;
                }
            }
        }

        // Check columns
        for (int j = 0; j < N; j++)
        {
            int num = board[j][i];
            if (num != 0)
            {
                for (int k = 0; k < N; k++)
                {
                    if (board[k][i] != num && board[k][i] != 0)
                        return 0;
                }
            }
        }

        // Check 3x3 boxes
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                int sum = 0;
                for (int r = x * 3; r < x * 3 + 3; r++)
                {
                    for (int c = y * 3; c < y * 3 + 3; c++)
                    {
                        sum += board[r][c];
                    }
                }
                if (sum != 9)
                    return 0;
            }
        }
    }
    return 1;
}