//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 20

void initialize_grid(int grid[GRID_SIZE][GRID_SIZE], float probability)
{
    srand(time(NULL));
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            float r = (float) rand() / RAND_MAX;
            grid[i][j] = (r < probability) ? 1 : 0;
        }
    }
}

void print_grid(int grid[GRID_SIZE][GRID_SIZE])
{
    for(int i = 0; i < GRID_SIZE; i++)
    {
        for(int j = 0; j < GRID_SIZE; j++)
        {
            char symbol = (grid[i][j] == 1) ? '#' : ' ';
            printf("%c ", symbol);
        }
        printf("\n");
    }
}

int is_percolating(int grid[GRID_SIZE][GRID_SIZE])
{
    int visited[GRID_SIZE][GRID_SIZE] = {0};
    int queue[GRID_SIZE * GRID_SIZE] = {0};
    int front = 0, rear = 0;
    for(int i = 0; i < GRID_SIZE; i++)
    {
        if(grid[0][i] == 1)
        {
            queue[rear++] = i;
            visited[0][i] = 1;
        }
    }
    while(front < rear)
    {
        int current = queue[front++];
        int i = current / GRID_SIZE;
        int j = current % GRID_SIZE;
        if(i == GRID_SIZE - 1)
        {
            return 1;
        }
        if(i-1 >= 0 && visited[i-1][j] == 0 && grid[i-1][j] == 1)
        {
            queue[rear++] = (i-1) * GRID_SIZE + j;
            visited[i-1][j] = 1;
        }
        if(i+1 < GRID_SIZE && visited[i+1][j] == 0 && grid[i+1][j] == 1)
        {
            queue[rear++] = (i+1) * GRID_SIZE + j;
            visited[i+1][j] = 1;
        }
        if(j-1 >= 0 && visited[i][j-1] == 0 && grid[i][j-1] == 1)
        {
            queue[rear++] = i * GRID_SIZE + j-1;
            visited[i][j-1] = 1;
        }
        if(j+1 < GRID_SIZE && visited[i][j+1] == 0 && grid[i][j+1] == 1)
        {
            queue[rear++] = i * GRID_SIZE + j+1;
            visited[i][j+1] = 1;
        }
    }
    return 0;
}

int main()
{
    int grid[GRID_SIZE][GRID_SIZE];
    float probability;
    printf("Enter the probability of a cell being open (0.0 to 1.0): ");
    scanf("%f", &probability);
    initialize_grid(grid, probability);
    printf("\nInitial Configuration:\n");
    print_grid(grid);
    if(is_percolating(grid))
    {
        printf("\nPercolation achieved!\n");
    }
    else
    {
        printf("\nPercolation not achieved!\n");
    }
    return 0;
}