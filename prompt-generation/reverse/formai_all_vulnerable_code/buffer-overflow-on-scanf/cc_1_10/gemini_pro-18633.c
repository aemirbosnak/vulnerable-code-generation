//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: modular
#include <stdio.h>
#include <stdbool.h>

// Define the drone's state
typedef enum {
    DRONE_STATE_IDLE,
    DRONE_STATE_TAKING_OFF,
    DRONE_STATE_FLYING,
    DRONE_STATE_LANDING,
    DRONE_STATE_CRASHED
} drone_state_t;

// Define the drone's commands
typedef enum {
    DRONE_COMMAND_NONE,
    DRONE_COMMAND_TAKE_OFF,
    DRONE_COMMAND_FLY,
    DRONE_COMMAND_LAND,
    DRONE_COMMAND_CRASH
} drone_command_t;

// Define the drone's control structure
typedef struct {
    drone_state_t state;
    drone_command_t command;
} drone_control_t;

// Initialize the drone's control structure
drone_control_t drone_control = {
    .state = DRONE_STATE_IDLE,
    .command = DRONE_COMMAND_NONE
};

// Define the drone's functions
void drone_take_off(drone_control_t *drone_control) {
    if (drone_control->state != DRONE_STATE_IDLE) {
        printf("Error: Drone is not in idle state.\n");
        return;
    }

    drone_control->state = DRONE_STATE_TAKING_OFF;
    printf("Drone is taking off.\n");
}

void drone_fly(drone_control_t *drone_control) {
    if (drone_control->state != DRONE_STATE_FLYING) {
        printf("Error: Drone is not in flying state.\n");
        return;
    }

    printf("Drone is flying.\n");
}

void drone_land(drone_control_t *drone_control) {
    if (drone_control->state != DRONE_STATE_FLYING) {
        printf("Error: Drone is not in flying state.\n");
        return;
    }

    drone_control->state = DRONE_STATE_LANDING;
    printf("Drone is landing.\n");
}

void drone_crash(drone_control_t *drone_control) {
    if (drone_control->state != DRONE_STATE_FLYING) {
        printf("Error: Drone is not in flying state.\n");
        return;
    }

    drone_control->state = DRONE_STATE_CRASHED;
    printf("Drone has crashed.\n");
}

// Define the main function
int main(void) {
    // Get the drone's command
    drone_command_t command;
    printf("Enter a command (take_off, fly, land, crash, or quit): ");
    scanf("%s", &command);

    // Execute the drone's command
    switch (command) {
        case DRONE_COMMAND_TAKE_OFF:
            drone_take_off(&drone_control);
            break;
        case DRONE_COMMAND_FLY:
            drone_fly(&drone_control);
            break;
        case DRONE_COMMAND_LAND:
            drone_land(&drone_control);
            break;
        case DRONE_COMMAND_CRASH:
            drone_crash(&drone_control);
            break;
        case DRONE_COMMAND_NONE:
            printf("No command entered.\n");
            break;
        default:
            printf("Invalid command entered.\n");
    }

    return 0;
}