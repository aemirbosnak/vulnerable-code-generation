//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(char maze[ROWS][COLS]);
void printMaze(const char maze[ROWS][COLS]);
int checkExit(int x, int y);
void solveMaze(char maze[ROWS][COLS]);

int main() {
    srand(time(NULL));
    char maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    solveMaze(maze);
    return 0;
}

void generateMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }

    // Set start and exit points
    maze[0][0] = '.';
    maze[ROWS - 1][COLS - 1] = 'E';
}

void printMaze(const char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int checkExit(int x, int y) {
    return x == COLS - 1 && y == ROWS - 1;
}

void solveMaze(char maze[ROWS][COLS]) {
    int startX = 0, startY = 0, endX = COLS - 1, endY = ROWS - 1;

    while (!checkExit(startX, startY)) {
        if (maze[startX][startY] == '.') {
            maze[startX][startY] = '*';
            startX++;
        } else if (maze[startX][startY] == '#') {
            startX--;
        }
    }

    while (!checkExit(endX, endY)) {
        if (maze[endX][endY] == '.') {
            maze[endX][endY] = '*';
            endX--;
        } else if (maze[endX][endY] == '#') {
            endX++;
        }
    }
}