#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 5

void printMap(int map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int map[MAP_SIZE][MAP_SIZE] = {0};
    int x = 0, y = 0;

    while (1) {
        system("clear");
        printMap(map);
        printf("Player at (%d, %d)\n", x, y);

        char move;
        printf("Move (w/a/s/d): ");
        scanf(" %c", &move);

        switch (move) {
            case 'w':
                if (x > 0) x--;
                break;
            case 'a':
                if (y > 0) y--;
                break;
            case 's':
                if (x < MAP_SIZE - 1) x++;
                break;
            case 'd':
                if (y < MAP_SIZE - 1) y++;
                break;
            default:
                printf("Invalid move!\n");
                continue;
        }

        // Simulate placing something on the map
        map[x][y]++;
    }

    return 0;
}
