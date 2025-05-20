//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

#define DELAY 100000

int main() {
    // Initialize the RC vehicle
    int speed = 0;
    int direction = 0; // 0 = forward, 1 = backward, 2 = left, 3 = right
    int battery = 100; // Percentage of battery remaining

    // Main loop
    while (1) {
        // Check for user input
        printf("Enter a command (f/b/l/r/s/q): ");
        char command;
        scanf(" %c", &command);

        // Process the command
        switch (command) {
            case 'f': // Forward
                if (speed < 100) {
                    speed++;
                }
                direction = 0;
                break;
            case 'b': // Backward
                if (speed > -100) {
                    speed--;
                }
                direction = 1;
                break;
            case 'l': // Left
                direction = 2;
                break;
            case 'r': // Right
                direction = 3;
                break;
            case 's': // Stop
                speed = 0;
                break;
            case 'q': // Quit
                return 0;
        }

        // Update the RC vehicle
        if (speed != 0) {
            // Move the vehicle
            if (direction == 0) {
                printf("Moving forward at %d mph\n", speed);
            } else if (direction == 1) {
                printf("Moving backward at %d mph\n", -speed);
            } else if (direction == 2) {
                printf("Turning left\n");
            } else if (direction == 3) {
                printf("Turning right\n");
            }

            // Decrement the battery
            battery--;
        } else {
            printf("Stopped\n");
        }

        // Display the RC vehicle's status
        printf("Speed: %d mph\n", speed);
        printf("Direction: %s\n", direction == 0 ? "Forward" : (direction == 1 ? "Backward" : (direction == 2 ? "Left" : "Right")));
        printf("Battery: %d%%\n", battery);

        // Delay to simulate the RC vehicle's movement
        for (int i = 0; i < DELAY; i++);
    }

    return 0;
}