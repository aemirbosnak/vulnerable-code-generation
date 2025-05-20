//FormAI DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLS 30

int grid[ROWS][COLS];
int tempGrid[ROWS][COLS];

/* Function to initialize the grid randomly */
void initializeGrid()
{
    int i, j;
    srand(time(NULL));
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            grid[i][j] = rand()%2;
        }
    }
}

/* Function to print the grid */
void printGrid()
{
    int i, j;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            if(grid[i][j] == 0)
                printf(".");
            else
                printf("*");
        }
        printf("\n");
    }
}

/* Function to get the neighbor count of a cell */
int getNeighborCount(int row, int col)
{
    int count = 0;
    if(row > 0 && col > 0 && grid[row-1][col-1] == 1)
        count++;
    if(row > 0 && grid[row-1][col] == 1)
        count++;
    if(row > 0 && col < COLS-1 && grid[row-1][col+1] == 1)
        count++;
    if(col > 0 && grid[row][col-1] == 1)
        count++;
    if(col < COLS-1 && grid[row][col+1] == 1)
        count++;
    if(row < ROWS-1 && col > 0 && grid[row+1][col-1] == 1)
        count++;
    if(row < ROWS-1 && grid[row+1][col] == 1)
        count++;
    if(row < ROWS-1 && col < COLS-1 && grid[row+1][col+1] == 1)
        count++;
    return count;
}

/* Function to update the state of the grid for the next generation */
void updateGrid()
{
    int i, j, count;
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            count = getNeighborCount(i, j);
            if(grid[i][j] == 1)
            {
                if(count < 2 || count > 3)
                    tempGrid[i][j] = 0;
                else
                    tempGrid[i][j] = 1;
            }
            else
            {
                if(count == 3)
                    tempGrid[i][j] = 1;
                else
                    tempGrid[i][j] = 0;
            }
        }
    }

    /* Copy the updated grid to the original grid */
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            grid[i][j] = tempGrid[i][j];
        }
    }
}

/* Main function */
int main()
{
    int gens, i;
    printf("Enter the number of generations: ");
    scanf("%d", &gens);
    initializeGrid();
    for(i=1; i<=gens; i++)
    {
        printf("Generation %d:\n", i);
        printGrid();
        updateGrid();
    }
    return 0;
}