//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define the maximum speed of the remote control vehicle
#define MAX_SPEED 100

int main() {
    int speed = 0;
    char direction;

    // Keep running the simulation until the user exits
    while (1) {
        // Ask the user for input
        printf("Enter speed (0-100) and direction (f-forward, b-backward, l-left, r-right, s-stop): ");
        scanf("%d %c", &speed, &direction);

        // Check if the input is valid
        if (speed < 0 || speed > MAX_SPEED) {
            printf("Invalid speed. Please enter a value between 0 and %d.\n", MAX_SPEED);
            continue;
        }

        // Update the state of the vehicle based on the user input
        switch (direction) {
            case 'f':
                printf("Moving forward at speed %d.\n", speed);
                break;
            case 'b':
                printf("Moving backward at speed %d.\n", speed);
                break;
            case 'l':
                printf("Turning left at speed %d.\n", speed / 2);
                break;
            case 'r':
                printf("Turning right at speed %d.\n", speed / 2);
                break;
            case 's':
                printf("Stopping.\n");
                break;
            default:
                printf("Invalid direction. Please enter f, b, l, r or s.\n");
                continue;
        }

        // If the speed is zero, the vehicle is stopped
        if (speed == 0) {
            printf("The vehicle is now stopped.\n");
        }
    }

    return 0;
}