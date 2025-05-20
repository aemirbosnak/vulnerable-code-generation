//Falcon-180B DATASET v1.0 Category: Rogue-like Game with Procedural Generation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int map[10][10] = {0};
    int playerx = 0, playery = 0;

    // Generate map
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            map[i][j] = rand() % 2;
        }
    }

    // Print map
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

    // Move player
    char move;
    while (1) {
        printf("Enter your move (w/a/s/d): ");
        scanf("%c", &move);
        switch (move) {
            case 'w':
                if (playerx > 0 && map[playerx - 1][playery] == 0) {
                    playerx--;
                }
                break;
            case 'a':
                if (playery > 0 && map[playerx][playery - 1] == 0) {
                    playery--;
                }
                break;
            case's':
                if (playerx < 9 && map[playerx + 1][playery] == 0) {
                    playerx++;
                }
                break;
            case 'd':
                if (playery < 9 && map[playerx][playery + 1] == 0) {
                    playery++;
                }
                break;
            default:
                printf("Invalid move.\n");
        }
        // Check if player reached exit
        if (playerx == 9 && playery == 9) {
            printf("Congratulations! You won!\n");
            break;
        }
    }

    return 0;
}