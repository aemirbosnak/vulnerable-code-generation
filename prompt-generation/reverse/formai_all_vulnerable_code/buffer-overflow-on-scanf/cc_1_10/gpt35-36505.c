//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX 20   // Maximum size of maze

int maze[MAX][MAX];   // the maze
int sol[MAX][MAX];    // solution matrix
int rows, cols;       // size of maze
int startX, startY;   // starting position
int endX, endY;       // ending position

// Initialize solution matrix with 0's
void initSol() {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            sol[i][j] = 0;
        }
    }
}

// Print the solution matrix
void printSol() {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%d ", sol[i][j]);
        }
        printf("\n");
    }
}

// Recursive function to find the route
int findRoute(int x, int y) {

    // End point reached
    if(x == endX && y == endY) {
        sol[x][y] = 1;
        return 1;
    }

    // Check if current cell is valid
    if(x>=0 && x<rows && y>=0 && y<cols && maze[x][y]!=0 && sol[x][y]!=1) {
        sol[x][y] = 1;  // Mark current cell as part of solution

        // Move right
        if(findRoute(x, y+1) == 1) {
            return 1;
        }

        // Move down
        if(findRoute(x+1, y) == 1) {
            return 1;
        }

        // Move left
        if(findRoute(x, y-1) == 1) {
            return 1;
        }

        // Move up
        if(findRoute(x-1, y) == 1) {
            return 1;
        }

        // Backtrack
        sol[x][y] = 0;

        return 0;
    }

    return 0;
}

int main() {

    int i, j;

    // Input the maze
    printf("Enter the number of rows and columns of the maze: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the maze:\n");
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    // Input the starting and ending points
    printf("Enter the starting point (x,y): ");
    scanf("%d %d", &startX, &startY);

    printf("Enter the ending point (x,y): ");
    scanf("%d %d", &endX, &endY);

    // Initialize the solution matrix
    initSol();

    // Find the route
    if(findRoute(startX, startY) == 1) {
        printf("Path found:\n");
        printSol();
    } else {
        printf("Path not found!\n");
    }

    return 0;
}