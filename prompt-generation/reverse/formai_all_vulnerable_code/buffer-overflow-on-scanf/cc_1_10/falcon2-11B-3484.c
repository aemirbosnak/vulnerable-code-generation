//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Structure to represent the robot
struct Robot {
    int x;
    int y;
    int vx;
    int vy;
    int ax;
    int ay;
};

// Function to move the robot forward
void moveForward(struct Robot *robot) {
    robot->x += robot->vx;
    robot->y += robot->vy;
}

// Function to move the robot backward
void moveBackward(struct Robot *robot) {
    robot->x -= robot->vx;
    robot->y -= robot->vy;
}

// Function to turn the robot left
void turnLeft(struct Robot *robot) {
    robot->ax = -1 * robot->ax;
    robot->ay = -1 * robot->ay;
}

// Function to turn the robot right
void turnRight(struct Robot *robot) {
    robot->ax = robot->ax * -1;
    robot->ay = robot->ay * -1;
}

// Function to move the robot in a direction
void moveDirection(struct Robot *robot, int direction) {
    if (direction == 0) {
        moveForward(robot);
    } else if (direction == 1) {
        moveBackward(robot);
    } else if (direction == 2) {
        turnLeft(robot);
    } else if (direction == 3) {
        turnRight(robot);
    } else {
        printf("Invalid direction\n");
    }
}

int main() {
    struct Robot robot;
    robot.x = 0;
    robot.y = 0;
    robot.vx = 0;
    robot.vy = 0;
    robot.ax = 0;
    robot.ay = 0;

    while (1) {
        printf("Enter direction (0-3): ");
        int direction;
        scanf("%d", &direction);
        moveDirection(&robot, direction);
    }

    return 0;
}