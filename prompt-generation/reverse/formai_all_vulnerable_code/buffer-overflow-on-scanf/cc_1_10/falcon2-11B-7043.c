//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to move the robot in a specific direction
void moveRobot(int direction) {
    if (direction == 1) { // Forward
        printf("Robot is moving forward\n");
    } else if (direction == 2) { // Backward
        printf("Robot is moving backward\n");
    } else if (direction == 3) { // Left
        printf("Robot is moving left\n");
    } else if (direction == 4) { // Right
        printf("Robot is moving right\n");
    } else {
        printf("Invalid direction\n");
    }
}

// Function to control the robot
void controlRobot() {
    int direction;
    printf("Enter the direction of movement: ");
    scanf("%d", &direction);
    moveRobot(direction);
}

// Function to stop the robot
void stopRobot() {
    printf("Robot is stopped\n");
}

// Function to move the robot in a random direction
void moveRobotRandom() {
    int direction;
    do {
        direction = rand() % 4 + 1; // Random direction between 1 and 4
        moveRobot(direction);
    } while (direction!= 1 && direction!= 2 && direction!= 3 && direction!= 4);
}

int main() {
    int option;
    printf("1. Control Robot\n2. Move Robot Randomly\n3. Stop Robot\n");
    printf("Enter your choice: ");
    scanf("%d", &option);
    switch (option) {
        case 1:
            controlRobot();
            break;
        case 2:
            moveRobotRandom();
            break;
        case 3:
            stopRobot();
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}