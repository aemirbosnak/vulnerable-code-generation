#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define GRID_SIZE 5

int main() {
    int x = GRID_SIZE / 2;
    int y = GRID_SIZE / 2;

    printf("Welcome to the Treasure Hunt Game!\n");
    printf("Your starting position is at (%d, %d).\n", x, y);

    while (1) {
        char move;
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);

        switch (move) {
            case 'w':
                if (y > 0) y--;
                break;
            case 'a':
                if (x > 0) x--;
                break;
            case 's':
                if (y < GRID_SIZE - 1) y++;
                break;
            case 'd':
                if (x < GRID_SIZE - 1) x++;
                break;
            default:
                printf("Invalid move. Please enter w, a, s, or d.\n");
                continue;
        }

        printf("You moved to (%d, %d).\n", x, y);
    }

    return 0;
}
