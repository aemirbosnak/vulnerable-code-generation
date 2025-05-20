//Gemma-7B DATASET v1.0 Category: Game of Life ; Style: happy
#include <stdio.h>
#include <stdlib.h>

#define MAX_CELLS 20

int main()
{
    int **cells = (int **)malloc(MAX_CELLS * sizeof(int *));
    for(int i = 0; i < MAX_CELLS; i++)
    {
        cells[i] = (int *)malloc(MAX_CELLS * sizeof(int));
    }

    int x, y;
    printf("Enter the number of rows: ");
    scanf("%d", &x);
    printf("Enter the number of columns: ");
    scanf("%d", &y);

    printf("Enter the initial state of the cells (0 for dead, 1 for alive):\n");
    for(int r = 0; r < x; r++)
    {
        for(int c = 0; c < y; c++)
        {
            scanf("%d", &cells[r][c]);
        }
    }

    // Game loop
    for(int t = 0; t < 10; t++)
    {
        for(int r = 0; r < x; r++)
        {
            for(int c = 0; c < y; c++)
            {
                int alive = 0;
                // Check the neighbors
                if(cells[r-1][c] == 1) alive++;
                if(cells[r+1][c] == 1) alive++;
                if(cells[r][c-1] == 1) alive++;
                if(cells[r][c+1] == 1) alive++;

                // Apply the rules
                if(cells[r][c] == 1 && alive < 2) cells[r][c] = 0;
                if(cells[r][c] == 0 && alive == 3) cells[r][c] = 1;
            }
        }
    }

    // Print the final state of the cells
    printf("The final state of the cells is:\n");
    for(int r = 0; r < x; r++)
    {
        for(int c = 0; c < y; c++)
        {
            printf("%d ", cells[r][c]);
        }
        printf("\n");
    }

    // Free the memory
    for(int i = 0; i < MAX_CELLS; i++)
    {
        free(cells[i]);
    }
    free(cells);

    return 0;
}