//FormAI DATASET v1.0 Category: Robot movement control ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

// Function to move the robot forward
void moveForward(int distance) {
    printf("Moving forward %d units...\n", distance);
    // Code to move the robot forward
}

// Function to move the robot backward
void moveBackward(int distance) {
    printf("Moving backward %d units...\n", distance);
    // Code to move the robot backward
}

// Function to turn the robot left
void turnLeft(int angle) {
    printf("Turning left %d degrees...\n", angle);
    // Code to turn the robot left
}

// Function to turn the robot right
void turnRight(int angle) {
    printf("Turning right %d degrees...\n", angle);
    // Code to turn the robot right
}

int main() {
    int distance, angle;

    printf("Welcome to the Robot Movement Control Program!\n");

    // Prompt the user to enter the distance they want the robot to move
    printf("Please enter the distance you want the robot to move: ");
    scanf("%d", &distance);

    // Move the robot forward the specified distance
    moveForward(distance);

    // Prompt the user to enter the distance they want the robot to move backwards
    printf("Please enter the distance you want the robot to move backwards: ");
    scanf("%d", &distance);

    // Move the robot backwards the specified distance
    moveBackward(distance);

    // Prompt the user to enter the angle they want the robot to turn left
    printf("Please enter the angle you want the robot to turn left: ");
    scanf("%d", &angle);

    // Turn the robot left the specified angle
    turnLeft(angle);

    // Prompt the user to enter the angle they want the robot to turn right
    printf("Please enter the angle you want the robot to turn right: ");
    scanf("%d", &angle);

    // Turn the robot right the specified angle
    turnRight(angle);

    return 0;
}