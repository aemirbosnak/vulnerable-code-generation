//Falcon-180B DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 8

void create_grid(int grid[N][N], int n) {
    int i, j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            grid[i][j] = 0;
        }
    }
}

void add_border(int grid[N][N]) {
    int i, j;
    for(i=0; i<N; i++) {
        grid[i][0] = 1;
        grid[i][N-1] = 1;
    }
    for(j=0; j<N; j++) {
        grid[0][j] = 1;
        grid[N-1][j] = 1;
    }
}

void display_grid(int grid[N][N]) {
    int i, j;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(grid[i][j] == 1) {
                printf("X ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
}

void percolate(int grid[N][N]) {
    int i, j, k, count = 0;
    for(i=1; i<N-1; i++) {
        for(j=1; j<N-1; j++) {
            if(grid[i][j] == 1) {
                count = 0;
                if(grid[i-1][j] == 1) {
                    count++;
                }
                if(grid[i+1][j] == 1) {
                    count++;
                }
                if(grid[i][j-1] == 1) {
                    count++;
                }
                if(grid[i][j+1] == 1) {
                    count++;
                }
                if(count!= 1) {
                    grid[i][j] = 0;
                }
            }
        }
    }
}

int main() {
    int grid[N][N], n, i, j, k;
    srand(time(NULL));
    printf("Enter the size of the grid (must be between 2 and %d): ", N-1);
    scanf("%d", &n);
    if(n < 2 || n > N-1) {
        printf("Invalid grid size.\n");
        return 0;
    }
    create_grid(grid, n);
    add_border(grid);
    display_grid(grid);
    percolate(grid);
    display_grid(grid);
    return 0;
}