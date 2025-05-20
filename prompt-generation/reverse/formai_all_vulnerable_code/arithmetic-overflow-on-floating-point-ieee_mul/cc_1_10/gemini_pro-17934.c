//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SPEED 10
#define MAX_TURN_ANGLE 30

typedef struct {
    double x;
    double y;
    double theta; // in degrees
} Position;

typedef struct {
    double speed;
    double turn_angle;
} ControlInput;

typedef struct {
    Position position;
    ControlInput control_input;
} VehicleState;

void print_state(VehicleState state) {
    printf("Position: (%.2f, %.2f)\n", state.position.x, state.position.y);
    printf("Theta: %.2f degrees\n", state.position.theta);
    printf("Speed: %.2f m/s\n", state.control_input.speed);
    printf("Turn angle: %.2f degrees\n", state.control_input.turn_angle);
}

void update_state(VehicleState *state, double dt) {
    // Update position based on speed and turn angle
    state->position.x += state->control_input.speed * dt * cos(state->position.theta * M_PI / 180.0);
    state->position.y += state->control_input.speed * dt * sin(state->position.theta * M_PI / 180.0);
    state->position.theta += state->control_input.turn_angle * dt;

    // Wrap theta to within [0, 360) degrees
    state->position.theta = fmod(state->position.theta, 360.0);
}

int main() {
    // Initialize vehicle state
    VehicleState state = {
        .position = {.x = 0.0, .y = 0.0, .theta = 0.0},
        .control_input = {.speed = 0.0, .turn_angle = 0.0}
    };

    // Simulation parameters
    double dt = 0.1; // timestep (seconds)
    int num_steps = 1000;

    // Main simulation loop
    for (int i = 0; i < num_steps; i++) {
        // Get control inputs from user
        printf("Enter speed (0-%d m/s): ", MAX_SPEED);
        scanf("%lf", &state.control_input.speed);
        printf("Enter turn angle (-%d-%d degrees): ", MAX_TURN_ANGLE, MAX_TURN_ANGLE);
        scanf("%lf", &state.control_input.turn_angle);

        // Update vehicle state
        update_state(&state, dt);

        // Print vehicle state
        print_state(state);
    }

    return 0;
}