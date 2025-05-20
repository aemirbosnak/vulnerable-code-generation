//Gemma-7B DATASET v1.0 Category: Percolation Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main()
{
    // Create a 2D array to store the water levels
    int **water_level = (int **)malloc(ROWS * sizeof(int *));
    for (int r = 0; r < ROWS; r++)
    {
        water_level[r] = (int *)malloc(COLS * sizeof(int));
    }

    // Initialize the water levels
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            water_level[r][c] = 0;
        }
    }

    // Seed the random number generator
    srand(time(NULL));

    // Simulate water flow
    for (int t = 0; t < 1000; t++)
    {
        // Randomly select a cell
        int r = rand() % ROWS;
        int c = rand() % COLS;

        // If the cell is not already full and there is water flowing into it
        if (water_level[r][c] == 0 && water_level[r - 1][c] > 0)
        {
            // Fill the cell
            water_level[r][c] = 1;

            // Spread the water to neighboring cells
            if (r - 1 >= 0) water_level[r - 1][c]--;
            if (r + 1 < ROWS) water_level[r + 1][c]--;
            if (c - 1 >= 0) water_level[r][c - 1]--;
            if (c + 1 < COLS) water_level[r][c + 1]--;
        }
    }

    // Print the water levels
    for (int r = 0; r < ROWS; r++)
    {
        for (int c = 0; c < COLS; c++)
        {
            printf("%d ", water_level[r][c]);
        }
        printf("\n");
    }

    // Free the memory allocated for the water level array
    for (int r = 0; r < ROWS; r++)
    {
        free(water_level[r]);
    }
    free(water_level);

    return 0;
}