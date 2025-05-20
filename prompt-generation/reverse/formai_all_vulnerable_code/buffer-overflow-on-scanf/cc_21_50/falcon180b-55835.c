//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int x, y, playerX, playerY, shipX, shipY, choice;
    char map[10][10];

    // Initialize map with asteroids and empty spaces
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = '.';
        }
    }

    // Place player and enemy ship on the map
    playerX = 0;
    playerY = 0;
    map[playerX][playerY] = 'P';

    shipX = 9;
    shipY = 9;
    map[shipX][shipY] = 'S';

    // Print initial map
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }

    // Game loop
    while (1) {
        // Move enemy ship towards player
        if (shipX > playerX) {
            shipX--;
        } else if (shipX < playerX) {
            shipX++;
        }
        if (shipY > playerY) {
            shipY--;
        } else if (shipY < playerY) {
            shipY++;
        }

        // Check for collision with asteroid
        if (map[shipX][shipY] == '*') {
            printf("The enemy ship has crashed into an asteroid!\n");
            printf("You win!\n");
            break;
        }

        // Check for collision with player
        if (map[shipX][shipY] == 'P') {
            printf("The enemy ship has caught up to you!\n");
            printf("Game over.\n");
            break;
        }

        // Move player
        char key;
        printf("Enter your move (w/a/s/d): ");
        scanf("%c", &key);
        switch (key) {
            case 'w':
                if (playerY > 0 && map[playerX][playerY - 1] == '.') {
                    playerY--;
                }
                break;
            case 'a':
                if (playerX > 0 && map[playerX - 1][playerY] == '.') {
                    playerX--;
                }
                break;
            case's':
                if (playerY < 9 && map[playerX][playerY + 1] == '.') {
                    playerY++;
                }
                break;
            case 'd':
                if (playerX < 9 && map[playerX + 1][playerY] == '.') {
                    playerX++;
                }
                break;
            default:
                printf("Invalid move.\n");
        }

        // Update map
        map[playerX][playerY] = '.';
        map[shipX][shipY] = 'S';
        playerX = shipX;
        playerY = shipY;

        // Print updated map
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}