//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define ACCELERATION 1
#define DECELERATION 1

int main() {
    int speed = MIN_SPEED;
    int direction = 1;
    int turn = 0;
    int turn_speed = 5;
    int turn_direction = 1;
    int choice;
    int running = 1;

    printf("Welcome to the Sherlock Holmes Remote Control Vehicle Simulator\n");
    printf("Press 1 to start the vehicle\n");
    scanf("%d", &choice);

    if (choice == 1) {
        running = 1;
        while (running) {
            printf("Current speed: %d\n", speed);
            printf("Current direction: %d\n", direction);
            printf("Current turn: %d\n", turn);
            printf("Press 1 to accelerate\n");
            printf("Press 2 to decelerate\n");
            printf("Press 3 to turn left\n");
            printf("Press 4 to turn right\n");
            printf("Press 5 to stop\n");
            scanf("%d", &choice);

            if (choice == 1) {
                if (speed < MAX_SPEED) {
                    speed += ACCELERATION;
                    printf("Accelerating... Current speed: %d\n", speed);
                } else {
                    printf("Cannot accelerate further.\n");
                }
            } else if (choice == 2) {
                if (speed > MIN_SPEED) {
                    speed -= DECELERATION;
                    printf("Decelerating... Current speed: %d\n", speed);
                } else {
                    printf("Cannot decelerate further.\n");
                }
            } else if (choice == 3) {
                turn_direction = -1;
                printf("Turning left...\n");
            } else if (choice == 4) {
                turn_direction = 1;
                printf("Turning right...\n");
            } else if (choice == 5) {
                printf("Stopping...\n");
                running = 0;
            }
        }
    } else {
        printf("Exiting program...\n");
    }

    return 0;
}