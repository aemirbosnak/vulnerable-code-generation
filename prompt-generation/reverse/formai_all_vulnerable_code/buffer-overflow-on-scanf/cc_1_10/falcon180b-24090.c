//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
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
    srand(time(0));
    char maze[ROWS][COLS];
    generateMaze(maze);
    printMaze(maze);
    int startX, startY;
    do {
        printf("Enter starting position (row col): ");
        scanf("%d %d", &startX, &startY);
    } while (!checkExit(startX, startY));
    solveMaze(maze, startX, startY);
    return 0;
}

void generateMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }
}

void printMaze(char maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int checkExit(int x, int y) {
    return x == COLS - 1 && y == ROWS - 1;
}

void solveMaze(char maze[ROWS][COLS], int startX, int startY) {
    int dirX[] = {0, 1, 0, -1};
    int dirY[] = {1, 0, -1, 0};
    int x = startX, y = startY;
    maze[x][y] = 'S';
    while (!checkExit(x, y)) {
        int dir = rand() % 4;
        x += dirX[dir];
        y += dirY[dir];
        if (maze[x][y] == '.') {
            maze[x][y] = 'S';
        }
    }
    printf("Solution:\n");
    printMaze(maze);
}