//Falcon2-11B DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create a maze
void createMaze(int maze[100][100], int width, int height, int startRow, int startCol, int endRow, int endCol) {
    // Create a maze with width and height
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            maze[i][j] = 0;
        }
    }

    // Start from the starting point and find the path to the ending point
    int x = startCol;
    int y = startRow;
    while (x!= endCol || y!= endRow) {
        int dx[4] = { 0, 1, 0, -1 };
        int dy[4] = { 1, 0, -1, 0 };

        int currX = x;
        int currY = y;
        int nextX = currX + dx[maze[currY][currX]];
        int nextY = currY + dy[maze[currY][currX]];

        if (nextX >= 0 && nextX < width && nextY >= 0 && nextY < height && maze[nextY][nextX] == 0) {
            maze[nextY][nextX] = maze[currY][currX] + 1;
            x = nextX;
            y = nextY;
        } else {
            maze[currY][currX] = maze[currY][currX] + 1;
            break;
        }
    }
}

// Function to print the maze
void printMaze(int maze[100][100], int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int maze[100][100] = { 0 };
    int width = 10;
    int height = 10;
    int startRow = 0;
    int startCol = 0;
    int endRow = 9;
    int endCol = 9;

    createMaze(maze, width, height, startRow, startCol, endRow, endCol);
    printMaze(maze, width, height);

    return 0;
}