//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Global variables
int speed = 0;
int angle = 0;

// Function to print current status of vehicle
void printStatus() {
    printf("Current speed: %d mph\n", speed);
    printf("Current angle: %d degrees\n", angle);
}

int main() {
    // Vehicle simulation loop
    bool running = true;
    while (running) {
        // Get user input for speed and angle
        printf("Enter speed (0-100 mph): ");
        scanf("%d", &speed);
        printf("Enter angle (-90 to 90 degrees): ");
        scanf("%d", &angle);

        // Ensure speed is within range
        if (speed < 0) {
            printf("Speed cannot be negative. Setting speed to 0...\n");
            speed = 0;
        }
        else if (speed > 100) {
            printf("Speed exceeds maximum limit. Setting speed to 100...\n");
            speed = 100;
        }

        // Ensure angle is within range
        if (angle < -90) {
            printf("Angle exceeds maximum limit. Setting angle to -90...\n");
            angle = -90;
        }
        else if (angle > 90) {
            printf("Angle exceeds maximum limit. Setting angle to 90...\n");
            angle = 90;
        }

        // Print current status of vehicle
        printStatus();

        // User prompts to continue or quit
        char choice;
        printf("Do you want to continue? (y/n)\n");
        scanf(" %c", &choice);
        if (choice == 'n') {
            printf("Quitting vehicle simulation...\n");
            running = false;
        }
    }

    return 0;
}