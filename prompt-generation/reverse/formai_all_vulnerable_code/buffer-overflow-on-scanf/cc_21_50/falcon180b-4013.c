//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4
#define STOP 5

int main() {
    int choice;
    int speed = 0;
    int direction = STOP;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Please choose an option:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Stop\n");

    scanf("%d", &choice);

    switch (choice) {
        case FORWARD:
            speed = 10;
            direction = FORWARD;
            break;
        case BACKWARD:
            speed = -10;
            direction = BACKWARD;
            break;
        case LEFT:
            speed = -5;
            direction = LEFT;
            break;
        case RIGHT:
            speed = 5;
            direction = RIGHT;
            break;
        case STOP:
            speed = 0;
            direction = STOP;
            break;
        default:
            printf("Invalid choice.\n");
            return 0;
    }

    while (1) {
        printf("Current speed: %d, direction: %d\n", speed, direction);
        if (direction == FORWARD) {
            printf("Moving forward...\n");
        } else if (direction == BACKWARD) {
            printf("Moving backward...\n");
        } else if (direction == LEFT) {
            printf("Turning left...\n");
        } else if (direction == RIGHT) {
            printf("Turning right...\n");
        } else {
            printf("Stopped.\n");
        }

        if (speed > 0) {
            speed--;
        } else if (speed < 0) {
            speed++;
        }

        if (speed == 0) {
            printf("Vehicle stopped.\n");
            break;
        }

        if (direction == FORWARD && speed > 0) {
            printf("Moving forward...\n");
        } else if (direction == BACKWARD && speed < 0) {
            printf("Moving backward...\n");
        } else if (direction == LEFT && speed < 0) {
            printf("Turning left...\n");
        } else if (direction == RIGHT && speed > 0) {
            printf("Turning right...\n");
        }

        if (speed > 0) {
            printf("Current position: %d\n", speed);
            speed++;
        } else if (speed < 0) {
            printf("Current position: %d\n", speed);
            speed--;
        }

        sleep(1);
    }

    return 0;
}