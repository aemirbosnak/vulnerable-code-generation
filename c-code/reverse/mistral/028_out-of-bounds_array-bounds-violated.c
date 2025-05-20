#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char map[ROWS][COLS];
int playerX = 0, playerY = 0;

void print_map() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void move_player(char dir) {
    switch (dir) {
        case 'N': --playerY; break;
        case 'S': ++playerY; break;
        case 'E': ++playerX; break;
        case 'W': --playerX; break;
        default: printf("Invalid direction.\n");
    }

    if (playerX < 0 || playerX >= COLS || playerY < 0 || playerY >= ROWS) {
        printf("Out of bounds.\n");
        playerX = playerY = 0;
    }
}

int main() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            map[i][j] = '.' + (i * COLS + j) % 26;
        }
    }
    map[playerX][playerY] = 'P';

    char input;
    while (1) {
        print_map();
        scanf(" %c", &input);
        move_player(input);
    }

    return 0;
}
