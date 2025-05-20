//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// Function to generate a random number between 1 and 100
int randomNumber(int min, int max) {
    return min + (rand() % (max - min + 1));
}

// Function to generate a random maze
void generateMaze(int rows, int cols, int startRow, int startCol, int endRow, int endCol) {
    // Create a 2D array to represent the maze
    int maze[rows][cols];

    // Set the starting and ending positions
    maze[startRow][startCol] = 1;
    maze[endRow][endCol] = 1;

    // Generate the maze
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // Generate a random number between 1 and 100
            int num = randomNumber(1, 100);

            // If the number is odd, create a wall
            if (num % 2 == 1) {
                maze[i][j] = 1;
            }
            // If the number is even, create a path
            else {
                maze[i][j] = 0;
            }
        }
    }

    // Print the maze
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows = 10;
    int cols = 10;
    int startRow = randomNumber(1, rows);
    int startCol = randomNumber(1, cols);
    int endRow = randomNumber(1, rows);
    int endCol = randomNumber(1, cols);

    generateMaze(rows, cols, startRow, startCol, endRow, endCol);

    return 0;
}