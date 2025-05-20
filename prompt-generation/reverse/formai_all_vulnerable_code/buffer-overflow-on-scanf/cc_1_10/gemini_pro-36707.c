//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Constants representing the vehicle's directions
#define FORWARD 0
#define BACKWARD 1
#define LEFT 2
#define RIGHT 3

// Function to simulate the remote control vehicle's movement
void moveVehicle(int direction, int distance) {
    switch (direction) {
        case FORWARD:
            printf("The vehicle moves forward %d units.\n", distance);
            break;
        case BACKWARD:
            printf("The vehicle moves backward %d units.\n", distance);
            break;
        case LEFT:
            printf("The vehicle turns left.\n");
            break;
        case RIGHT:
            printf("The vehicle turns right.\n");
            break;
        default:
            printf("Invalid direction entered.\n");
            break;
    }
}

// Function to simulate the user's input for the remote control vehicle
int getInput() {
    int input;
    printf("Enter a command for the vehicle (1: Forward, 2: Backward, 3: Left, 4: Right, 0: Quit): ");
    scanf("%d", &input);
    return input;
}

// Main function to control the simulation
int main() {
    bool running = true;
    while (running) {
        // Get the user's input
        int input = getInput();

        // Exit the simulation if the user enters 0
        if (input == 0) {
            running = false;
        } else {
            // Move the vehicle based on the user's input
            moveVehicle(input - 1, 1);
        }
    }

    printf("Simulation ended.\n");
    return 0;
}