//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int **grid = NULL;
    int rows = 0, cols = 0;
    char ch;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    grid = (int**)malloc(rows * sizeof(int*));
    for (int r = 0; r < rows; r++)
    {
        grid[r] = (int*)malloc(cols * sizeof(int));
    }

    printf("Enter the initial state of the grid (O for alive, X for dead): ");
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < cols; c++)
        {
            scanf("%c", &ch);
            grid[r][c] = (ch == 'O')? 1 : 0;
        }
    }

    for (int t = 0; t < 10; t++)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                int neighbors = 0;
                if (r - 1 >= 0) neighbors++;
                if (r + 1 < rows) neighbors++;
                if (c - 1 >= 0) neighbors++;
                if (c + 1 < cols) neighbors++;

                if (grid[r][c] == 1 && neighbors < 2) grid[r][c] = 0;
                if (grid[r][c] == 0 && neighbors == 3) grid[r][c] = 1;
            }
        }

        printf("State at t = %d:\n", t);
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                printf("%c ", grid[r][c] == 1? 'O' : 'X');
            }
            printf("\n");
        }
    }

    return 0;
}