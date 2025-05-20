//FormAI DATASET v1.0 Category: Robot movement control ; Style: portable
#include <stdio.h>
#include <stdbool.h>

#define MOVE_FORWARD 1
#define MOVE_BACKWARD 2
#define TURN_LEFT 3
#define TURN_RIGHT 4
#define STOP 5

int main() {
    int command;
    bool isMoving = false;
    printf("Welcome to the Robot Movement Control Program!\n");

    while (true) {
        printf("\nEnter the command number to move the robot:\n");
        printf("1 - Move Forward\n2 - Move Backward\n3 - Turn Left\n4 - Turn Right\n5 - Stop\n");
        scanf("%d", &command);

        switch (command) {
            case MOVE_FORWARD:
                if (isMoving) {
                    printf("Robot is already moving forward\n");
                } else {
                    printf("Robot is moving forward\n");
                    isMoving = true;
                }
                break;
            case MOVE_BACKWARD:
                if (isMoving) {
                    printf("Robot is already moving backward\n");
                } else {
                    printf("Robot is moving backward\n");
                    isMoving = true;
                }
                break;
            case TURN_LEFT:
                if (isMoving) {
                    printf("Robot is turning left\n");
                } else {
                    printf("Robot cannot turn left while stationary\n");
                }
                break;
            case TURN_RIGHT:
                if (isMoving) {
                    printf("Robot is turning right\n");
                } else {
                    printf("Robot cannot turn right while stationary\n");
                }
                break;
            case STOP:
                if (isMoving) {
                    printf("Robot is stopping\n");
                    isMoving = false;
                } else {
                    printf("Robot is already stopped\n");
                }
                break;
            default:
                printf("Invalid command\n");
                break;
        }
    }

    return 0;
}