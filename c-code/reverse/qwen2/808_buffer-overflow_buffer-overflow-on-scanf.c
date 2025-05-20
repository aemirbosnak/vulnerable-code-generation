#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 5

void printGrid(int grid[GRID_SIZE][GRID_SIZE], int playerX, int playerY) {
    system("cls");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("P ");
            } else if (grid[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(0));
    int grid[GRID_SIZE][GRID_SIZE] = {0};
    int playerX = 2, playerY = 2;
    int treasureX, treasureY;

    do {
        treasureX = rand() % GRID_SIZE;
        treasureY = rand() % GRID_SIZE;
    } while (treasureX == playerX && treasureY == playerY);

    grid[treasureX][treasureY] = 1;

    char move;
    while (1) {
        printGrid(grid, playerX, playerY);
        printf("Move (w/a/s/d): ");
        scanf(" %c", &move);

        switch (move) {
            case 'w':
                if (playerX > 0) playerX--;
                break;
            case 'a':
                if (playerY > 0) playerY--;
                break;
            case 's':
                if (playerX < GRID_SIZE - 1) playerX++;
                break;
            case 'd':
                if (playerY < GRID_SIZE - 1) playerY++;
                break;
            default:
                continue;
        }

        if (playerX == treasureX && playerY == treasureY) {
            printf("Congratulations! You found the treasure!\n");
            return 0;
        }
    }

    return 0;
}
