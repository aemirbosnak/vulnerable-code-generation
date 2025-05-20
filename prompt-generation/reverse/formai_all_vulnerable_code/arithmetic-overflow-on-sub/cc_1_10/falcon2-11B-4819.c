//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate a random maze
void generateMaze(int maze[][100], int rows, int cols) {
    int i, j;
    int startRow = rand() % rows;
    int startCol = rand() % cols;

    // mark start position
    maze[startRow][startCol] = 1;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (maze[i][j] == 1) {
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int newRow = i + maze[i][j] - 1;
                int newCol = j + k;

                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) {
                    maze[newRow][newCol] = 1;
                }
            }
        }
    }
}

// function to print the maze
void printMaze(int maze[][100], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int maze[100][100];
    int rows = 10;
    int cols = 10;

    srand(time(NULL));

    generateMaze(maze, rows, cols);
    printMaze(maze, rows, cols);

    return 0;
}