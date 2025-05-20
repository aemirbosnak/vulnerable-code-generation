//FormAI DATASET v1.0 Category: Robot movement control ; Style: active
#include <stdio.h>

// Function for moving the robot forward
void moveForward(int distance) {
    printf("Moving forward %d meters\n", distance);
}

// Function for moving the robot backward
void moveBackward(int distance) {
    printf("Moving backward %d meters\n", distance);
}

// Function for turning the robot left
void turnLeft(int degrees) {
    printf("Turning left %d degrees\n", degrees);
}

// Function for turning the robot right
void turnRight(int degrees) {
    printf("Turning right %d degrees\n", degrees);
}

// Main function for controlling the robot
int main() {
    printf("Welcome to the robot movement control program!\n");

    // Prompt the user for input
    printf("Enter a command (f for forward, b for backward, l for left, r for right, and q to quit):\n");

    // Loop until the user quits
    while (1) {
        // Get the user's input
        char input;
        scanf(" %c", &input);

        // Check which command the user entered
        if (input == 'f') {
            // If the user entered 'f', move the robot forward
            int distance;
            printf("Enter the distance to move forward (in meters):\n");
            scanf("%d", &distance);
            moveForward(distance);
        } else if (input == 'b') {
            // If the user entered 'b', move the robot backward
            int distance;
            printf("Enter the distance to move backward (in meters):\n");
            scanf("%d", &distance);
            moveBackward(distance);
        } else if (input == 'l') {
            // If the user entered 'l', turn the robot left
            int degrees;
            printf("Enter the number of degrees to turn left:\n");
            scanf("%d", &degrees);
            turnLeft(degrees);
        } else if (input == 'r') {
            // If the user entered 'r', turn the robot right
            int degrees;
            printf("Enter the number of degrees to turn right:\n");
            scanf("%d", &degrees);
            turnRight(degrees);
        } else if (input == 'q') {
            // If the user entered 'q', quit the program
            printf("Goodbye!\n");
            break;
        } else {
            // If the user entered an invalid command, prompt the user again
            printf("Invalid command, please try again (f for forward, b for backward, l for left, r for right, and q to quit):\n");
        }
    }

    return 0;
}