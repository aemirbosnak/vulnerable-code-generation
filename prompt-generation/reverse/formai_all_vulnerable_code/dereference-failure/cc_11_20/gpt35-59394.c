//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));  // initialize random seed

    int size = 10;  // size of grid
    int *grid = calloc(size*size, sizeof(int));  // allocate memory for grid

    // randomly fill grid with 1's and 0's
    for (int i = 0; i < size*size; i++)
    {
        grid[i] = rand() < RAND_MAX / 2 ? 1 : 0;
    }

    int open[size*size];  // array to keep track of open sites
    int open_count = 0;  // number of open sites

    // initialize all sites to be closed
    for (int i = 0; i < size*size; i++)
    {
        open[i] = 0;
    }

    // randomly open sites until there is a percolating path from top to bottom
    while (1)
    {
        int i = rand() % size;
        int j = rand() % size;

        // open site (i, j) if it is not already open
        if (grid[i*size + j] == 0 && !open[i*size + j])
        {
            open[i*size + j] = 1;
            open_count++;

            // check if there is a percolating path from top to bottom
            int percolates = 0;
            for (int k = 0; k < size; k++)
            {
                if (open[k*size] && open[(size-1)*size + k])
                {
                    percolates = 1;
                    break;
                }
            }

            // print out current state of grid
            for (int k = 0; k < size*size; k++)
            {
                if (open[k]) printf("O ");
                else if (grid[k]) printf("# ");
                else printf(". ");
                if ((k+1) % size == 0) printf("\n");
            }

            printf("\n%d open sites\n\n", open_count);
            printf(percolates ? "The grid percolates!\n" : "The grid does not percolate.\n");

            // stop simulation if grid percolates
            if (percolates) break;
        }
    }

    free(grid);  // free memory allocated for grid
    return 0;
}