//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 20
#define PAC_MAN_SIZE 5

typedef struct Pacman {
    int x;
    int y;
    int direction;
} Pacman;

Pacman pacman;

void drawBoard() {
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (x == pacman.x && y == pacman.y) {
                printf("O");
            } else if (x % 2 == 0 && y % 2 == 0) {
                printf("#");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

void movePacman() {
    switch (pacman.direction) {
        case 0:
            pacman.y--;
            break;
        case 1:
            pacman.x++;
            break;
        case 2:
            pacman.y++;
            break;
        case 3:
            pacman.x--;
            break;
    }

    if (pacman.x < 0 || pacman.x >= BOARD_SIZE - PAC_MAN_SIZE) {
        pacman.direction = (pacman.direction + 1) % 4;
    }

    if (pacman.y < 0 || pacman.y >= BOARD_SIZE - PAC_MAN_SIZE) {
        pacman.direction = (pacman.direction + 1) % 4;
    }
}

int main() {
    pacman.x = BOARD_SIZE / 2;
    pacman.y = BOARD_SIZE / 2;
    pacman.direction = 0;

    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        movePacman();
        drawBoard();
        sleep(0.1);
    }

    return 0;
}