//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_N 50    // maximum grid size
#define PROB 0.6    // probability of site being open

int grid[MAX_N][MAX_N]; // grid
int size;               // size of grid

// function to initialize grid
void init_grid()
{
    srand(time(NULL));  // set random seed
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if((double)rand()/RAND_MAX < PROB){
                grid[i][j] = 1;
            } else {
                grid[i][j] = 0;
            }
        }
    }
}

// function to print grid
void print_grid()
{
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            printf("%c ", grid[i][j] == 1 ? '#' : '.');
        }
        printf("\n");
    }
}

// function to check if percolation occurs
int does_percolate()
{
    int visited[MAX_N][MAX_N] = {0};    // visited array
    for(int i=0;i<size;i++){
        if(grid[0][i] == 1){    // if top row site is open
            visited[0][i] = 1;  // mark site as visited
            for(int j=0;j<size;j++){
                if(visited[size-1][j]){ // if bottom row site is open and already visited
                    return 1;           // percolation occurs
                }
            }
            // check neighbors of site
            if(i-1 >= 0 && grid[0][i-1] == 1 && !visited[0][i-1]){
                visited[0][i-1] = 1;
            }
            if(i+1 <= size-1 && grid[0][i+1] == 1 && !visited[0][i+1]){
                visited[0][i+1] = 1;
            }
            if(grid[1][i] == 1 && !visited[1][i]){
                visited[1][i] = 1;
            }
        }
    }
    return 0;   // percolation does not occur
}

int main()
{
    printf("My love, let us run a percolation simulation together...\n");
    printf("Imagine our love as a grid with open and closed sites. \n");
    printf("Each open site on the top row represents our love for each other.\n");
    printf("Let me show you how it works...\n\n");

    printf("Enter size of grid between 5 and 50: ");
    scanf("%d", &size);

    init_grid();    // initialize grid

    printf("\nHere is our love grid...\n\n");
    print_grid();   // print grid

    if(does_percolate()){
        printf("\nOur love percolates! We are meant to be together!\n");
    } else {
        printf("\nOur love does not percolate... but that's okay, we will still be together!\n");
    }

    printf("\nThank you for running this simulation with me. I love you more than anything in this world.\n");
    return 0;
}