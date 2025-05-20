//Falcon-180B DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROW 10
#define COL 10

void createMaze(int maze[ROW][COL]);
void printMaze(int maze[ROW][COL]);
int checkWin(int maze[ROW][COL], int x, int y);
void movePlayer(int maze[ROW][COL], int *x, int *y, char dir);

int main() {
    int maze[ROW][COL];
    int playerX = 0, playerY = 0;

    srand(time(NULL));
    createMaze(maze);
    printMaze(maze);

    while (!checkWin(maze, playerX, playerY)) {
        char input;
        printf("Enter your move (w/a/s/d): ");
        scanf("%c", &input);

        movePlayer(maze, &playerX, &playerY, input);
        printMaze(maze);
    }

    printf("Congratulations! You have reached the end of the maze.\n");

    return 0;
}

void createMaze(int maze[ROW][COL]) {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            maze[i][j] = rand() % 2;
        }
    }
}

void printMaze(int maze[ROW][COL]) {
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

int checkWin(int maze[ROW][COL], int x, int y) {
    if (x == COL - 1 && y == ROW - 1) {
        return 1;
    }

    return 0;
}

void movePlayer(int maze[ROW][COL], int *x, int *y, char dir) {
    int newX = *x, newY = *y;

    switch (dir) {
        case 'w':
            --newY;
            break;
        case 'a':
            --newX;
            break;
        case's':
            ++newY;
            break;
        case 'd':
            ++newX;
            break;
    }

    if (maze[*y][newX] == 0) {
        *x = newX;
        *y = newY;
    }
}