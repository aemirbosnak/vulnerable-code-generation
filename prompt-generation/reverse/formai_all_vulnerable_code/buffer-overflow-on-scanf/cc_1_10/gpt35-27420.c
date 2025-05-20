//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 0, 1, 1, 1, 1, 0, 1}
};

int startX, startY, endX, endY;

void setStartAndEnd() {
    printf("Enter the starting X and Y coordinates: ");
    scanf("%d %d", &startX, &startY);

    printf("Enter the ending X and Y coordinates: ");
    scanf("%d %d", &endX, &endY);
}

bool isValid(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return false;
    }

    if (maze[x][y] == 1) {
        return false;
    }

    return true;
}

bool findPath(int x, int y) {
    if (x == endX && y == endY) {
        return true;
    }

    if (!isValid(x, y)) {
        return false;
    }

    maze[x][y] = 1;

    if (findPath(x - 1, y)) { // move left
        return true;
    }

    if (findPath(x + 1, y)) { // move right
        return true;
    }

    if (findPath(x, y - 1)) { // move up
        return true;
    }

    if (findPath(x, y + 1)) { // move down
        return true;
    }

    maze[x][y] = 0;

    return false;
}

void printMaze() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == startX && j == startY) {
                printf("S ");
            } else if (i == endX && j == endY) {
                printf("E ");
            } else if (maze[i][j] == 1) {
                printf("# ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    setStartAndEnd();

    if (findPath(startX, startY)) {
        printf("Path found!\n");
        printMaze();
    } else {
        printf("No path found!\n");
    }

    return 0;
}