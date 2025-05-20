//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Sherlock Holmes
//The Percolation Simulator in Sherlock Holmes Style

#include <stdio.h> //For I/O operations
#include <stdbool.h> //For using Boolean variables
#include <stdlib.h> //For memory allocation

//Print the opening message
void openingMessage() {
    printf("Welcome to the Percolation Simulator, Mr Holmes.\n");
    printf("Please enter the size of the grid that you would like to simulate:\n");
}

//Create the grid
int** createGrid(int size) {
    int** grid = (int**)malloc(size*sizeof(int*));
    for(int i = 0; i < size; i++) {
        grid[i] = (int*)malloc(size*sizeof(int));
        for(int j = 0; j < size; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

//Print the grid
void printGrid(int** grid, int size) {
    printf("The current grid is:\n");
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

//Open a site
void openSite(int** grid, int i, int j) {
    grid[i][j] = 1;
}

//Check if a site is open
bool isSiteOpen(int** grid, int i, int j) {
    return (grid[i][j] == 1);
}

//Check if a site is full
bool isSiteFull(int** grid, int i, int j, int size) {
    bool top = false;
    bool bottom = false;
    bool left = false;
    bool right = false;

    if(i == 0) {
        top = true;
    }
    if(i == size-1) {
        bottom = true;
    }
    if(j == 0) {
        left = true;
    }
    if(j == size-1) {
        right = true;
    }

    if(top || bottom || left || right) {
        return true;
    }

    if(isSiteOpen(grid, i-1, j) && isSiteFull(grid, i-1, j, size)) {
        return true;
    }
    if(isSiteOpen(grid, i+1, j) && isSiteFull(grid, i+1, j, size)) {
        return true;
    }
    if(isSiteOpen(grid, i, j-1) && isSiteFull(grid, i, j-1, size)) {
        return true;
    }
    if(isSiteOpen(grid, i, j+1) && isSiteFull(grid, i, j+1, size)) {
        return true;
    }

    return false;
}

//Check if the system percolates
bool doesSystemPercolate(int** grid, int size) {
    for(int j = 0; j < size; j++) {
        if(isSiteFull(grid, 0, j, size)) {
            return true;
        }
    }
    return false;
}

//Main function
int main() {

    //Print opening message
    openingMessage();

    //Get input from user
    int size;
    scanf("%d", &size);

    //Create the grid
    int** grid = createGrid(size);

    //Simulate
    while(true) {
        //Get input from user
        printf("Please enter the row and column of the site you would like to open (separated by a space).\n");
        int x, y;
        scanf("%d %d", &x, &y);

        //Open the site
        openSite(grid, x, y);

        //Check if the system percolates
        if(doesSystemPercolate(grid, size)) {
            printf("The system percolates!\n");
            break;
        }

        //Print the grid
        printGrid(grid, size);
    }

    //Free the memory
    for(int i = 0; i < size; i++) {
        free(grid[i]);
    }
    free(grid);

    //End the program
    printf("Thank you for using the Percolation Simulator, Mr Holmes.\n");
    return 0;
}