//Gemma-7B DATASET v1.0 Category: Sudoku solver ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 9

void solveSudoku(int **board)
{
    int i, j, k;
    int available[MAX_SIZE] = {0};

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (board[i][j] != 0)
            {
                available[board[i][j]] = 1;
            }
        }
    }

    for (i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if (board[i][j] == 0)
            {
                for (k = 0; k < MAX_SIZE; k++)
                {
                    if (available[k] && k != board[i][j])
                    {
                        board[i][j] = k;
                        solveSudoku(board);
                        board[i][j] = 0;
                    }
                }
            }
        }
    }

    return;
}

int main()
{
    int board[MAX_SIZE][MAX_SIZE] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                              {6, 0, 0, 1, 9, 5, 0, 0, 0},
                              {0, 9, 8, 0, 0, 0, 0, 0, 0},
                              {8, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 4},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0},
                              {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    solveSudoku(board);

    for (int i = 0; i < MAX_SIZE; i++)
    {
        for (int j = 0; j < MAX_SIZE; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}