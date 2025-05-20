//Gemma-7B DATASET v1.0 Category: Procedural Space Adventure ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_Players 2

typedef struct Ship {
    int x;
    int y;
    int orientation; // 0 for horizontal, 1 for vertical, 2 for diagonal
} Ship;

void initializeShips(Ship *ships, int numShips) {
    for (int i = 0; i < numShips; i++) {
        ships[i].x = rand() % 10;
        ships[i].y = rand() % 10;
        ships[i].orientation = rand() % 3;
    }
}

void placeShot(Ship *ships, int x, int y) {
    for (int i = 0; i < MAX_Players; i++) {
        if (ships[i].x == x && ships[i].y == y) {
            ships[i].x = -1;
            ships[i].y = -1;
            return;
        }
    }
    printf("Shot missed!\n");
}

int main() {
    Ship ships[MAX_Players];
    initializeShips(ships, MAX_Players);

    // Gameplay loop
    while (1) {
        int x, y;
        printf("Enter shot coordinates (x, y): ");
        scanf("%d %d", &x, &y);

        placeShot(ships, x, y);

        // Check if any ships are still alive
        for (int i = 0; i < MAX_Players; i++) {
            if (ships[i].x != -1 && ships[i].y != -1) {
                printf("Still alive!\n");
                break;
            }
        }

        // If all ships are sunk, game over
        if (ships[0].x == -1 && ships[0].y == -1) {
            printf("Game over! Player 1 wins!\n");
            break;
        } else if (ships[1].x == -1 && ships[1].y == -1) {
            printf("Game over! Player 2 wins!\n");
            break;
        }
    }

    return 0;
}