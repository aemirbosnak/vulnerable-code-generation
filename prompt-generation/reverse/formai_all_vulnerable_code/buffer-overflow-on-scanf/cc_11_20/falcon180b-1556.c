//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define FORWARD 5
#define BACKWARD 6
#define STOP 7

int main() {
    int choice;
    int speed = 5;
    int direction = 0;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Press 1 to go forward, 2 to go backward, 3 to turn left, 4 to turn right, 5 to stop.\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case FORWARD:
                printf("Vehicle is moving forward.\n");
                break;
            case BACKWARD:
                printf("Vehicle is moving backward.\n");
                break;
            case LEFT:
                if (direction!= RIGHT) {
                    printf("Vehicle is turning left.\n");
                    direction = LEFT;
                } else {
                    printf("Cannot turn left while going right.\n");
                }
                break;
            case RIGHT:
                if (direction!= LEFT) {
                    printf("Vehicle is turning right.\n");
                    direction = RIGHT;
                } else {
                    printf("Cannot turn right while going left.\n");
                }
                break;
            case STOP:
                printf("Vehicle has stopped.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

        if (choice!= STOP) {
            if (direction == LEFT) {
                printf("Vehicle is moving left.\n");
            } else if (direction == RIGHT) {
                printf("Vehicle is moving right.\n");
            } else {
                printf("Vehicle is moving forward.\n");
            }

            speed += 5;
            if (speed > 50) {
                speed = 50;
            }

            printf("Current speed: %d\n", speed);
        } else {
            speed = 5;
        }

        printf("\n");
        fflush(stdin);
        fflush(stdout);
        sleep(1);
    }

    return 0;
}