//Falcon-180B DATASET v1.0 Category: Procedural Space Adventure ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int playerX = 0, playerY = 0;
    int map[10][10];
    int i, j;

    // Initialize map
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            map[i][j] = rand() % 2; // 0 for empty space, 1 for asteroid
        }
    }

    // Print map
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (map[i][j] == 0)
                printf(" ");
            else
                printf("*");
        }
        printf("\n");
    }

    while (1) {
        system("clear"); // Clear screen
        printf("Your position: (%d,%d)\n", playerX, playerY);
        printf("Map:\n");

        // Print map
        for (i = 0; i < 10; i++) {
            for (j = 0; j < 10; j++) {
                if (map[i][j] == 0)
                    printf(" ");
                else
                    printf("*");
            }
            printf("\n");
        }

        printf("Enter your move (w/a/s/d): ");
        char move;
        scanf("%c", &move);

        switch (move) {
        case 'w':
            if (playerY > 0 && map[playerY-1][playerX] == 0)
                playerY--;
            break;
        case 'a':
            if (playerX > 0 && map[playerY][playerX-1] == 0)
                playerX--;
            break;
        case's':
            if (playerY < 9 && map[playerY+1][playerX] == 0)
                playerY++;
            break;
        case 'd':
            if (playerX < 9 && map[playerY][playerX+1] == 0)
                playerX++;
            break;
        default:
            printf("Invalid move\n");
        }
    }
}