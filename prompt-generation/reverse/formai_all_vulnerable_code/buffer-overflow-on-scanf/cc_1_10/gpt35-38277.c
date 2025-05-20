//FormAI DATASET v1.0 Category: Robot movement control ; Style: high level of detail
// C Robot Movement Control Example Program

// Libraries
#include <stdio.h>
#include <stdlib.h>

// Function to move robot forward
void moveForward() {
    printf("Robot is moving forward...\n");
}

// Function to move robot backward
void moveBackward() {
    printf("Robot is moving backward...\n");
}

// Function to turn robot left
void turnLeft() {
    printf("Robot is turning left...\n");
}

// Function to turn robot right
void turnRight() {
    printf("Robot is turning right...\n");
}

// Main function
int main() {
    // Initialize variables
    char input;
    int movementCount = 0;
    
    printf("*** C Robot Movement Control Program ***\n");
    
    do {
        // Display robot movements
        printf("\nRobot Movements:\n1. Forward\n2. Backward\n3. Turn Left\n4. Turn Right\n\nEnter your movement (1-4): ");
    
        // Read input from user
        scanf(" %c", &input);
        
        // Switch case to execute specific movements based on user input
        switch(input) {
            case '1':
                moveForward();
                movementCount++;
                break;
            case '2':
                moveBackward();
                movementCount++;
                break;
            case '3':
                turnLeft();
                movementCount++;
                break;
            case '4':
                turnRight();
                movementCount++;
                break;
            default:
                printf("Invalid input! Please enter a number from 1 to 4.\n");
        }
        
        // Display movement count
        printf("Total movements: %d\n", movementCount);
        
    } while(input != 'q'); // Exit loop when user enters 'q'
    
    printf("\n*** Program ended. ***\n");
    
    return 0;
}

// End of code