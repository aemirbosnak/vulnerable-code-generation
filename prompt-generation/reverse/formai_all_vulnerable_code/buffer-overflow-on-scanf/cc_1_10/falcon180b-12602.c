//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(char maze[ROWS][COLS]);
void printMaze(char maze[ROWS][COLS]);
int checkExit(int x, int y);
void solveMaze(char maze[ROWS][COLS], int startX, int startY);

int main() {
    srand(time(NULL));
    char maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    int startX, startY;
    do {
        printf("Enter starting position (row and column): ");
        scanf("%d %d", &startX, &startY);
    } while (!checkExit(startX, startY));
    solveMaze(maze, startX, startY);
    return 0;
}

void generateMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2 == 0? '.' : '#';
        }
    }
}

void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int checkExit(int x, int y) {
    return x == COLS - 1 && y == ROWS - 1;
}

void solveMaze(char maze[ROWS][COLS], int startX, int startY) {
    int path[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            path[i][j] = -1;
        }
    }
    path[startY][startX] = 0;
    int dx[] = { 0, 0, -1, 1 };
    int dy[] = { -1, 1, 0, 0 };
    int dir = 0;
    while (path[startY][startX] < ROWS * COLS - 1) {
        int nx = startX + dx[dir];
        int ny = startY + dy[dir];
        if (nx >= 0 && nx < COLS && ny >= 0 && ny < ROWS && path[ny][nx] == -1 && maze[ny][nx]!= '#') {
            path[ny][nx] = path[startY][startX] + 1;
            startX = nx;
            startY = ny;
        } else {
            dir = (dir + 1) % 4;
        }
    }
    printf("Solution:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (path[i][j] == -1) {
                printf(". ");
            } else {
                printf("%d ", path[i][j]);
            }
        }
        printf("\n");
    }
}