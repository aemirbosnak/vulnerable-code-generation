#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

char map[HEIGHT][WIDTH];
int playerX = 0, playerY = 0;

void print_map() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void move_player(char dir) {
    switch (dir) {
        case 'N': --playerY;
        case 'S': ++playerY;
        case 'E': ++playerX;
        case 'W': --playerX;
        if (playerX < 0 || playerX >= WIDTH || playerY < 0 || playerY >= HEIGHT) {
            printf("Out of bounds!\n");
            system("pause");
            exit(1);
        }
    }
    map[playerY][playerX] = 'P';
    print_map();
}

int main() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            map[i][j] = (i + j) % 2 ? '#' : ' ';
        }
    }
    map[playerY][playerX] = 'P';

    char input;
    while (1) {
        printf("Enter direction (N, S, E, W): ");
        scanf("%c", &input);
        move_player(input);
    }

    return 0;
}
