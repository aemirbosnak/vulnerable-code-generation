//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// This program simulates a remote control vehicle (RCV) capable of moving forward and backward, turning left and right.

// Define constants for the RCV's maximum forward and backward speed, as well as turning angles in degrees
#define MAX_FORWARD_SPEED 3
#define MAX_BACKWARD_SPEED -3
#define LEFT_TURN_ANGLE 30
#define RIGHT_TURN_ANGLE 30

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Declare variables for the RCV's current speed and direction
    int speed = 0;
    int direction = 0;

    printf("Welcome to the RCV Simulator!\n");

    // Loop until the program is terminated
    while (1) {
        // Output current RCV status
        printf("\nRCV status: speed=%d, direction=%d\n", speed, direction);

        // Prompt user for desired action
        printf("Enter an action (f=forward, b=backward, l=left, r=right, q=quit): ");
        char action;
        scanf(" %c", &action);

        // Handle user input
        switch (action) {
            case 'f':
                // Increase RCV speed
                if (speed < MAX_FORWARD_SPEED) {
                    speed++;
                }
                break;
            case 'b':
                // Decrease RCV speed
                if (speed > MAX_BACKWARD_SPEED) {
                    speed--;
                }
                break;
            case 'l':
                // Turn RCV left
                direction -= LEFT_TURN_ANGLE;
                break;
            case 'r':
                // Turn RCV right
                direction += RIGHT_TURN_ANGLE;
                break;
            case 'q':
                // Quit program
                printf("Goodbye!\n");
                exit(0);
            default:
                // Invalid input
                printf("Invalid action!\n");
                break;
        }

        // Add some randomness to the RCV's movements
        direction += (rand() % 21) - 10;
        speed += (rand() % 3) - 1;

        // Make sure RCV speed is within limits
        if (speed > MAX_FORWARD_SPEED) {
            speed = MAX_FORWARD_SPEED;
        } else if (speed < MAX_BACKWARD_SPEED) {
            speed = MAX_BACKWARD_SPEED;
        }

        // Make sure RCV direction is within range 0..359
        if (direction < 0) {
            direction += 360;
        } else if (direction >= 360) {
            direction -= 360;
        }
    }

    return 0;
}