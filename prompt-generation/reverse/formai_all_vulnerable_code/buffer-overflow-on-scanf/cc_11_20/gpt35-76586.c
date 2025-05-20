//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdbool.h>

// Define directions
#define NORTH 1
#define EAST 2
#define SOUTH 3
#define WEST 4

// Define commands
#define FORWARD 'F'
#define TURN_LEFT 'L'
#define TURN_RIGHT 'R'
#define STOP 'S'

// Define simulation parameters
#define SIMULATION_TIME 1000
#define VEHICLE_SPEED 10
#define TURN_SPEED 5

// Define vehicle state
struct VehicleState {
    int x;
    int y;
    int direction;
};

// Function to print vehicle state
void printVehicleState(struct VehicleState state) {
    printf("Vehicle is at (%d, %d) facing ", state.x, state.y);
    switch (state.direction) {
        case NORTH:
            printf("North\n");
            break;
        case EAST:
            printf("East\n");
            break;
        case SOUTH:
            printf("South\n");
            break;
        case WEST:
            printf("West\n");
            break;
    }
}

int main() {
    // Initialize vehicle state
    struct VehicleState state = {0, 0, NORTH};

    // Start simulation loop
    for (int t = 0; t < SIMULATION_TIME; t++) {
        // Read user input
        char command;
        scanf("%c", &command);

        // Execute command
        switch (command) {
            case FORWARD:
                // Move forward
                switch (state.direction) {
                    case NORTH:
                        state.y += VEHICLE_SPEED;
                        break;
                    case EAST:
                        state.x += VEHICLE_SPEED;
                        break;
                    case SOUTH:
                        state.y -= VEHICLE_SPEED;
                        break;
                    case WEST:
                        state.x -= VEHICLE_SPEED;
                        break;
                }
                break;
            case TURN_LEFT:
                // Turn left
                switch (state.direction) {
                    case NORTH:
                        state.direction = WEST;
                        break;
                    case EAST:
                        state.direction = NORTH;
                        break;
                    case SOUTH:
                        state.direction = EAST;
                        break;
                    case WEST:
                        state.direction = SOUTH;
                        break;
                }
                break;
            case TURN_RIGHT:
                // Turn right
                switch (state.direction) {
                    case NORTH:
                        state.direction = EAST;
                        break;
                    case EAST:
                        state.direction = SOUTH;
                        break;
                    case SOUTH:
                        state.direction = WEST;
                        break;
                    case WEST:
                        state.direction = NORTH;
                        break;
                }
                break;
            case STOP:
                // Stop
                break;
        }

        // Print vehicle state
        printVehicleState(state);
    }

    return 0;
}