//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **board = NULL;
    int rows, cols;
    int i, j, k, l;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    board = (int **)malloc(rows * sizeof(int *));
    for (i = 0; i < rows; i++)
    {
        board[i] = (int *)malloc(cols * sizeof(int));
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter the initial state of the cell (0/1): ");
            scanf("%d", &board[i][j]);
        }
    }

    for (k = 0; k < 5; k++)
    {
        for (l = 0; l < 5; l++)
        {
            int neighbors = 0;
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    if (board[i][j] == 1 && (i == k || j == l))
                    {
                        neighbors++;
                    }
                }
            }

            if (board[k][l] == 1 && neighbors < 2)
            {
                board[k][l] = 0;
            }
            else if (board[k][l] == 0 && neighbors == 2)
            {
                board[k][l] = 1;
            }
        }
    }

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("The state of the cell after %d iterations: %d\n", k, board[i][j]);
        }
    }

    return 0;
}