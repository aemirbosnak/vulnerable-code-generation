//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define the remote control vehicle's properties
#define MAX_SPEED 100
#define MIN_SPEED 0
#define ACCELERATION 5
#define DECELERATION 2
#define TURN_RADIUS 50

// Define the remote control vehicle's state
typedef struct {
    int speed;
    int direction;
} VehicleState;

// Initialize the remote control vehicle's state
VehicleState initState() {
    VehicleState state;
    state.speed = 0;
    state.direction = 0;
    return state;
}

// Update the remote control vehicle's state based on user input
VehicleState updateState(VehicleState state, int accel, int turn) {
    if (accel > 0) {
        state.speed = (state.speed + ACCELERATION) % MAX_SPEED;
    } else if (accel < 0) {
        state.speed = (state.speed - DECELERATION + MAX_SPEED) % MAX_SPEED;
    }

    if (turn > 0) {
        state.direction = (state.direction + TURN_RADIUS) % 360;
    } else if (turn < 0) {
        state.direction = (state.direction - TURN_RADIUS + 360) % 360;
    }

    return state;
}

// Print the remote control vehicle's current state
void printState(VehicleState state) {
    printf("Speed: %d\n", state.speed);
    printf("Direction: %d degrees\n", state.direction);
}

// Main function
int main() {
    VehicleState state = initState();

    while (1) {
        int accel, turn;
        printf("Enter acceleration (+ for forward, - for backward): ");
        scanf("%d", &accel);
        printf("Enter turn (+ for right, - for left): ");
        scanf("%d", &turn);

        state = updateState(state, accel, turn);
        printState(state);
    }

    return 0;
}