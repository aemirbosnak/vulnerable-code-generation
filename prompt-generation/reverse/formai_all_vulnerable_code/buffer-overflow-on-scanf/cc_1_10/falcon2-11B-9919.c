//Falcon2-11B DATASET v1.0 Category: Pac-Man Game Clone ; Style: standalone
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

enum direction {
    LEFT,
    RIGHT,
    UP,
    DOWN
};

struct position {
    int x;
    int y;
};

struct ghost {
    struct position position;
    int health;
};

void move_left(struct position *position) {
    position->x--;
}

void move_right(struct position *position) {
    position->x++;
}

void move_up(struct position *position) {
    position->y--;
}

void move_down(struct position *position) {
    position->y++;
}

void update_ghost_health(struct ghost *ghost) {
    if (ghost->health < 4) {
        ghost->health++;
    }
}

void display_ghost(struct ghost *ghost) {
    printf("Health: %d\n", ghost->health);
}

int main() {
    struct position pacman_position = {0, 0};
    struct ghost ghost = { { 0, 0 }, 4 };

    while (true) {
        printf("Pac-Man's position: (%d, %d)\n", pacman_position.x, pacman_position.y);
        display_ghost(&ghost);

        printf("Choose a direction: 1. Left, 2. Right, 3. Up, 4. Down\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_left(&pacman_position);
                break;
            case 2:
                move_right(&pacman_position);
                break;
            case 3:
                move_up(&pacman_position);
                break;
            case 4:
                move_down(&pacman_position);
                break;
            default:
                printf("Invalid choice!\n");
        }

        update_ghost_health(&ghost);
    }

    return 0;
}