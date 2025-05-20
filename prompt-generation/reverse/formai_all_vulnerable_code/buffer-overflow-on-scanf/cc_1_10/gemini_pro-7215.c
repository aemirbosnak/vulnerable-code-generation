//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Vehicle states
typedef enum {
    STOPPED,
    MOVING_FORWARD,
    MOVING_BACKWARD,
    TURNING_LEFT,
    TURNING_RIGHT
} VehicleState;

// Vehicle actions (movement commands)
typedef enum {
    STOP,
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
} VehicleAction;

// Vehicle object
typedef struct {
    float x;                  // x-coordinate
    float y;                  // y-coordinate
    float angle;              // angle (in radians)
    float speed;              // speed (in m/s)
    VehicleState state;      // current state
} Vehicle;

// Initialize a vehicle
void vehicle_init(Vehicle *vehicle) {
    vehicle->x = 0.0f;
    vehicle->y = 0.0f;
    vehicle->angle = 0.0f;
    vehicle->speed = 0.0f;
    vehicle->state = STOPPED;
}

// Update the vehicle's state based on the given action
void vehicle_update(Vehicle *vehicle, VehicleAction action) {
    switch (action) {
    case STOP:
        vehicle->state = STOPPED;
        vehicle->speed = 0.0f;
        break;
    case FORWARD:
        vehicle->state = MOVING_FORWARD;
        vehicle->speed += 0.1f;
        break;
    case BACKWARD:
        vehicle->state = MOVING_BACKWARD;
        vehicle->speed -= 0.1f;
        break;
    case LEFT:
        vehicle->state = TURNING_LEFT;
        vehicle->angle += 0.1f;
        break;
    case RIGHT:
        vehicle->state = TURNING_RIGHT;
        vehicle->angle -= 0.1f;
        break;
    }
}

// Draw the vehicle on the console
void vehicle_draw(Vehicle *vehicle) {
    printf("Vehicle status:\n");
    printf("  x: %f\n", vehicle->x);
    printf("  y: %f\n", vehicle->y);
    printf("  angle: %f\n", vehicle->angle);
    printf("  speed: %f\n", vehicle->speed);
    printf("  state: ");
    switch (vehicle->state) {
    case STOPPED:
        printf("STOPPED\n");
        break;
    case MOVING_FORWARD:
        printf("MOVING_FORWARD\n");
        break;
    case MOVING_BACKWARD:
        printf("MOVING_BACKWARD\n");
        break;
    case TURNING_LEFT:
        printf("TURNING_LEFT\n");
        break;
    case TURNING_RIGHT:
        printf("TURNING_RIGHT\n");
        break;
    }
}

int main() {
    // Create a new vehicle
    Vehicle vehicle;
    vehicle_init(&vehicle);

    // Main loop
    bool running = true;
    while (running) {
        // Get user input
        char input;
        printf("Enter a command (f/b/l/r/s/q): ");
        scanf(" %c", &input);

        // Update the vehicle based on the input
        switch (input) {
        case 'f':
            vehicle_update(&vehicle, FORWARD);
            break;
        case 'b':
            vehicle_update(&vehicle, BACKWARD);
            break;
        case 'l':
            vehicle_update(&vehicle, LEFT);
            break;
        case 'r':
            vehicle_update(&vehicle, RIGHT);
            break;
        case 's':
            vehicle_update(&vehicle, STOP);
            break;
        case 'q':
            running = false;
            break;
        }

        // Draw the vehicle
        vehicle_draw(&vehicle);
    }

    return 0;
}