//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SIZE 50

int main()
{
    printf("Welcome to the Percolation Simulator!\n\n");

    // initialization
    srand(time(NULL));
    int N, open_count = 0;
    printf("Please enter the size of the grid (between 1 and %d): ", MAX_SIZE);
    scanf("%d", &N);

    bool grid[MAX_SIZE][MAX_SIZE];
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            grid[i][j] = false;

    // random opening of sites
    while(!grid[0][N-1])  // check if the right corner site percolates
    {
        int i = rand() % N;
        int j = rand() % N;
        if(!grid[i][j])
        {
            grid[i][j] = true;
            open_count++;
        }
    }

    // output results
    printf("\nSuccessfully opened %d sites.\n\n", open_count);
    printf("The grid looks like:\n\n");
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(grid[i][j])
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }

    // wait for user input
    getchar();
    return 0;
}