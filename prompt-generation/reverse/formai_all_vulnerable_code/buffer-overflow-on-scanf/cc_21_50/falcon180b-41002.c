//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int maze[10][10];
    int playerX = 0;
    int playerY = 0;
    int treasureX = rand() % 10;
    int treasureY = rand() % 10;
    int gameOver = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            maze[i][j] = rand() % 2;
        }
    }

    while (!gameOver) {
        system("clear");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (maze[i][j] == 0) {
                    printf("  ");
                } else {
                    printf("# ");
                }
            }
            printf("\n");
        }
        printf("You are at (%d,%d)\n", playerX, playerY);
        if (playerX == treasureX && playerY == treasureY) {
            printf("Congratulations! You found the treasure!\n");
            gameOver = 1;
        }

        char move;
        scanf("%c", &move);
        if (move == 'w' && playerY > 0 && maze[playerX][playerY - 1] == 0) {
            playerY--;
        } else if (move =='s' && playerY < 9 && maze[playerX][playerY + 1] == 0) {
            playerY++;
        } else if (move == 'a' && playerX > 0 && maze[playerX - 1][playerY] == 0) {
            playerX--;
        } else if (move == 'd' && playerX < 9 && maze[playerX + 1][playerY] == 0) {
            playerX++;
        }
    }

    return 0;
}