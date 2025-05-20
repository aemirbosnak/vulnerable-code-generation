//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_ROW 20
#define MAX_COL 20

// function to initialize the grid with random values
void init_grid(bool grid[MAX_ROW][MAX_COL], int n, float p) {
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            float random = (float)rand() / (float)RAND_MAX;
            grid[i][j] = (random < p);
        }
    }
}

// function to print current state of the grid
void print_grid(bool grid[MAX_ROW][MAX_COL], int n) {
    int i, j;
    printf("Current state of grid:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(grid[i][j]) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// recursive function to flood a cluster starting from given coordinates
void flood_cluster(bool grid[MAX_ROW][MAX_COL], int i, int j, bool visited[MAX_ROW][MAX_COL], int n) {
    if(i < 0 || i >= n || j < 0 || j >= n) {
        return;
    }
    if(!grid[i][j] || visited[i][j]) {
        return;
    }
    visited[i][j] = true;
    flood_cluster(grid, i-1, j, visited, n);
    flood_cluster(grid, i+1, j, visited, n);
    flood_cluster(grid, i, j-1, visited, n);
    flood_cluster(grid, i, j+1, visited, n);
}

// function to check if a percolation path exists in the grid
bool has_percolation_path(bool grid[MAX_ROW][MAX_COL], int n) {
    bool visited[MAX_ROW][MAX_COL];
    int i, j;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
    for(j = 0; j < n; j++) {
        if(grid[0][j]) {
            flood_cluster(grid, 0, j, visited, n);
        }
    }
    for(j = 0; j < n; j++) {
        if(visited[n-1][j]) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    float p;
    printf("Enter size of grid: ");
    scanf("%d", &n);
    printf("Enter probability of cell being open (0.0 to 1.0): ");
    scanf("%f", &p);
    
    srand(time(NULL));
    bool grid[MAX_ROW][MAX_COL];
    init_grid(grid, n, p);
    print_grid(grid, n);
    
    if(has_percolation_path(grid, n)) {
        printf("A percolation path exists!\n");
    } else {
        printf("No percolation path exists.\n");
    }
    
    return 0;
}