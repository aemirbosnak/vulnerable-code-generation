#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 10
#define COLS 10

char map[ROWS][COLS];
int player_x = 0, player_y = 0;

void print_map() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void move(char dir) {
    switch (dir) {
        case 'N': --player_y; break;
        case 'S': ++player_y; break;
        case 'E': ++player_x; break;
        case 'W': --player_x; break;
    }

    if (player_x < 0 || player_x >= COLS || player_y < 0 || player_y >= ROWS) {
        printf("Out of bounds!\n");
        exit(1);
    }

    map[player_y][player_x] = 'P';
    print_map();
}

int main() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            map[i][j] = (i + j) % 2 ? '.' : '#';
        }
    }
    map[player_y][player_x] = 'P';

    char command;
    while (1) {
        printf("> ");
        scanf("%c", &command);
        move(command);
    }

    return 0;
}
