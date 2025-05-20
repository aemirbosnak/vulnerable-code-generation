//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
#define WALL -1

int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, 0},
    {0, WALL, 0, 0, 0, 0, 0, 0, WALL, 0},
    {0, WALL, 0, 0, 0, 0, 0, 0, WALL, 0},
    {0, WALL, 0, 0, 0, 0, 0, 0, WALL, 0},
    {0, WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

void printMaze(int maze[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == WALL) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void dfs(int maze[][COLS], int x, int y) {
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int i, j;
    maze[x][y] = 1;
    for (i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && maze[nx][ny] == 0) {
            dfs(maze, nx, ny);
        }
    }
}

int main() {
    int startX, startY, endX, endY;
    printf("Enter starting point (row, col): ");
    scanf("%d %d", &startX, &startY);
    printf("Enter ending point (row, col): ");
    scanf("%d %d", &endX, &endY);
    dfs(maze, startX, startY);
    printMaze(maze);
    return 0;
}