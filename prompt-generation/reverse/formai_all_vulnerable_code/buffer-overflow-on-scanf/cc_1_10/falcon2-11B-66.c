//Falcon2-11B DATASET v1.0 Category: Robot movement control ; Style: innovative
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

#define FORWARD 1
#define BACKWARD 2
#define RIGHT 3
#define LEFT 4

// Function to move the robot forward
void moveForward(int steps) {
    int i;
    for (i = 0; i < steps; i++) {
        printf("Robot moves forward\n");
    }
}

// Function to move the robot backward
void moveBackward(int steps) {
    int i;
    for (i = 0; i < steps; i++) {
        printf("Robot moves backward\n");
    }
}

// Function to turn the robot right
void turnRight(int degrees) {
    int i;
    for (i = 0; i < degrees; i++) {
        printf("Robot turns right\n");
    }
}

// Function to turn the robot left
void turnLeft(int degrees) {
    int i;
    for (i = 0; i < degrees; i++) {
        printf("Robot turns left\n");
    }
}

int main() {
    int steps, degrees;
    char direction;

    // Get user input
    printf("Enter the number of steps to move forward: ");
    scanf("%d", &steps);
    printf("Enter the number of degrees to turn right: ");
    scanf("%d", &degrees);
    printf("Enter the direction (F for forward, B for backward, R for right, L for left): ");
    scanf(" %c", &direction);

    // Execute the corresponding action
    if (direction == 'F') {
        moveForward(steps);
    } else if (direction == 'B') {
        moveBackward(steps);
    } else if (direction == 'R') {
        turnRight(degrees);
    } else if (direction == 'L') {
        turnLeft(degrees);
    } else {
        printf("Invalid direction\n");
    }

    return 0;
}