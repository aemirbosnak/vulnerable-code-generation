#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 5

void printMap(char map[MAP_SIZE][MAP_SIZE], int x, int y) {
    system("clear");
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == x && j == y)
                printf("P ");
            else
                printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char map[MAP_SIZE][MAP_SIZE] = {
        {'#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#'},
        {'#', ' ', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#'}
    };
    int x = 1, y = 1;

    while (1) {
        printMap(map, x, y);
        printf("Enter direction (w/a/s/d): ");
        char dir;
        scanf(" %c", &dir);

        switch (dir) {
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
                printf("Invalid input!\n");
                continue;
        }

        // Boundary check to prevent buffer overflow
        if (x < 0 || x >= MAP_SIZE || y < 0 || y >= MAP_SIZE) {
            printf("Boundary reached! Staying in place.\n");
            x = (x + MAP_SIZE) % MAP_SIZE;
            y = (y + MAP_SIZE) % MAP_SIZE;
        }
    }

    return 0;
}
