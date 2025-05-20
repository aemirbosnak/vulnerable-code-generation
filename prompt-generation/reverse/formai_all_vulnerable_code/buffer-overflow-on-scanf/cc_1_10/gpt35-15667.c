//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define the maximum speed of the vehicle
#define MAX_SPEED 100

// Define the steering angles
#define LEFT_STEER 30
#define STRAIGHT_STEER 0
#define RIGHT_STEER (-30)

// Declare the function prototypes
void accelerate(int speed);
void steer(int angle);
void brake();
void stop();
void move(char direction);

// Define the main function
int main() {
    char input;

    // Display a welcome message
    printf("Welcome to the Remote Control Vehicle Simulator!\n");

    // Ask the user to input a command
    printf("Type 'w' to move forward, 'a' to turn left, 'd' to turn right, 's' to move backward, or 'q' to quit.\n");

    // Loop until the user quits
    while (1) {
        // Read the user's input
        scanf("%c", &input);

        // Move the vehicle according to the user's input
        switch (input) {
            case 'w':
            case 'W':
                move('F');
                break;
            case 'a':
            case 'A':
                move('L');
                break;
            case 'd':
            case 'D':
                move('R');
                break;
            case 's':
            case 'S':
                move('B');
                break;
            case 'q':
            case 'Q':
                stop();
                printf("Thank you for using the Remote Control Vehicle Simulator!\n");
                exit(0);
            default:
                printf("Invalid command. Please try again.\n");
                break;
        }

        // Flush the input buffer to avoid reading the same input multiple times
        fflush(stdin);
    }

    return 0;
}

// Define the function to accelerate the vehicle
void accelerate(int speed) {
    if (speed <= MAX_SPEED && speed >= 0) {
        printf("Accelerating to %d km/h...\n", speed);
    } else {
        printf("Invalid speed. Please enter a value between 0 and %d km/h.\n", MAX_SPEED);
    }
}

// Define the function to steer the vehicle
void steer(int angle) {
    if (angle == LEFT_STEER) {
        printf("Turning left...\n");
    } else if (angle == STRAIGHT_STEER) {
        printf("Going straight...\n");
    } else if (angle == RIGHT_STEER) {
        printf("Turning right...\n");
    } else {
        printf("Invalid steering angle. Please enter -30 (left), 0 (straight), or 30 (right).\n");
    }
}

// Define the function to brake the vehicle
void brake() {
    printf("Braking...\n");
}

// Define the function to stop the vehicle
void stop() {
    printf("Stopping...\n");
}

// Define the function to move the vehicle in the specified direction
void move(char direction) {
    int speed = 0;
    int angle = STRAIGHT_STEER;

    // Ask the user to input the speed
    printf("Enter the speed (0-%d km/h): ", MAX_SPEED);
    scanf("%d", &speed);

    // Ask the user to input the steering angle
    printf("Enter the steering angle (-30, 0, 30): ");
    scanf("%d", &angle);

    // Move the vehicle according to the specified direction
    switch (direction) {
        case 'F':
            accelerate(speed);
            steer(angle);
            break;
        case 'L':
            steer(LEFT_STEER);
            brake();
            accelerate(speed);
            steer(STRAIGHT_STEER);
            break;
        case 'R':
            steer(RIGHT_STEER);
            brake();
            accelerate(speed);
            steer(STRAIGHT_STEER);
            break;
        case 'B':
            brake();
            accelerate(speed);
            steer(angle);
            break;
        default:
            printf("Invalid direction. Please enter 'F' (forward), 'L' (left), 'R' (right), or 'B' (backward).\n");
            break;
    }
}