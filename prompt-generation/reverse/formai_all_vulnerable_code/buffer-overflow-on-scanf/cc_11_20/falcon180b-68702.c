//Falcon-180B DATASET v1.0 Category: Robot movement control ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159

int main() {
    double x, y, theta, v, w;
    int choice;

    // Initialize robot position and velocity
    x = 0;
    y = 0;
    theta = 0;
    v = 0;
    w = 0;

    // Main loop
    while (1) {
        printf("Robot position: (%lf, %lf)\n", x, y);
        printf("Robot orientation: %lf radians\n", theta);

        // Get user input for movement command
        printf("Enter movement command (f for forward, b for backward, l for left turn, r for right turn, q to quit): ");
        scanf("%c", &choice);

        // Process user input
        switch (choice) {
            case 'f': // Forward movement
                v = 0.5; // Set robot velocity to 0.5 m/s
                break;
            case 'b': // Backward movement
                v = -0.5; // Set robot velocity to -0.5 m/s
                break;
            case 'l': // Left turn
                w = 0.5; // Set robot angular velocity to 0.5 rad/s
                break;
            case 'r': // Right turn
                w = -0.5; // Set robot angular velocity to -0.5 rad/s
                break;
            case 'q': // Quit program
                exit(0);
            default: // Invalid input
                printf("Invalid input. Please try again.\n");
                break;
        }

        // Calculate new robot position and orientation based on movement command
        x += v * cos(theta);
        y += v * sin(theta);
        theta += w;

        // Limit robot speed to 1 m/s and 1 rad/s
        if (v > 1) {
            v = 1;
        }
        if (v < -1) {
            v = -1;
        }
        if (w > 1) {
            w = 1;
        }
        if (w < -1) {
            w = -1;
        }

        // Limit robot orientation to 2 radians
        if (theta > 2 * PI) {
            theta -= 2 * PI;
        }
        if (theta < 0) {
            theta += 2 * PI;
        }

        // Pause program for 0.1 seconds to simulate robot movement
        usleep(100000);
    }

    return 0;
}