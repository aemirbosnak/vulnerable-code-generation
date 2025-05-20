//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 //Size of the grid

//Function to initialize the grid randomly with open/closed cells
void initializeGrid(int grid[SIZE][SIZE], float p){
    int i, j;
    srand(time(NULL));
    for (i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            float r = (float)rand() / (float)RAND_MAX;
            if (r <= p){
                grid[i][j] = 1; //Open cell
            } else {
                grid[i][j] = 0; //Closed cell
            }
        }
    }
}

//Function to print the current state of the grid
void printGrid(int grid[SIZE][SIZE]){
    int i, j;
    for (i=0; i<SIZE; i++){
        for (j=0; j<SIZE; j++){
            if (grid[i][j] == 1){
                printf("O "); //Open cell
            } else {
                printf("X "); //Closed cell
            }
        }
        printf("\n");
    }
}

//Function to check if a cell is connected to the top row
int isConnected(int grid[SIZE][SIZE], int row, int col){
    if (row == 0){
        return 1; //Connected to the top row
    }
    if (grid[row][col] == 0){
        return 0; //Not connected
    }
    if (col > 0 && isConnected(grid, row, col-1)){
        return 1; //Connected to the left
    }
    if (col < SIZE-1 && isConnected(grid, row, col+1)){
        return 1; //Connected to the right
    }
    if (row > 0 && isConnected(grid, row-1, col)){
        return 1; //Connected to the top
    }
    return 0; //Not connected
}

//Function to simulate percolation
int percolation(int grid[SIZE][SIZE]){
    int i, j, count = 0;
    for (j=0; j<SIZE; j++){
        if (isConnected(grid, SIZE-1, j)){
            count++; //Count connected cells in bottom row
        }
    }
    if (count > 0){
        return 1; //Percolates
    } else {
        return 0; //Does not percolate
    }
}

int main(){
    int grid[SIZE][SIZE];
    float p;
    printf("Enter probability of open cells (0.0-1.0): ");
    scanf("%f", &p);
    initializeGrid(grid, p);
    printGrid(grid);
    if (percolation(grid)){
        printf("The system percolates.\n");
    } else {
        printf("The system does not percolate.\n");
    }
    return 0;
}