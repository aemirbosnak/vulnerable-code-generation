#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 5

void printGrid(char grid[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char grid[GRID_SIZE][GRID_SIZE] = {0};
    int x = 2, y = 2;
    grid[x][y] = 'P';

    while (1) {
        system("clear");
        printGrid(grid);
        printf("Enter move (w/a/s/d): ");
        char move;
        scanf(" %c", &move);

        switch (move) {
            case 'w':
                if (x > 0) x--;
                break;
            case 'a':
                if (y > 0) y--;
                break;
            case 's':
                if (x < GRID_SIZE - 1) x++;
                break;
            case 'd':
                if (y < GRID_SIZE - 1) y++;
                break;
            default:
                printf("Invalid move!\n");
                continue;
        }

        grid[x][y] = 'P';
        grid[(x + 1) % GRID_SIZE][(y + 1) % GRID_SIZE] = '*'; // Vulnerable to buffer overflow
    }

    return 0;
}
