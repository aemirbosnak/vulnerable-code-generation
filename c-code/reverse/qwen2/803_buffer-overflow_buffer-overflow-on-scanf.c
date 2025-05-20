#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 5
#define HEIGHT 5

void print_map(int map[HEIGHT][WIDTH], int x, int y) {
    system("clear");
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (i == x && j == y) printf("P ");
            else printf(". ");
        }
        printf("\n");
    }
}

int main() {
    int map[HEIGHT][WIDTH] = {0};
    int x = 2, y = 2;
    char move;

    while (1) {
        print_map(map, x, y);
        printf("Enter your move (w/a/s/d): ");
        scanf(" %c", &move);

        switch (move) {
            case 'w':
                if (x > 0) x--;
                break;
            case 'a':
                if (y > 0) y--;
                break;
            case 's':
                if (x < HEIGHT - 1) x++;
                break;
            case 'd':
                if (y < WIDTH - 1) y++;
                break;
            default:
                printf("Invalid move. Try again.\n");
                continue;
        }

        // Check for treasure at the new position
        if (map[x][y] == 1) {
            printf("Congratulations! You found the treasure!\n");
            return 0;
        }
    }

    return 0;
}
