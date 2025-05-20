//GEMINI-pro DATASET v1.0 Category: Robot movement control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

#define PI 3.14159265

// Robot movement parameters
#define X_MIN 0.0
#define X_MAX 10.0
#define Y_MIN 0.0
#define Y_MAX 10.0
#define THETA_MIN 0.0
#define THETA_MAX 2.0 * PI

// Robot state variables
double x = 5.0;
double y = 5.0;
double theta = 0.0;

// Robot movement functions
void move_forward(double distance) {
    x += distance * cos(theta);
    y += distance * sin(theta);
}

void move_backward(double distance) {
    x -= distance * cos(theta);
    y -= distance * sin(theta);
}

void turn_left(double angle) {
    theta -= angle;
    if (theta < THETA_MIN) {
        theta += 2.0 * PI;
    }
}

void turn_right(double angle) {
    theta += angle;
    if (theta > THETA_MAX) {
        theta -= 2.0 * PI;
    }
}

// Main program
int main() {
    // Set the robot's initial position and orientation
    x = 5.0;
    y = 5.0;
    theta = 0.0;

    // Create a loop to control the robot's movement
    while (1) {
        // Get the user's input
        char command;
        printf("Enter a command (f, b, l, r, q): ");
        scanf(" %c", &command);

        // Execute the command
        switch (command) {
            case 'f':
                move_forward(1.0);
                break;
            case 'b':
                move_backward(1.0);
                break;
            case 'l':
                turn_left(PI / 4.0);
                break;
            case 'r':
                turn_right(PI / 4.0);
                break;
            case 'q':
                exit(0);
            default:
                printf("Invalid command!\n");
        }

        // Print the robot's current position and orientation
        printf("Robot position: (%f, %f)\n", x, y);
        printf("Robot orientation: %f\n", theta);
    }

    return 0;
}