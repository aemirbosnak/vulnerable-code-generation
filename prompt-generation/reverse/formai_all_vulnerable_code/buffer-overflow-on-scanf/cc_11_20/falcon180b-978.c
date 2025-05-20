//Falcon-180B DATASET v1.0 Category: Terminal Based Game ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerX = 0, playerY = 0;
    int enemyX = 0, enemyY = 0;
    int map[10][10] = {0};
    int gameover = 0;

    srand(time(NULL));

    system("clear");

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = rand() % 2;
        }
    }

    while (!gameover) {
        system("clear");

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (map[i][j] == 1) {
                    printf("#");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }

        printf("Player: %d, %d\n", playerX, playerY);
        printf("Enemy: %d, %d\n", enemyX, enemyY);

        char move;
        scanf("%c", &move);

        switch (move) {
            case 'w':
                playerY--;
                break;
            case's':
                playerY++;
                break;
            case 'a':
                playerX--;
                break;
            case 'd':
                playerX++;
                break;
            default:
                break;
        }

        if (playerX < 0 || playerX > 9 || playerY < 0 || playerY > 9) {
            printf("Game over! You lost.\n");
            gameover = 1;
        } else if (map[playerX][playerY] == 1) {
            printf("Game over! You won!\n");
            gameover = 1;
        } else {
            map[playerX][playerY] = 1;
        }

        if (gameover) {
            system("pause");
        }
    }

    return 0;
}