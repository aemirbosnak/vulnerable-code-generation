//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void generateMaze(char maze[ROWS][COLS]);
void printMaze(const char maze[ROWS][COLS]);
int movePlayer(char maze[ROWS][COLS], int x, int y, int dx, int dy);

int main() {
    srand(time(NULL));
    char maze[ROWS][COLS];
    generateMaze(maze);
    int playerX = 0, playerY = 0;

    while (1) {
        system("clear");
        printMaze(maze);
        printf("Player at (%d,%d)\n", playerX, playerY);

        char move;
        scanf(" %c", &move);

        switch (move) {
            case 'w':
                playerY -= 1;
                break;
            case's':
                playerY += 1;
                break;
            case 'a':
                playerX -= 1;
                break;
            case 'd':
                playerX += 1;
                break;
            default:
                continue;
        }

        playerX = (playerX + COLS) % COLS;
        playerY = (playerY + ROWS) % ROWS;

        if (maze[playerY][playerX] == '#') {
            printf("You hit a wall!\n");
        } else {
            movePlayer(maze, playerX, playerY, 0, 0);
        }
    }

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
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int movePlayer(char maze[ROWS][COLS], int x, int y, int dx, int dy) {
    if (maze[y][x] == '.') {
        maze[y][x] = '@';
        return 1;
    }

    return 0;
}