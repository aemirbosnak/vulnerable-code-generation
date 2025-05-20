//Gemma-7B DATASET v1.0 Category: Space Invaders Game Clone ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEFT_BOUND 0
#define RIGHT_BOUND 50

#define UP_BOUND 0
#define DOWN_BOUND 20

#define BULLET_SPEED 5
#define SHIP_SPEED 3

typedef struct Ship {
    int x, y;
    int direction;
    int lives;
} Ship;

Ship ship;
int bullets[10] = {0};
int bullet_index = 0;

void initialize_ship() {
    ship.x = RIGHT_BOUND / 2;
    ship.y = DOWN_BOUND - 1;
    ship.direction = 1;
    ship.lives = 3;
}

void draw_ship() {
    printf("o ");
    for (int i = ship.x; i < ship.x + 3; i++) {
        printf("=");
    }
    printf("\n");
}

void move_ship() {
    switch (ship.direction) {
        case 1:
            ship.x++;
            break;
        case 2:
            ship.x--;
            break;
        case 3:
            ship.y--;
            break;
        case 4:
            ship.y++;
            break;
    }

    if (ship.x < LEFT_BOUND) {
        ship.direction = 2;
    } else if (ship.x > RIGHT_BOUND) {
        ship.direction = 1;
    }

    if (ship.y < UP_BOUND) {
        ship.direction = 4;
    } else if (ship.y > DOWN_BOUND) {
        ship.direction = 3;
    }
}

void shoot() {
    bullets[bullet_index] = 1;
    bullet_index++;
}

void update_bullets() {
    for (int i = 0; i < bullet_index; i++) {
        if (bullets[i] == 1) {
            bullets[i] = 0;
            // Move bullet
        }
    }
}

int main() {
    initialize_ship();

    // Game loop
    while (ship.lives > 0) {
        draw_ship();

        update_bullets();

        move_ship();

        if (rand() % 100 < 5) {
            shoot();
        }

        printf("Lives: %d\n", ship.lives);
    }

    printf("Game Over!\n");

    return 0;
}