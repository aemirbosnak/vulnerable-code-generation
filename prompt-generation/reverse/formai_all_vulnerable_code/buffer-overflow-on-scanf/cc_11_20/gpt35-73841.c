//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants for the maximum speed and maximum number of turns
#define MAX_SPEED 10
#define MAX_TURNS 5

// Define a structure for the remote control vehicle
typedef struct {
    int x, y; // Coordinates of the vehicle on a 2D grid
    int speed; // Current speed of the vehicle
    int direction; // Direction of the vehicle (0 for north, 1 for east, 2 for south, 3 for west)
} RCVehicle;

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a new RCVehicle instance
    RCVehicle vehicle = {0, 0, 0, 0};

    // Define variables to store the user's input and the number of turns remaining
    int input, turns_remaining = MAX_TURNS;

    // Print the initial state of the vehicle
    printf("Initial state of vehicle: (%d, %d), speed = %d, direction = %d\n", vehicle.x, vehicle.y, vehicle.speed, vehicle.direction);

    // Loop until the user runs out of turns or exits the program
    do {
        // Prompt the user for input
        printf("Choose an action (0 to exit, 1 to accelerate, 2 to decelerate, 3 to turn left, 4 to turn right): ");
        scanf("%d", &input);

        // Handle the user's input
        switch (input) {
            case 0: // Exit the program
                printf("Exiting program...\n");
                return 0;
            case 1: // Accelerate the vehicle
                if (vehicle.speed < MAX_SPEED) vehicle.speed++;
                break;
            case 2: // Decelerate the vehicle
                if (vehicle.speed > 0) vehicle.speed--;
                break;
            case 3: // Turn the vehicle left
                vehicle.direction = (vehicle.direction - 1 + 4) % 4; // Use modular arithmetic to wrap around from west to north
                break;
            case 4: // Turn the vehicle right
                vehicle.direction = (vehicle.direction + 1) % 4; // Use modular arithmetic to wrap around from north to west
                break;
            default: // Invalid input
                printf("Invalid input, please try again...\n");
                continue;
        }

        // Update the vehicle's position based on its current speed and direction
        switch (vehicle.direction) {
            case 0: // North
                vehicle.y += vehicle.speed;
                break;
            case 1: // East
                vehicle.x += vehicle.speed;
                break;
            case 2: // South
                vehicle.y -= vehicle.speed;
                break;
            case 3: // West
                vehicle.x -= vehicle.speed;
                break;
        }

        // Print the updated state of the vehicle
        printf("Updated state of vehicle: (%d, %d), speed = %d, direction = %d\n", vehicle.x, vehicle.y, vehicle.speed, vehicle.direction);

        // Decrement the number of turns remaining
        turns_remaining--;
    } while (turns_remaining > 0);

    // Print the final state of the vehicle
    printf("Final state of vehicle: (%d, %d), speed = %d, direction = %d\n", vehicle.x, vehicle.y, vehicle.speed, vehicle.direction);

    return 0;
}