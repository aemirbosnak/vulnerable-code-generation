#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

char map[ROWS][COLS] = {
    "S.......W",
    ".......#",
    "......##",
    "....##..",
    "..##...#",
    "##......",
    "##...##.",
    "..##...#",
    "....##..",
    "......##"
};

int playerX = 5, playerY = 5;
int goalX = 8, goalY = 8;

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
    }

    if (playerX < 0 || playerX >= COLS || playerY < 0 || playerY >= ROWS) {
        printf("Out of bounds!\n");
        print_map();
        playerX = playerY = 5;
    } else if (map[playerY][playerX] == '#') {
        printf("Blocked!\n");
        print_map();
        playerX = playerY = 5;
    }
}

int main() {
    char input;

    while (playerX != goalX || playerY != goalY) {
        print_map();
        printf("Enter direction (N, S, E, W): ");
        scanf("%c", &input);
        move_player(input);
    }

    printf("Congratulations! You've reached the goal!\n");
    return 0;
}
