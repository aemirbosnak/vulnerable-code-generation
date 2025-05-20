//FormAI DATASET v1.0 Category: Robot movement control ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isRobotIdle = false;

void rotateLeft() {
    printf("Rotating Left\n");
}

void rotateRight() {
    printf("Rotating Right\n");
}

void moveForward() {
    printf("Moving Forward\n");
}

void moveBackward() {
    printf("Moving Backward\n");
}

int main() {
    int instruction;
    printf("Enter 1 to rotate left, 2 to rotate right, 3 to move forward, 4 to move backward and 5 to exit: \n");
    scanf("%d", &instruction);

    while(instruction != 5) {
        switch(instruction) {
            case 1:
                rotateLeft();
                break;
            case 2:
                rotateRight();
                break;
            case 3:
                if(!isRobotIdle) {
                    moveForward();
                } else {
                    printf("Robot is idle. Move not initiated.\n");
                }
                break;
            case 4:
                if(!isRobotIdle) {
                    moveBackward();
                } else {
                    printf("Robot is idle. Move not initiated.\n");
                }
                break;
            default:
                printf("Invalid instruction! Enter a valid instruction.\n");
                break;
        }

        printf("Enter 1 to rotate left, 2 to rotate right, 3 to move forward, 4 to move backward and 5 to exit: \n");
        scanf("%d", &instruction);
    }

    return 0;
}