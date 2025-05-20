#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 10
#define HEIGHT 10

char map[HEIGHT][WIDTH] = {
    "S.......SS",
    ".......E.",
    ".......SS",
    ".......SS",
    ".......SS",
    ".......SS",
    ".......SS",
    ".......SS",
    ".......SS",
    "N.......N"
};

int playerX = WIDTH / 2;
int playerY = HEIGHT - 1;

void printMap() {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%c ", map[i][j]);
        }
        printf("\n");
    }
}

void movePlayer(char direction) {
    switch (direction) {
        case 'N': --playerY; break;
        case 'S': ++playerY; break;
        case 'E': ++playerX; break;
        case 'W': --playerX; break;
    }

    if (playerX < 0 || playerX >= WIDTH || playerY < 0 || playerY >= HEIGHT) {
        printf("Out of bounds!\n");
        playerX = WIDTH / 2;
        playerY = HEIGHT - 1;
    }
}

int checkWin() {
    return map[playerY][playerX] == 'E';
}

int main() {
    char input;
    while (!checkWin()) {
        printMap();
        printf("Enter direction (N, S, E, W): ");
        scanf("%c", &input);
        movePlayer(input);
    }
    printMap();
    printf("Congratulations! You've won the game!\n");
    return 0;
}
