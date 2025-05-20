//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define PAC_SIZE 5

typedef struct Pacman {
    int x;
    int y;
    int dir;
} Pacman;

Pacman pac;

void draw_map() {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (x == pac.x && y == pac.y) {
                printf("O ");
            } else if (x == 0 || x == MAP_SIZE - 1) {
                printf("|| ");
            } else if (y == 0) {
                printf("|| ");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

void move_pacman() {
    switch (pac.dir) {
        case 0:
            pac.x--;
            break;
        case 1:
            pac.x++;
            break;
        case 2:
            pac.y--;
            break;
        case 3:
            pac.y++;
            break;
    }
}

void update_pacman() {
    move_pacman();
    draw_map();
}

int main() {
    pac.x = MAP_SIZE / 2;
    pac.y = MAP_SIZE - 1;
    pac.dir = 0;

    time_t t = time(NULL);
    while (time(NULL) - t < 10) {
        update_pacman();
        sleep(0.1);
    }

    return 0;
}