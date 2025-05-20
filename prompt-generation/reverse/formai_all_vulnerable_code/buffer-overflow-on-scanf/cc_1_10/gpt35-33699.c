//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_HEIGHT 100
#define MAX_ANGLE 45

typedef struct {
    int height;
    int angle;
} Drone;

void moveUp(Drone *d);
void moveDown(Drone *d);
void moveLeft(Drone *d);
void moveRight(Drone *d);

int main() {
    Drone d;
    int input;

    d.height = 0;
    d.angle = 0;

    printf("Welcome to the Drone Remote Control!\n");
    printf("Press 1 to move up\n");
    printf("Press 2 to move down\n");
    printf("Press 3 to move left\n");
    printf("Press 4 to move right\n");
    printf("Press 5 to exit\n");

    while (1) {
        printf("Current height: %d meters\n", d.height);
        printf("Current angle: %d degrees\n", d.angle);

        scanf("%d", &input);

        switch (input) {
            case 1:
                moveUp(&d);
                break;
            case 2:
                moveDown(&d);
                break;
            case 3:
                moveLeft(&d);
                break;
            case 4:
                moveRight(&d);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid input!\n");
                break;
        }
    }
    return 0;
}

void moveUp(Drone *d) {
    if (d->height >= MAX_HEIGHT) {
        printf("The drone cannot go any higher!\n");
    } else {
        d->height++;
        printf("The drone moves up to %d meters.\n", d->height);
    }
}

void moveDown(Drone *d) {
    if (d->height <= 0) {
        printf("The drone cannot go any lower!\n");
    } else {
        d->height--;
        printf("The drone moves down to %d meters.\n", d->height);
    }
}

void moveLeft(Drone *d) {
    if (d->angle >= MAX_ANGLE) {
        printf("The drone cannot turn any further left!\n");
    } else {
        d->angle++;
        printf("The drone turns left to %d degrees.\n", d->angle);
    }
}

void moveRight(Drone *d) {
    if (d->angle <= -MAX_ANGLE) {
        printf("The drone cannot turn any further right!\n");
    } else {
        d->angle--;
        printf("The drone turns right to %d degrees.\n", d->angle);
    }
}