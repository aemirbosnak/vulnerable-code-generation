//FormAI DATASET v1.0 Category: Robot movement control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

void moveForward();
void moveBackward();
void turnRight();
void turnLeft();
void stop();

int main() {
    char input;
    printf("Enter movement command (F)orward, (B)ackward, (R)ight turn, (L)eft turn, (S)top: \n");

    while (1) {
        scanf(" %c", &input);
        switch (input) {
            case 'F':
                moveForward();
                break;
            case 'B':
                moveBackward();
                break;
            case 'R':
                turnRight();
                break;
            case 'L':
                turnLeft();
                break;
            case 'S':
                stop();
                break;
            default:
                printf("Invalid command.\n");
        }

        printf("Enter movement command (F)orward, (B)ackward, (R)ight turn, (L)eft turn, (S)top: \n");
    }

    return 0;
}

void moveForward() {
    printf("Moving forward.\n");
    // Code for robot to move forward
}

void moveBackward() {
    printf("Moving backward.\n");
    // Code for robot to move backward
}

void turnRight() {
    printf("Turning right.\n");
    // Code for robot to turn right
}

void turnLeft() {
    printf("Turning left.\n");
    // Code for robot to turn left
}

void stop() {
    printf("Stopping.\n");
    // Code for robot to stop moving
}