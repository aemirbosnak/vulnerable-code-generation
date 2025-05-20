//Falcon-180B DATASET v1.0 Category: Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

void drawMaze(char maze[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; ++i) {
        for (j = 0; j < COLS; ++j) {
            if (maze[i][j] == 1) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    int maze[ROWS][COLS];
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            maze[i][j] = rand() % 2;
        }
    }
    drawMaze(maze);
    int playerX = 0, playerY = 0;
    char move;
    while (1) {
        system("clear");
        drawMaze(maze);
        printf("Player at (%d, %d)\n", playerX, playerY);
        scanf("%c", &move);
        int newX = playerX, newY = playerY;
        switch (move) {
        case 'w':
            --newY;
            break;
        case's':
            ++newY;
            break;
        case 'a':
            --newX;
            break;
        case 'd':
            ++newX;
            break;
        default:
            continue;
        }
        if (maze[newY][newX] == 0) {
            playerX = newX;
            playerY = newY;
        }
    }
    return 0;
}