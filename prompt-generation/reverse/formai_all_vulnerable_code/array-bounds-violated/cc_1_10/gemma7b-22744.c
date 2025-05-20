//Gemma-7B DATASET v1.0 Category: Pac-Man Game Clone ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE 20
#define PACMAN_SIZE 4

typedef struct Pacman {
    int x;
    int y;
    int direction;
} Pacman;

Pacman pacman;
int map[MAP_SIZE][MAP_SIZE];

void initialize_map() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = 0;
        }
    }
    map[ pacman.x ][pacman.y] = PACMAN_SIZE;
}

void draw_map() {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (map[i][j] == PACMAN_SIZE) {
                printf("P ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void move_pacman() {
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

    if (map[pacman.x][pacman.y] == 1) {
        pacman.direction = (pacman.direction + 1) % 4;
    }
}

int main() {
    initialize_map();
    draw_map();
    move_pacman();
    draw_map();

    return 0;
}