//FormAI DATASET v1.0 Category: Game of Life ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10 // maximum allowed rows in the grid
#define MAX_COLS 10 // maximum allowed columns in the grid

int grid[MAX_ROWS][MAX_COLS]; // the game grid
int newGrid[MAX_ROWS][MAX_COLS]; // the updated game grid
int rows, cols; // actual dimensions of the grid

// function to initialize the grid with random values
void initializeGrid(){
    srand(time(NULL));
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            grid[i][j] = rand()%2;
        }
    }
}

// function to print the current state of the grid
void printGrid(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%c ", grid[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

// function to count the number of live neighbors for a cell
int countLiveNeighbors(int x, int y){
    int count = 0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i == 0 && j == 0){
                continue; // skip the current cell
            }
            int r = (x+i+rows)%rows; // move in a cyclic manner
            int c = (y+j+cols)%cols; // move in a cyclic manner
            count += grid[r][c];
        }
    }
    return count;
}

// function to update the grid according to the rules of the Game of Life
void updateGrid(){
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            int count = countLiveNeighbors(i, j);
            if(grid[i][j] == 0 && count == 3){
                newGrid[i][j] = 1; // a dead cell comes to life
            }
            else if(grid[i][j] == 1 && (count==2 || count==3)){
                newGrid[i][j] = 1; // the cell remains alive
            }
            else{
                newGrid[i][j] = 0; // the cell becomes dead
            }
        }
    }
    // copy the updated grid to the main grid
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            grid[i][j] = newGrid[i][j];
        }
    }
}

int main(){
    // read the dimensions of the grid from the user
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &rows, &cols);
    if(rows > MAX_ROWS || cols > MAX_COLS){
        printf("Invalid dimensions.\n");
        return 0;
    }
    // initialize the grid with random values
    initializeGrid();
    // run the Game of Life for 10 generations
    for(int i=0; i<10; i++){
        printf("Generation %d:\n", i+1);
        printGrid();
        updateGrid();
    }
    return 0;
}