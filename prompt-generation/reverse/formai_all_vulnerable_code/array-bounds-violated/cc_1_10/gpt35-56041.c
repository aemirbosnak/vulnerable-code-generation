//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 //size of grid
#define EMPTY 0
#define BLOCKED 1
#define OPEN 2
#define CONNECTED 3

int grid[N][N];
int percolate[N];
int percolated = 0;

int find(int x); 
void unionSites(int p, int q); 
void openSite(int x, int y);
void percolationSimulation();

int find(int x) 
{
    if(percolate[x] == x)
    {
        return x;
    }
    else 
    {
        percolate[x] = find(percolate[x]);
        return percolate[x];
    }
}

void unionSites(int p, int q) 
{
    percolate[find(p)] = find(q);
}

void openSite(int x, int y)
{
    grid[x][y] = OPEN;
    if(x == 0) percolate[y] = N * N;
    if(x == N - 1) percolate[y] = N * N + 1;

    if(x > 0 && grid[x - 1][y] == OPEN) unionSites(x * N + y, (x - 1) * N + y); 
    if(x < N - 1 && grid[x + 1][y] == OPEN) unionSites(x * N + y, (x + 1) * N + y); 
    if(y > 0 && grid[x][y - 1] == OPEN) unionSites(x * N + y, x * N + y - 1); 
    if(y < N - 1 && grid[x][y + 1] == OPEN) unionSites(x * N + y, x * N + y + 1); 
}

void percolationSimulation()
{
    //Initialize grid
    for(int i = 0; i < N; i++) 
    {
        for(int j = 0; j < N; j++) 
        {
            grid[i][j] = EMPTY; 
        }
    }

    //Initialize percolation array
    for(int i = 0; i < N * N + 2; i++) 
    {
        percolate[i] = i; 
    }

    //Generate blocked sites
    srand(time(0));
    int blocked_sites = rand() % (N*N);
    for(int i = 0; i < blocked_sites; i++)
    {
        int x = rand() % N;
        int y = rand() % N;
        if(grid[x][y] == EMPTY)
        {
            grid[x][y] = BLOCKED;
        }
    }

    //Open the top site
    openSite(0,0);

    //Open random sites until top and bottom are connected
    while(percolate[0] != percolate[N*N + 1])
    {
        int x = rand() % N;
        int y = rand() % N;
        if(grid[x][y] == BLOCKED)
        {
            grid[x][y] = OPEN;
            openSite(x, y);
        }
    }
    
    percolated = 1;
}

int main () 
{
    percolationSimulation();

    //Print grid
    printf(" ");
    for(int i = 0; i < N; i++) printf(" %d", i);
    printf("\n");
    for(int i = 0; i < N; i++) 
    {
        printf("%d ", i);
        for(int j = 0; j < N; j++) 
        {
            if(grid[i][j] == BLOCKED) printf("X ");
            else if(i == 0 && j == 0) printf("O ");
            else if(percolate[i * N + j] == percolate[N*N]) printf("+ ");
            else if(percolate[i * N + j] == percolate[N*N + 1]) printf("x ");
            else if(grid[i][j] == OPEN) printf("  ");
            else printf("? ");
        }
        printf("\n");
    }

    if(percolated) printf("Percolation achieved!\n");
    else printf("Percolation not achieved.");
    return 0;
}