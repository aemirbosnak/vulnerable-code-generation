//Falcon-180B DATASET v1.0 Category: Text-Based Adventure Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int playerX = 0, playerY = 0;
    int dungeon[10][10] = {0};

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            dungeon[i][j] = rand() % 2;
        }
    }

    while (1) {
        system("clear");

        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (dungeon[i][j] == 0) {
                    printf(" ");
                } else {
                    printf("#");
                }
            }
            printf("\n");
        }

        printf("Score: %d\n", playerX + playerY);

        char move;
        scanf("%c", &move);

        switch (move) {
            case 'w':
                if (playerY > 0 && dungeon[playerX][playerY - 1] == 0) {
                    playerY--;
                }
                break;
            case's':
                if (playerY < 9 && dungeon[playerX][playerY + 1] == 0) {
                    playerY++;
                }
                break;
            case 'a':
                if (playerX > 0 && dungeon[playerX - 1][playerY] == 0) {
                    playerX--;
                }
                break;
            case 'd':
                if (playerX < 9 && dungeon[playerX + 1][playerY] == 0) {
                    playerX++;
                }
                break;
            default:
                printf("Invalid move.\n");
        }

        if (playerX == 9 && playerY == 9) {
            printf("Congratulations! You win!\n");
            break;
        }
    }

    return 0;
}