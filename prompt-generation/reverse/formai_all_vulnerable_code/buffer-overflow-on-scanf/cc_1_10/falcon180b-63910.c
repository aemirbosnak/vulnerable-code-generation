//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define ACCELERATION 5
#define DECELERATION 1

#define UP 'w'
#define DOWN's'
#define LEFT 'a'
#define RIGHT 'd'

void move(int direction, int speed) {
    printf("Moving %c at %d km/h\n", direction, speed);
}

int main() {
    srand(time(0));
    int speed = MIN_SPEED;
    char direction;

    while (1) {
        printf("Enter a direction (w, a, s, d) or 0 to stop: ");
        scanf("%c", &direction);

        if (direction == 0) {
            break;
        }

        if (direction == UP || direction == DOWN || direction == LEFT || direction == RIGHT) {
            if (speed >= MAX_SPEED) {
                printf("Vehicle is already at maximum speed.\n");
            } else if (speed <= MIN_SPEED) {
                printf("Vehicle is already at minimum speed.\n");
            } else {
                if (direction == UP || direction == DOWN) {
                    speed += ACCELERATION;
                } else {
                    speed += DECELERATION;
                }
                printf("Accelerating to %d km/h\n", speed);
            }
        }

        move(direction, speed);
    }

    return 0;
}