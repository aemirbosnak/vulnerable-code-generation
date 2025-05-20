//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Define the size of our grid
#define GRID_SIZE 20

//Define a function to print the grid
void print_grid(int grid[GRID_SIZE][GRID_SIZE])
{
    //Loop over rows
    for(int i = 0; i < GRID_SIZE; i++)
    {
        //Loop over columns
        for(int j = 0; j < GRID_SIZE; j++)
        {
            //Print current cell
            if(grid[i][j] == 0)
                printf(" ");
            else
                printf("*");
        }
        //Print newline
        printf("\n");
    }
    //Print newline
    printf("\n");
}

//Define a function to check if a cell is percolated
int is_percolated(int grid[GRID_SIZE][GRID_SIZE])
{
    //Loop over top row
    for(int i = 0; i < GRID_SIZE; i++)
    {
        //If cell is open
        if(grid[0][i] == 0)
        {
            //Check if path exists to bottom row
            int visited[GRID_SIZE][GRID_SIZE] = {0};
            visited[0][i] = 1;
            for(int j = 1; j < GRID_SIZE; j++)
            {
                for(int k = 0; k < GRID_SIZE; k++)
                {
                    if(grid[j][k] == 0 && (visited[j-1][k-1] || visited[j-1][k] || visited[j-1][k+1]))
                    {
                        visited[j][k] = 1;
                    }
                    if(j == GRID_SIZE - 1 && visited[j][k])
                        return 1;
                }
            }
        }
    }
    //If no path exists, return 0
    return 0;
}

//Main function
int main()
{
    //Seed RNG
    srand(time(NULL));
    
    //Initialize grid
    int grid[GRID_SIZE][GRID_SIZE] = {0};
    
    //Loop until grid percolates
    while(!is_percolated(grid))
    {
        //Choose random cell
        int i = rand() % GRID_SIZE;
        int j = rand() % GRID_SIZE;
        
        //Perculate cell if it is not already perculated
        if(grid[i][j] == 0)
            grid[i][j] = 1;
    }
    
    //Print final grid
    print_grid(grid);
    
    return 0;
}