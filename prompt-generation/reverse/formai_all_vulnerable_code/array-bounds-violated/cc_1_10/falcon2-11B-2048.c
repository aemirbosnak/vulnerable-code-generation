//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

typedef struct {
    int x;
    int y;
    int direction;
} PacMan;

void move(PacMan *pacman) {
    switch (pacman->direction) {
        case LEFT:
            pacman->x--;
            break;
        case RIGHT:
            pacman->x++;
            break;
        case UP:
            pacman->y--;
            break;
        case DOWN:
            pacman->y++;
            break;
    }
}

void eat(PacMan *pacman) {
    printf("Pac-Man ate a power pellet! Get ready for some ghost-hunting!\n");
}

int main() {
    PacMan pacman = {0, 0, RIGHT};
    char grid[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = '.';
        }
    }

    grid[pacman.x][pacman.y] = 'P';

    while (1) {
        printf("---------------------------------\n");
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
        printf("Pac-Man's direction: %d\n", pacman.direction);
        printf("Pac-Man's position: (%d, %d)\n", pacman.x, pacman.y);
        printf("Press 'q' to quit.\n");

        int ch;
        scanf("%c", &ch);

        if (ch == 'q') {
            break;
        }

        move(&pacman);
        if (grid[pacman.x][pacman.y] == 'P') {
            eat(&pacman);
        } else {
            grid[pacman.x][pacman.y] = 'P';
        }
    }

    return 0;
}