//FormAI DATASET v1.0 Category: Robot movement control ; Style: creative
#include <stdio.h>

// Function to move the robot forward
void moveForward() {
    printf("Moving Forward\n");
}

// Function to move the robot backward
void moveBackward() {
    printf("Moving Backward\n");
}

// Function to turn the robot left
void turnLeft() {
    printf("Turning Left\n");
}

// Function to turn the robot right
void turnRight() {
    printf("Turning Right\n");
}

int main() {
    int command = 0;
    
    // Prompt user to enter a command
    printf("Enter a command (1 for Forward, 2 for Backward, 3 for Left, 4 for Right): ");
    scanf("%d", &command);
    
    // Switch case to determine which command was entered
    switch (command) {
        case 1:
            moveForward();
            break;
            
        case 2:
            moveBackward();
            break;
            
        case 3:
            turnLeft();
            break;
            
        case 4:
            turnRight();
            break;
            
        default:
            printf("Invalid command\n");
            break;
    }
    
    return 0;
}