//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: intelligent
#include<stdio.h>
#define MAX 30

int grid[MAX][MAX], temp[MAX][MAX];
int size, iterations;

void init() {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            grid[i][j] = 0;
            temp[i][j] = 0;
        }
    }
}

void printGrid() {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void copyGrid() {
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            grid[i][j] = temp[i][j];
        }
    }
}

int countNeighbors(int row, int col) {
    int count = 0;
    if(grid[row-1][col]) {count++;}
    if(grid[row+1][col]) {count++;}
    if(grid[row][col-1]) {count++;}
    if(grid[row][col+1]) {count++;}
    return count;
}

void simulate() {
    for(int i=0; i<iterations; i++) {
        for(int j=1; j<size-1; j++) {
            for(int k=1; k<size-1; k++) {
                if(grid[j][k] == 1) {
                    temp[j][k] = 1; // if cell is already full, keep it full
                }
                else if((countNeighbors(j,k)>=2) && (countNeighbors(j,k)<=3)) {
                    temp[j][k] = 1; // if cell has 2 or 3 full neighbors, fill it up
                }
                else {
                    temp[j][k] = 0; // otherwise, empty the cell
                }
            }
        }
        copyGrid(); // copy modified grid into original grid for next iteration
    }
}

int main() {
    printf("Enter the size of the grid (max 30): ");
    scanf("%d", &size);
    printf("Enter the number of iterations: ");
    scanf("%d", &iterations);
    init(); // initialize grids to all 0's
    grid[size/2][size/2] = 1; // set center cell to full
    simulate();
    printf("\nPercolation simulation:\n");
    printGrid();
    return 0;
}