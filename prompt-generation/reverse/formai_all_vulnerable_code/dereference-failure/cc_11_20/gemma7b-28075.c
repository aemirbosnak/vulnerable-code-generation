//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WIDTH 50
#define MAX_HEIGHT 50

#define WATER_LEVEL 20

int main()
{
    int **arr;
    int i, j, k, water_cells = 0;

    arr = (int *)malloc(MAX_WIDTH * MAX_HEIGHT * sizeof(int));

    for (i = 0; i < MAX_WIDTH; i++)
    {
        for (j = 0; j < MAX_HEIGHT; j++)
        {
            arr[i][j] = 0;
        }
    }

    srand(time(NULL));

    // Simulate water placement
    for (k = 0; k < WATER_LEVEL; k++)
    {
        i = rand() % MAX_WIDTH;
        j = rand() % MAX_HEIGHT;
        arr[i][j] = 1;
        water_cells++;
    }

    // Percolation process
    for (i = 0; i < MAX_WIDTH; i++)
    {
        for (j = 0; j < MAX_HEIGHT; j++)
        {
            if (arr[i][j] == 1)
            {
                // Check left
                if (i > 0 && arr[i - 1][j] == 0)
                    arr[i - 1][j] = 1;

                // Check right
                if (i < MAX_WIDTH - 1 && arr[i + 1][j] == 0)
                    arr[i + 1][j] = 1;

                // Check up
                if (j > 0 && arr[i][j - 1] == 0)
                    arr[i][j - 1] = 1;

                // Check down
                if (j < MAX_HEIGHT - 1 && arr[i][j + 1] == 0)
                    arr[i][j + 1] = 1;
            }
        }
    }

    // Print the results
    for (i = 0; i < MAX_WIDTH; i++)
    {
        for (j = 0; j < MAX_HEIGHT; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    printf("\nTotal number of water cells: %d", water_cells);

    free(arr);

    return 0;
}