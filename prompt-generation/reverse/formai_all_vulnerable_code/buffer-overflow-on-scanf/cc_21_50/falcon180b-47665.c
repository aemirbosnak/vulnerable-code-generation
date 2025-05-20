//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerX = rand() % 10;
    int playerY = rand() % 10;
    int treasureX = rand() % 10;
    int treasureY = rand() % 10;

    char map[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == playerX && j == playerY) {
                map[i][j] = 'P';
            } else if (i == treasureX && j == treasureY) {
                map[i][j] = 'T';
            } else {
                map[i][j] = rand() % 2? '.' : '#';
            }
        }
    }

    while (1) {
        system("clear");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
        printf("Press WASD to move.\n");
        char move;
        scanf("%c", &move);
        if (move == 'w' && playerY > 0 && map[playerX][playerY - 1]!= '#') {
            playerY--;
        } else if (move =='s' && playerY < 9 && map[playerX][playerY + 1]!= '#') {
            playerY++;
        } else if (move == 'a' && playerX > 0 && map[playerX - 1][playerY]!= '#') {
            playerX--;
        } else if (move == 'd' && playerX < 9 && map[playerX + 1][playerY]!= '#') {
            playerX++;
        }
        if (playerX == treasureX && playerY == treasureY) {
            printf("You found the treasure!\n");
            break;
        }
    }

    return 0;
}