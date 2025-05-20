//FormAI DATASET v1.0 Category: Robot movement control ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the constants
#define ROBOT_STEP 1
#define MAX_SPEED 10
#define MIN_SPEED 0

// Define the functions
void moveForward(int speed);
void moveBackward(int speed);
void stopRobot();
void turnLeft();
void turnRight();

// Define the variables
int heading = 0;   // 0 - North, 1 - West, 2 - South, 3 - East
int speed = 0;
bool isMoving = false;

int main() {
    char input;

    // Welcome the user
    printf("Welcome to the Robot Movement Control Program!\n\n");

    // Loop until the user quits
    while (true) {
        printf("Press the following keys to control the robot:\n");
        printf("w - Move Forward, s - Move Backward\n");
        printf("a - Turn Left, d - Turn Right\n");
        printf("q - Stop Robot, x - Exit Program\n");

        // Read the user input
        scanf(" %c", &input);

        // Determine the action based on the user input
        switch (input) {
            case 'w':
                moveForward(speed);
                break;

            case 's':
                moveBackward(speed);
                break;

            case 'a':
                turnLeft();
                break;

            case 'd':
                turnRight();
                break;

            case 'q':
                stopRobot();
                break;

            case 'x':
                printf("Goodbye!\n");
                return 0;

            default:
                printf("Invalid input, please try again.\n");
                break;
        }

        // Check if the robot is currently moving
        if (isMoving) {
            switch (heading) {
                case 0:
                    printf("Robot is moving North.\n");
                    break;

                case 1:
                    printf("Robot is moving West.\n");
                    break;

                case 2:
                    printf("Robot is moving South.\n");
                    break;

                case 3:
                    printf("Robot is moving East.\n");
                    break;
            }
        }
    }

    return 0;
}

// Function that moves the robot forward
void moveForward(int speed) {
    if (speed < MIN_SPEED || speed > MAX_SPEED) {
        printf("Invalid speed, please try again.\n");
        return;
    }

    printf("Moving the robot forward at speed %d.\n", speed);

    // Update the state
    isMoving = true;
}

// Function that moves the robot backward
void moveBackward(int speed) {
    if (speed < MIN_SPEED || speed > MAX_SPEED) {
        printf("Invalid speed, please try again.\n");
        return;
    }

    printf("Moving the robot backward at speed %d.\n", speed);

    // Update the state
    isMoving = true;
}

// Function that stops the robot
void stopRobot() {
    printf("Stopping the robot.\n");

    // Update the state
    isMoving = false;
}

// Function that turns the robot left
void turnLeft() {
    heading = (heading + 1) % 4;

    printf("Turning the robot left, now facing ");

    switch (heading) {
        case 0:
            printf("North.\n");
            break;

        case 1:
            printf("West.\n");
            break;

        case 2:
            printf("South.\n");
            break;

        case 3:
            printf("East.\n");
            break;
    }
}

// Function that turns the robot right
void turnRight() {
    heading = (heading - 1 + 4) % 4;

    printf("Turning the robot right, now facing ");

    switch (heading) {
        case 0:
            printf("North.\n");
            break;

        case 1:
            printf("West.\n");
            break;

        case 2:
            printf("South.\n");
            break;

        case 3:
            printf("East.\n");
            break;
    }
}