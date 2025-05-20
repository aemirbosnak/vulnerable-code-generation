#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

int main() {
    int x = 0, y = 0;
    int moves = 10;

    while (moves > 0) {
        printf("You are at (%d, %d). Moves left: %d\n", x, y, moves);
        printf("Enter direction (w/a/s/d): ");
        char dir;
        scanf(" %c", &dir);

        switch (dir) {
            case 'w':
                if (y > 0) y--;
                break;
            case 'a':
                if (x > 0) x--;
                break;
            case 's':
                if (y < HEIGHT - 1) y++;
                break;
            case 'd':
                if (x < WIDTH - 1) x++;
                break;
            default:
                printf("Invalid move.\n");
                continue;
        }

        if (x == WIDTH / 2 && y == HEIGHT / 2) {
            printf("Congratulations! You found the treasure!\n");
            return 0;
        }

        moves--;
    }

    printf("Game over. Treasure not found.\n");
    return 0;
}
