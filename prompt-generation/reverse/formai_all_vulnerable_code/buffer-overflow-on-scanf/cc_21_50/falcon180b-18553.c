//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int playerX = rand() % 10;
    int playerY = rand() % 10;
    int spaceshipX = rand() % 10;
    int spaceshipY = rand() % 10;
    int asteroidX = rand() % 10;
    int asteroidY = rand() % 10;

    char map[10][10];

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (i == playerX && j == playerY) {
                map[i][j] = 'P';
            } else if (i == spaceshipX && j == spaceshipY) {
                map[i][j] = 'S';
            } else if (i == asteroidX && j == asteroidY) {
                map[i][j] = 'A';
            } else {
                map[i][j] = '.';
            }
        }
    }

    printf("Welcome to the Space Adventure!\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }

    int playerInput;
    while (1) {
        printf("Enter your move (w/a/s/d): ");
        scanf("%d", &playerInput);

        switch (playerInput) {
            case 1:
                if (playerX > 0 && map[playerX - 1][playerY]!= 'S' && map[playerX - 1][playerY]!= 'A') {
                    playerX--;
                }
                break;
            case 2:
                if (playerX < 9 && map[playerX + 1][playerY]!= 'S' && map[playerX + 1][playerY]!= 'A') {
                    playerX++;
                }
                break;
            case 3:
                if (playerY > 0 && map[playerX][playerY - 1]!= 'S' && map[playerX][playerY - 1]!= 'A') {
                    playerY--;
                }
                break;
            case 4:
                if (playerY < 9 && map[playerX][playerY + 1]!= 'S' && map[playerX][playerY + 1]!= 'A') {
                    playerY++;
                }
                break;
            default:
                printf("Invalid move.\n");
        }

        if (map[playerX][playerY] == 'S') {
            printf("You found the spaceship!\n");
            return 0;
        } else if (map[playerX][playerY] == 'A') {
            printf("You hit an asteroid!\n");
            return 0;
        }
    }

    return 0;
}