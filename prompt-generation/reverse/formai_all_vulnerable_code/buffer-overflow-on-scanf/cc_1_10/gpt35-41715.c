//FormAI DATASET v1.0 Category: Robot movement control ; Style: configurable
#include <stdio.h>

// Define robot movement control commands
#define FORWARD 1
#define BACKWARD 2
#define LEFT 3
#define RIGHT 4

// Define robot speed control commands
#define SLOW 1
#define MEDIUM 2
#define FAST 3

// Initialize default settings
int speed = MEDIUM;
int rotation = RIGHT;

// Function to move the robot forward
void moveForward() {
    printf("Moving forward at speed ");
    if (speed == SLOW) {
        printf("slow");
    } else if (speed == MEDIUM) {
        printf("medium");
    } else {
        printf("fast");
    }
    printf("\n");
}

// Function to move the robot backward
void moveBackward() {
    printf("Moving backward at speed ");
    if (speed == SLOW) {
        printf("slow");
    } else if (speed == MEDIUM) {
        printf("medium");
    } else {
        printf("fast");
    }
    printf("\n");
}

// Function to turn the robot left
void turnLeft() {
    printf("Turning left\n");
}

// Function to turn the robot right
void turnRight() {
    printf("Turning right\n");
}

int main() {
    // Prompt user for input
    printf("Welcome to Robot Movement Control System\n");
    printf("Please choose a speed (1=slow, 2=medium, 3=fast): ");
    scanf("%d", &speed);
    printf("Please choose a rotation direction (1=left, 2=right): ");
    scanf("%d", &rotation);

    // Execute robot movement commands based on user input
    if (rotation == LEFT) {
        turnLeft();
    } else {
        turnRight();
    }

    moveForward();

    moveBackward();

    // End program
    printf("Program complete.");
    return 0;
}