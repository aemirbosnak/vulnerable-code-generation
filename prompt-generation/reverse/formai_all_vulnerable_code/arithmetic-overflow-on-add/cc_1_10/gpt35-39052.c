//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void printMaze(char**, int, int);
int isValidMove(char**, int, int, int, int);
void findRoute(char**, int, int, int, int, int*, int*);
void printRoute(int*, int*);

// Main function
int main() {
    int rows, cols, startRow, startCol, endRow, endCol, i, j;
    char** maze;

    // Take input from user
    printf("Enter the number of rows and columns of maze: ");
    scanf("%d %d", &rows, &cols);

    // Allocate memory for maze
    maze = (char**)malloc(rows * sizeof(char*));
    for(i=0; i<rows; i++) {
        maze[i] = (char*)malloc(cols * sizeof(char));
    }

    // Take input for maze
    printf("Enter the maze (Use 'S' for start and 'E' for end):\n");
    for(i=0; i<rows; i++) {
        scanf("%s", maze[i]);
        for(j=0; j<cols; j++) {
            if(maze[i][j] == 'S') {
                startRow = i;
                startCol = j;
            }
            if(maze[i][j] == 'E') {
                endRow = i;
                endCol = j;
            }
        }
    }

    // Print original maze
    printf("The original maze is:\n");
    printMaze(maze, rows, cols);

    // Find route
    int* routeRow = (int*)malloc(rows * cols * sizeof(int));
    int* routeCol = (int*)malloc(rows * cols * sizeof(int));
    int routeLength = 0;
    findRoute(maze, rows, cols, startRow, startCol, routeRow, routeCol);

    if(routeRow[routeLength] == endRow && routeCol[routeLength] == endCol) {
        printf("The route from start to end is:\n");
        printRoute(routeRow, routeCol);
    }
    else {
        printf("No route found!\n");
    }

    // Free memory
    free(maze);
    free(routeRow);
    free(routeCol);

    return 0;
}

// Function to print maze
void printMaze(char** maze, int rows, int cols) {
    int i, j;
    for(i=0; i<rows; i++) {
        for(j=0; j<cols; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if move is valid
int isValidMove(char** maze, int rows, int cols, int row, int col) {
    if(row >=0 && row < rows && col >= 0 && col < cols && maze[row][col] != '1') {
        return 1;
    }
    return 0;
}

// Function to find route
void findRoute(char** maze, int rows, int cols, int row, int col, int* routeRow, int* routeCol) {
    if(row == -1 || col == -1) {
        return;
    }
    if(maze[row][col] == '1') {
        return;
    }

    // Add the current cell to route
    routeRow[0] = row;
    routeCol[0] = col;

    // Check if the current cell is the end cell
    if(maze[row][col] == 'E') {
        return;
    }

    // Mark the current cell as visited
    maze[row][col] = '1';

    // Search in all four directions
    if(isValidMove(maze, rows, cols, row-1, col)) {
        findRoute(maze, rows, cols, row-1, col, routeRow+1, routeCol+1);
    }
    if(isValidMove(maze, rows, cols, row+1, col)) {
        findRoute(maze, rows, cols, row+1, col, routeRow+1, routeCol+1);
    }
    if(isValidMove(maze, rows, cols, row, col-1)) {
        findRoute(maze, rows, cols, row, col-1, routeRow+1, routeCol+1);
    }
    if(isValidMove(maze, rows, cols, row, col+1)) {
        findRoute(maze, rows, cols, row, col+1, routeRow+1, routeCol+1);
    }
}

// Function to print route
void printRoute(int* routeRow, int* routeCol) {
    int i=0;
    while(routeRow[i] != -1 && routeCol[i] != -1) {
        printf("(%d,%d) ", routeRow[i], routeCol[i]);
        i++;
    }
    printf("\n");
}