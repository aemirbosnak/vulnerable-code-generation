//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10                 // Number of Rows and Columns in Grid

int grid[N][N] = {0};         // Initializing Grid with all blocked cells

void print_grid()             // Function to print current grid
{
    printf("\nCurrent Grid:\n");

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j] == 0)
                printf("# ");
            else
                printf("O ");
        }
        printf("\n");
    }
}

int is_percolated()           // Function to check if perlocation is achieved
{
    int top_row[N] = {0};        // Initializing top_row array with all 0s

    for(int i=0; i<N; i++)
    {
        if(grid[0][i] == 1)         // Checking if cells in top row are open (1)
            top_row[i] = 1;
    }

    for(int i=1; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            if(grid[i][j] == 1)      // Checking all open cells (1)
            {
                if(j>0 && top_row[j-1])    // Check left cell
                    top_row[j] = 1;
                if(top_row[j])             // Check right cell
                    top_row[j] = 1;
                if(j<N-1 && top_row[j+1])  // Check right cell
                    top_row[j] = 1;
            }
        }
    }

    for(int i=0; i<N; i++)
        if(top_row[i] == 1)         // Checking if bottom row has open (1) cell
            return 1;

    return 0;                       // Percolation not yet achieved
}

void percolation(int p)          // Function to simulate percolation with p probability
{
    srand(time(NULL));                  // Initializing random generator

    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int r = rand()%100;         // Generating random number between 0-99
            if(r < p*100)               // Checking for probability
                grid[i][j] = 1;         // Open cell (1)
        }
    }
}

int main()
{
    print_grid();

    int p;
    printf("\nEnter Probability for Percolation (0-1): ");
    scanf("%lf", &p);

    percolation(p);
    print_grid();

    if(is_percolated())
        printf("\nPercolation Achieved!\n");
    else
        printf("\nPercolation Not Achieved!\n");

    return 0;
}