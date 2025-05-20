//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdbool.h>

#define MAX_ROWS 20
#define MAX_COLS 20

bool isWall(int x, int y) {
    if (x < 0 || x >= MAX_ROWS || y < 0 || y >= MAX_COLS) {
        return true;
    }
    return false;
}

void printPath(int startX, int startY, int endX, int endY, int path[]) {
    int currX = startX;
    int currY = startY;
    int nextX = endX;
    int nextY = endY;

    printf("Path: ");
    while (nextX!= currX || nextY!= currY) {
        printf("%d,%d ", path[currX * MAX_ROWS + currY]);
        currX = nextX;
        currY = nextY;
        nextX = path[currX * MAX_ROWS + currY];
        nextY = path[currX * MAX_ROWS + currY];
    }
    printf("\n");
}

int main() {
    int grid[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            grid[i][j] = 0;
        }
    }
    grid[5][5] = 1; // start
    grid[19][5] = 1; // end
    int path[MAX_ROWS * MAX_COLS];

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (grid[i][j] == 0 && isWall(i, j)) {
                path[i * MAX_ROWS + j] = i * MAX_ROWS + j;
            }
        }
    }

    printf("Path: ");
    int currX = 5;
    int currY = 5;
    int nextX = 19;
    int nextY = 5;
    while (nextX!= currX || nextY!= currY) {
        printf("%d,%d ", path[currX * MAX_ROWS + currY]);
        currX = nextX;
        currY = nextY;
        nextX = path[currX * MAX_ROWS + currY];
        nextY = path[currX * MAX_ROWS + currY];
    }
    printf("\n");

    return 0;
}