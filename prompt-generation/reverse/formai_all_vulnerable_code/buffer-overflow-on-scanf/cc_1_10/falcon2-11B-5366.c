//Falcon2-11B DATASET v1.0 Category: Drone Remote Control ; Style: brave
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Define the possible states of the drone
enum State {
    UNINITIALIZED,
    IDLE,
    MOVING,
    CRASHED
};

// Define the possible control signals
enum ControlSignal {
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    EMERGENCY_STOP
};

// Structure to hold the state and control signals
typedef struct {
    enum State state;
    enum ControlSignal controls[6];
} DroneState;

// Function to initialize the drone
void init_drone() {
    DroneState drone;
    drone.state = UNINITIALIZED;
    for (int i = 0; i < 6; i++) {
        drone.controls[i] = UNINITIALIZED;
    }
}

// Function to update the state of the drone based on control signals
void update_state(DroneState* drone) {
    if (drone->state == IDLE) {
        if (drone->controls[FORWARD]) {
            drone->state = MOVING;
        } else if (drone->controls[BACKWARD]) {
            drone->state = MOVING;
        } else if (drone->controls[LEFT] || drone->controls[RIGHT]) {
            drone->state = MOVING;
        } else if (drone->controls[UP] || drone->controls[DOWN]) {
            drone->state = MOVING;
        }
    } else if (drone->state == MOVING) {
        if (drone->controls[EMERGENCY_STOP]) {
            drone->state = CRASHED;
        }
    }
}

// Function to print the state of the drone
void print_state(DroneState* drone) {
    switch (drone->state) {
        case UNINITIALIZED:
            printf("Drone is uninitialized\n");
            break;
        case IDLE:
            printf("Drone is idle\n");
            break;
        case MOVING:
            printf("Drone is moving\n");
            break;
        case CRASHED:
            printf("Drone has crashed\n");
            break;
        default:
            printf("Unknown state\n");
            break;
    }
}

// Main function
int main() {
    init_drone();
    DroneState drone;
    while (true) {
        print_state(&drone);
        update_state(&drone);
        printf("Control signals: ");
        for (int i = 0; i < 6; i++) {
            printf("%s ", drone.controls[i] == EMERGENCY_STOP? "Emergency stop" : "Off");
        }
        printf("\n");
        scanf("%s", &drone.controls[FORWARD]);
        scanf("%s", &drone.controls[BACKWARD]);
        scanf("%s", &drone.controls[LEFT]);
        scanf("%s", &drone.controls[RIGHT]);
        scanf("%s", &drone.controls[UP]);
        scanf("%s", &drone.controls[DOWN]);
    }
    return 0;
}