//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMap(int x, int y, int player_x, int player_y) {
    printf("----------------------------\n");
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x; j++) {
            if (i == player_y && j == player_x) {
                printf(" P ");
            } else {
                printf(" - ");
            }
        }
        printf("\n");
    }
    printf("----------------------------\n");
}

int main() {

    int map_width = 10, map_height = 10;
    int player_x = 5, player_y = 5;
    int alien_x = rand() % map_width, alien_y = rand() % map_height;

    printf("Welcome to Procedural Space Adventure!\n");
    printf("You are a brave space explorer and your goal is to find and defeat the alien boss.\n");
    printf("You are currently at (%d, %d)\n", player_x, player_y);
    printf("The alien boss is hiding somewhere on a %d x %d map.\n", map_width, map_height);

    int moves = 0;

    while (1) {
        printMap(map_width, map_height, player_x, player_y);

        if (alien_x == player_x && alien_y == player_y) {
            printf("Congratulations! You found and defeated the alien boss in %d moves.\n", moves);
            break;
        }

        printf("Enter your move (u/d/l/r): ");
        char move;
        scanf(" %c", &move);

        if (move == 'u') {
            if (player_y > 0) {
                player_y--;
            } else {
                printf("You can't go there.\n");
            }
        } else if (move == 'd') {
            if (player_y < map_height - 1) {
                player_y++;
            } else {
                printf("You can't go there.\n");
            }
        } else if (move == 'l') {
            if (player_x > 0) {
                player_x--;
            } else {
                printf("You can't go there.\n");
            }
        } else if (move == 'r') {
            if (player_x < map_width - 1) {
                player_x++;
            } else {
                printf("You can't go there.\n");
            }
        } else {
            printf("Invalid move.\n");
        }

        moves++;

        if (moves % 5 == 0) {
            printf("An alien spaceship has appeared nearby.\n");
            int direction = rand() % 4;
            if (direction == 0) {
                printf("The alien spaceship has gone up.\n");
                if (alien_y > 0) {
                    alien_y--;
                }
            } else if (direction == 1) {
                printf("The alien spaceship has gone down.\n");
                if (alien_y < map_height - 1) {
                    alien_y++;
                }
            } else if (direction == 2) {
                printf("The alien spaceship has gone left.\n");
                if (alien_x > 0) {
                    alien_x--;
                }
            } else if (direction == 3) {
                printf("The alien spaceship has gone right.\n");
                if (alien_x < map_width - 1) {
                    alien_x++;
                }
            }
        }

    }

    return 0;
}