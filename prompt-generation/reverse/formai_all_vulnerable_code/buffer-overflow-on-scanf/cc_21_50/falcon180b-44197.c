//Falcon-180B DATASET v1.0 Category: Haunted House Simulator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int playerX = 0;
    int playerY = 0;
    int map[10][10] = {0};
    int doorX = rand() % 10;
    int doorY = rand() % 10;
    map[doorY][doorX] = 1;

    while (1) {
        system("CLS");
        printf("Score: %d\n", playerX * playerY);
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] == 1) {
                    printf("X ");
                } else if (i == playerX && j == playerY) {
                    printf("@ ");
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }
        if (playerX == doorX && playerY == doorY) {
            printf("You have escaped the haunted house!");
            break;
        }
        char move;
        scanf("%c", &move);
        switch (move) {
        case 'w':
            if (playerY > 0 && map[playerY - 1][playerX] == 0) {
                playerY--;
            }
            break;
        case's':
            if (playerY < 9 && map[playerY + 1][playerX] == 0) {
                playerY++;
            }
            break;
        case 'a':
            if (playerX > 0 && map[playerY][playerX - 1] == 0) {
                playerX--;
            }
            break;
        case 'd':
            if (playerX < 9 && map[playerY][playerX + 1] == 0) {
                playerX++;
            }
            break;
        default:
            printf("Invalid move.");
        }
    }

    return 0;
}