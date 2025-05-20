#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

#define ROWS 5
#define COLS 5

void printMap(int map[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(int map[ROWS][COLS], int *playerX, int *playerY) {
    char direction;
    printf("Enter direction (w/a/s/d): ");
    scanf(" %c", &direction);

    switch (direction) {
        case 'w':
            if (*playerX > 0) (*playerX)--;
            break;
        case 'a':
            if (*playerY > 0) (*playerY)--;
            break;
        case 's':
            if (*playerX < ROWS - 1) (*playerX)++;
            break;
        case 'd':
            if (*playerY < COLS - 1) (*playerY)++;
            break;
        default:
            printf("Invalid direction!\n");
            return;
    }

    // Intentional out-of-bounds access
    map[*playerX][*playerY] += 10;
}

int main() {
    int map[ROWS][COLS] = {0};
    int playerX = 0, playerY = 0;

    while (1) {
        system("clear");
        printMap(map);
        movePlayer(map, &playerX, &playerY);
    }

    return 0;
}
