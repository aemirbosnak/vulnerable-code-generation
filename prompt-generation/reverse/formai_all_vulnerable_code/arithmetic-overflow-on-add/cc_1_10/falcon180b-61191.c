//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define ROWS 5
#define COLS 5

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 0, 0, 1},
    {1, 0, 0, 0, 1},
    {1, 1, 1, 1, 1}
};

void printMaze(int maze[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(maze[i][j] == 1)
                printf("  ");
            else
                printf("X ");
        }
        printf("\n");
    }
}

void findRoute(int maze[ROWS][COLS], int x, int y, int destX, int destY) {
    if(x == destX && y == destY) {
        printf("Route found!\n");
        return;
    }

    int dx[] = {0, 1, 0, -1};
    int dy[] = {-1, 0, 1, 0};

    int i;
    for(i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >= 0 && nx < ROWS && ny >= 0 && ny < COLS && maze[nx][ny] == 1) {
            maze[nx][ny] = 0;
            findRoute(maze, nx, ny, destX, destY);
            maze[nx][ny] = 1;
        }
    }
}

int main() {
    int srcX, srcY, destX, destY;

    printf("Enter source coordinates:\n");
    scanf("%d %d", &srcX, &srcY);

    printf("Enter destination coordinates:\n");
    scanf("%d %d", &destX, &destY);

    findRoute(maze, srcX, srcY, destX, destY);

    printf("\nMaze:\n");
    printMaze(maze);

    return 0;
}