//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: single-threaded
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
#define TURN_LEFT 8
#define TURN_RIGHT 9
#define MAX_SPEED 10

// Function to move the vehicle
void move(int direction, int speed) {
    if (direction == FORWARD) {
        printf("Vehicle is moving forward with speed %d\n", speed);
    } else if (direction == BACKWARD) {
        printf("Vehicle is moving backward with speed %d\n", speed);
    } else if (direction == LEFT) {
        printf("Vehicle is turning left with speed %d\n", speed);
    } else if (direction == RIGHT) {
        printf("Vehicle is turning right with speed %d\n", speed);
    }
}

// Function to simulate the remote control
void remote_control() {
    int choice;
    printf("Enter your choice:\n");
    printf("1. Move forward\n");
    printf("2. Move backward\n");
    printf("3. Turn left\n");
    printf("4. Turn right\n");
    printf("5. Stop\n");
    scanf("%d", &choice);

    switch (choice) {
        case FORWARD:
            move(FORWARD, MAX_SPEED);
            break;
        case BACKWARD:
            move(BACKWARD, MAX_SPEED);
            break;
        case LEFT:
            move(LEFT, MAX_SPEED);
            break;
        case RIGHT:
            move(RIGHT, MAX_SPEED);
            break;
        case STOP:
            move(STOP, 0);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
}

int main() {
    srand(time(NULL));

    int choice;
    do {
        remote_control();
        printf("Press enter to continue...\n");
        scanf("%d", &choice);
    } while (choice!= STOP);

    return 0;
}