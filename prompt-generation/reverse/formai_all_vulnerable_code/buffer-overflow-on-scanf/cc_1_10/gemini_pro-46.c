//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UP      'U'
#define DOWN    'D'
#define LEFT    'L'
#define RIGHT   'R'
#define QUIT    'Q'

typedef struct {
    int x;
    int y;
    char direction;
} drone;

void init_drone(drone *d) {
    d->x = 0;
    d->y = 0;
    d->direction = UP;
}

void move_drone(drone *d, char direction) {
    switch (direction) {
        case UP:
            d->y++;
            break;
        case DOWN:
            d->y--;
            break;
        case LEFT:
            d->x--;
            break;
        case RIGHT:
            d->x++;
            break;
    }
}

void print_drone(drone *d) {
    printf("Drone is at (%d, %d), facing %c\n", d->x, d->y, d->direction);
}

int main() {
    drone d;
    char input;

    init_drone(&d);

    while (1) {
        printf("Enter a command (U/D/L/R/Q): ");
        scanf(" %c", &input);

        switch (input) {
            case UP:
            case DOWN:
            case LEFT:
            case RIGHT:
                move_drone(&d, input);
                break;
            case QUIT:
                exit(0);
            default:
                printf("Invalid command\n");
                break;
        }

        print_drone(&d);
    }

    return 0;
}