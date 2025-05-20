//Falcon-180B DATASET v1.0 Category: Educational ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROWS 10
#define MAX_COLS 10
#define ROWS 5
#define COLS 5

int maze[MAX_ROWS][MAX_COLS] = {{0}};
int startRow, startCol;
int endRow, endCol;

void generateMaze() {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            maze[row][col] = rand() % 2;
        }
    }

    // Set start and end points
    do {
        startRow = rand() % ROWS;
        startCol = rand() % COLS;
    } while (maze[startRow][startCol]!= 0);

    do {
        endRow = rand() % ROWS;
        endCol = rand() % COLS;
    } while (maze[endRow][endCol]!= 0);

    // Create path from start to end
    int pathRow = startRow;
    int pathCol = startCol;
    while (pathRow!= endRow || pathCol!= endCol) {
        int dir = rand() % 4;
        switch (dir) {
            case 0:
                pathRow--;
                break;
            case 1:
                pathRow++;
                break;
            case 2:
                pathCol--;
                break;
            case 3:
                pathCol++;
                break;
        }
        maze[pathRow][pathCol] = 1;
    }
}

void printMaze() {
    int row, col;
    for (row = 0; row < ROWS; row++) {
        for (col = 0; col < COLS; col++) {
            if (maze[row][col] == 0) {
                printf("X ");
            } else if (maze[row][col] == 1) {
                printf("- ");
            } else {
                printf("%d ", maze[row][col]);
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    generateMaze();
    printMaze();

    return 0;
}