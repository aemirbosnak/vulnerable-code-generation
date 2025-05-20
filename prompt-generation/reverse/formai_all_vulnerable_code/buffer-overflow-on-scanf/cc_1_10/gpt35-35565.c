//FormAI DATASET v1.0 Category: Robot movement control ; Style: intelligent
#include <stdio.h>

// Defining constants for robot movement
#define FORWARD 1
#define BACKWARD 0
#define LEFT 1
#define RIGHT 0

// Function to move the robot forward or backward by a given distance
void moveForwardOrBackward(int distance, int direction) {
    if (direction == FORWARD) {
        printf("Moving robot forward by %d meters\n", distance);
    } else {
        printf("Moving robot backward by %d meters\n", distance);
    }
}

// Function to turn the robot left or right by an angle
void turnLeftOrRight(int angle, int direction) {
    if (direction == LEFT) {
        printf("Turning robot left by %d degrees\n", angle);
    } else {
        printf("Turning robot right by %d degrees\n", angle);
    }
}

// Main function to control the robot movement
int main() {
    int moveDistance, turnAngle;
    char moveDirection, turnDirection;
    
    printf("Welcome to the intelligent robot movement control system\n");
    printf("Please enter the direction of robot movement (F/B): ");
    scanf("%c", &moveDirection);
    printf("Please enter the distance of robot movement: ");
    scanf("%d", &moveDistance);
    printf("Please enter the direction of robot turning (L/R): ");
    scanf(" %c", &turnDirection);
    printf("Please enter the angle of robot turning: ");
    scanf("%d", &turnAngle);
    
    if (moveDirection == 'F') {
        moveForwardOrBackward(moveDistance, FORWARD);
    } else {
        moveForwardOrBackward(moveDistance, BACKWARD);
    }
    
    if (turnDirection == 'L') {
        turnLeftOrRight(turnAngle, LEFT);
    } else {
        turnLeftOrRight(turnAngle, RIGHT);
    }
    
    printf("Robot movement completed successfully\n");
    
    return 0;
}