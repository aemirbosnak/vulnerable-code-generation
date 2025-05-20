//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = {
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 0, 0, 0, 0, 1}
};

int moveX[4] = {1, -1, 0, 0};
int moveY[4] = {0, 0, 1, -1};

bool isValid(int x, int y) {
    if (x < 0 || y < 0 || x >= ROW || y >= COL) {
        return false;
    }
    if (maze[x][y] == 0) {
        return false;
    }
    return true;
}

bool dfs(int x, int y, int destX, int destY) {
    if (x == destX && y == destY) {
        maze[x][y] = 2;
        return true;
    }

    for (int i = 0; i < 4; i++) {
        int nextX = x + moveX[i];
        int nextY = y + moveY[i];

        if (isValid(nextX, nextY)) {
            maze[x][y] = 2;
            if (dfs(nextX, nextY, destX, destY)) {
                return true;
            }
            maze[x][y] = 1;
        }
    }

    return false;
}

void printMaze() {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            if (maze[i][j] == 0) {
                printf("#\t");
            } else if (maze[i][j] == 1) {
                printf(".\t");
            } else if (maze[i][j] == 2) {
                printf("X\t");
            }
        }
        printf("\n");
    }
}

int main() {
    int startX, startY, destX, destY;

    printf("Enter the starting position of the maze [X Y]: ");
    scanf("%d%d", &startX, &startY);

    printf("Enter the destination of the maze [X Y]: ");
    scanf("%d%d", &destX, &destY);

    if (dfs(startX, startY, destX, destY)) {
        printf("\nCongratulations! Your path has been found.\n\n");
    } else {
        printf("\nSorry! Your path was not found.\n\n");
    }

    printMaze();

    return 0;
}