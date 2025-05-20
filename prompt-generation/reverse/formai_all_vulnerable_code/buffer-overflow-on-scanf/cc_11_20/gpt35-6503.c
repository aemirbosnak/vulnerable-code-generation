//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0)); // Setting seed for random numbers
    int rows, cols; // Initializing variables for rows and columns of maze
    printf("Enter the number of rows and columns of the maze: ");
    scanf("%d%d", &rows, &cols);
    
    int maze[rows][cols]; // Initializing the maze
    
    // Starting position of the maze
    int x = 0;
    int y = 0;
    int steps = 0; // Initializing steps taken to solve the maze
    
    // Initializing the maze with random 1s and 0s
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            maze[i][j] = rand()%2;
        }
    }
    // Printing the initialized maze
    printf("\nInitialized Maze:\n");
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Solving the maze
    while(x<rows-1 || y<cols-1){ // As long as we haven't reached the bottom right corner
        if(x < rows-1 && maze[x+1][y] == 0){ // Checking if we can move down
            x++;
            steps++;
        }
        else if(y < cols-1 && maze[x][y+1] == 0){ // Checking if we can move right
            y++;
            steps++;
        }
        else{ // We are stuck, no other way to move
            printf("Stuck at %d,%d :( \n", x, y);
            break;
        }
        printf("Moved to position %d,%d \n", x, y);
    }
    if(x==rows-1 && y==cols-1){ // Checking if we have reached the bottom right corner
        steps++;
        printf("\nCongratulations, maze solved in %d steps!!", steps);
    }
    return 0;
}