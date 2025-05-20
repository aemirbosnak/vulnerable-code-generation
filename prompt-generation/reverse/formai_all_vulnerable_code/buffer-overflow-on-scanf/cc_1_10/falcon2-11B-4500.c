//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to move the vehicle forward
void moveForward() {
    printf("Vehicle is moving forward...\n");
}

// Function to move the vehicle backward
void moveBackward() {
    printf("Vehicle is moving backward...\n");
}

// Function to turn the vehicle left
void turnLeft() {
    printf("Vehicle is turning left...\n");
}

// Function to turn the vehicle right
void turnRight() {
    printf("Vehicle is turning right...\n");
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    // Main loop to control the vehicle
    while (1) {
        // Get user input
        int choice;
        printf("Enter a command (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Forward
                moveForward();
                break;
            case 2: // Backward
                moveBackward();
                break;
            case 3: // Left
                turnLeft();
                break;
            case 4: // Right
                turnRight();
                break;
            default:
                printf("Invalid command.\n");
        }

        // Wait for user input
        printf("Press any key to continue...\n");
        getchar();
    }

    return 0;
}