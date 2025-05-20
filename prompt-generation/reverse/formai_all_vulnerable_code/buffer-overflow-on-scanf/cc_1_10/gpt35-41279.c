//FormAI DATASET v1.0 Category: Robot movement control ; Style: optimized
#include <stdio.h>

// Define constants for robot movement
#define FORWARD 1
#define BACKWARD -1
#define LEFT 2
#define RIGHT -2

// Function to move robot forward
void moveForward() {
    printf("Moving forward...\n");
}

// Function to move robot backward
void moveBackward() {
    printf("Moving backward...\n");
}

// Function to turn robot left
void turnLeft() {
    printf("Turning left...\n");
}

// Function to turn robot right
void turnRight() {
    printf("Turning right...\n");
}

// Function to stop robot movement
void stopMovement() {
    printf("Stopping robot movement...\n");
}

// Main function
int main() {
    int moveDirection = FORWARD; // Set initial movement direction
    
    // Loop until user enters 'q' to quit
    while (1) {
        // Print movement options
        printf("\nChoose a movement direction:\n");
        printf("1. Forward\n2. Backward\n3. Left\n4. Right\n");
        
        // Read user input
        char input;
        scanf(" %c", &input);
        
        // Determine movement direction based on user input
        switch (input) {
            case '1':
                moveDirection = FORWARD;
                break;
            case '2':
                moveDirection = BACKWARD;
                break;
            case '3':
                moveDirection = LEFT;
                break;
            case '4':
                moveDirection = RIGHT;
                break;
            case 'q':
                stopMovement();
                return 0;
                break; // Optional break statement
            default:
                printf("Invalid input\n");
                continue; // Restart loop
        }
        
        // Move the robot in the given direction
        switch (moveDirection) {
            case FORWARD:
                moveForward();
                break;
            case BACKWARD:
                moveBackward();
                break;
            case LEFT:
                turnLeft();
                break;
            case RIGHT:
                turnRight();
                break;
            default:
                printf("Invalid direction\n");
                break;
        }
    }
}