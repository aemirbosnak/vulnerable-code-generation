//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void Initialize(int grid[SIZE][SIZE], double threshold);
void Percolate(int grid[SIZE][SIZE]);
void Display(int grid[SIZE][SIZE]);

int main()
{
    int grid[SIZE][SIZE];
    double threshold;

    printf("Percolation Simulator\n");
    printf("---------------------\n");
    printf("Enter the percolation threshold (0.0 - 1.0): ");
    scanf("%lf", &threshold);

    Initialize(grid, threshold);
    Percolate(grid);
    Display(grid);

    return 0;
}

void Initialize(int grid[SIZE][SIZE], double threshold)
{
    srand(time(NULL));
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if ((double)rand() / RAND_MAX < threshold)
                grid[i][j] = 1;
            else
                grid[i][j] = 0;
        }
    }
}

void Percolate(int grid[SIZE][SIZE])
{
    int i, j;
    int top[SIZE], bottom[SIZE];
    int topIndex = 0, bottomIndex = 0;

    for (j = 0; j < SIZE; j++)
    {
        if (grid[0][j] == 1)
            top[topIndex++] = j;
        if (grid[SIZE - 1][j] == 1)
            bottom[bottomIndex++] = j;
    }

    for (i = 0; i < topIndex; i++)
    {
        for (j = 0; j < bottomIndex; j++)
        {
            if (top[i] == bottom[j])
            {
                printf("The system percolates!\n");
                return;
            }
        }
    }

    printf("The system does not percolate.\n");
}

void Display(int grid[SIZE][SIZE])
{
    int i, j;

    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            if (grid[i][j] == 1)
                printf("# ");
            else
                printf(". ");
        }
        printf("\n");
    }
}