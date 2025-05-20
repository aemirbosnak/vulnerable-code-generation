//FormAI DATASET v1.0 Category: Robot movement control ; Style: portable
#include <stdio.h>

// Function to move robot forward
void moveForward(int distance) {
    printf("Moving robot forward by %d meters...\n", distance);
}

// Function to move robot backward
void moveBackward(int distance) {
    printf("Moving robot backward by %d meters...\n", distance);
}

// Function to turn robot left
void turnLeft(int degree) {
    printf("Turning robot left by %d degrees...\n", degree);
}

// Function to turn robot right
void turnRight(int degree) {
    printf("Turning robot right by %d degrees...\n", degree);
}

int main() {
    char choice;

    // Loop until user wants to exit
    while (1) {
        printf("\nWhat do you want to do?\n");
        printf("F - Move robot forward\n");
        printf("B - Move robot backward\n");
        printf("L - Turn robot left\n");
        printf("R - Turn robot right\n");
        printf("E - Exit program\n");

        // Take user choice
        scanf(" %c", &choice);

        switch (choice) {
            case 'F':
                moveForward(5); // Move robot forward by 5 meters
                break;
            case 'B':
                moveBackward(5); // Move robot backward by 5 meters
                break;
            case 'L':
                turnLeft(90); // Turn robot left by 90 degrees
                break;
            case 'R':
                turnRight(90); // Turn robot right by 90 degrees
                break;
            case 'E':
                printf("Exiting program...\n");
                return 0; // Exit program
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}