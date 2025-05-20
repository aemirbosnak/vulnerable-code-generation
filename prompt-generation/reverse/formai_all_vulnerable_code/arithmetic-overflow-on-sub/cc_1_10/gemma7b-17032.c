//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define PACMAN_SIZE 5

typedef struct Pacman {
    int x;
    int y;
    int direction;
} Pacman;

Pacman pacman;

void drawMap() {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (x == pacman.x && y == pacman.y) {
                printf("O ");
            } else if (x == 0 || y == 0) {
                printf("X ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void movePacman() {
    switch (pacman.direction) {
        case 0:
            pacman.x--;
            break;
        case 1:
            pacman.y--;
            break;
        case 2:
            pacman.x++;
            break;
        case 3:
            pacman.y++;
            break;
    }
}

void updatePacman() {
    movePacman();
    drawMap();
}

int main() {
    pacman.x = 5;
    pacman.y = 5;
    pacman.direction = 0;

    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        updatePacman();
        sleep(0.1);
    }

    return 0;
}