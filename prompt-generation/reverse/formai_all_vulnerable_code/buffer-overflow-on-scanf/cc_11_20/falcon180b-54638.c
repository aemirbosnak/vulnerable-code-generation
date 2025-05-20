//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int map[10][10];
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = rand() % 2;
        }
    }

    int playerX = 0;
    int playerY = 0;

    while (1) {
        system("clear");
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] == 0) {
                    printf(" ");
                } else {
                    printf("#");
                }
            }
            printf("\n");
        }
        printf("Player: (%d, %d)\n", playerX, playerY);

        char move;
        scanf("%c", &move);

        switch (move) {
            case 'w':
                if (playerY > 0 && map[playerX][playerY - 1] == 0) {
                    playerY--;
                }
                break;
            case's':
                if (playerY < 9 && map[playerX][playerY + 1] == 0) {
                    playerY++;
                }
                break;
            case 'a':
                if (playerX > 0 && map[playerX - 1][playerY] == 0) {
                    playerX--;
                }
                break;
            case 'd':
                if (playerX < 9 && map[playerX + 1][playerY] == 0) {
                    playerX++;
                }
                break;
            default:
                printf("Invalid move.\n");
        }
    }

    return 0;
}