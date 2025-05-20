//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAP_SIZE 10
#define PLAYER_SIZE 1

typedef struct Player {
    int x, y;
    char direction;
} Player;

void initializePlayer(Player *p) {
    p->x = 0;
    p->y = 0;
    p->direction = 'N';
}

void movePlayer(Player *p, char direction) {
    switch (direction) {
        case 'N':
            p->y--;
            break;
        case 'S':
            p->y++;
            break;
        case 'E':
            p->x++;
            break;
        case 'W':
            p->x--;
            break;
    }
}

void drawMap(Player *p) {
    for (int y = 0; y < MAP_SIZE; y++) {
        for (int x = 0; x < MAP_SIZE; x++) {
            if (x == p->x && y == p->y) {
                printf("P ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    Player player;
    initializePlayer(&player);

    char input;

    while (1) {
        drawMap(&player);
        printf("Enter direction (N/S/E/W): ");
        scanf("%c", &input);

        movePlayer(&player, input);

        if (input == 'q') {
            break;
        }
    }

    return 0;
}