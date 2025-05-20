//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CLEAR_SCREEN "\033[2J\033[H"

// Drone states
enum drone_state {
    TAKING_OFF,
    FLYING,
    LANDING,
    IDLE
};

// Drone commands
enum drone_command {
    TAKE_OFF,
    LAND,
    MOVE_FORWARD,
    MOVE_BACKWARD,
    MOVE_LEFT,
    MOVE_RIGHT,
    ROTATE_LEFT,
    ROTATE_RIGHT,
    FLIP,
    STOP
};

// Drone structure
struct drone {
    enum drone_state state;
    int altitude;
    int x;
    int y;
    int z;
};

// Function to initialize the drone
void drone_init(struct drone *drone) {
    drone->state = IDLE;
    drone->altitude = 0;
    drone->x = 0;
    drone->y = 0;
    drone->z = 0;
}

// Function to print the drone's current state
void drone_print_state(struct drone *drone) {
    printf("State: %s\n", drone->state == TAKING_OFF ? "TAKING OFF" : drone->state == FLYING ? "FLYING" : drone->state == LANDING ? "LANDING" : "IDLE");
    printf("Altitude: %d\n", drone->altitude);
    printf("X: %d\n", drone->x);
    printf("Y: %d\n", drone->y);
    printf("Z: %d\n", drone->z);
}

// Function to take off the drone
void drone_take_off(struct drone *drone) {
    if (drone->state != IDLE) {
        printf("Error: Drone is not in IDLE state.\n");
        return;
    }

    drone->state = TAKING_OFF;

    // Simulate taking off
    for (int i = 0; i < 10; i++) {
        drone->altitude++;
        printf(CLEAR_SCREEN);
        drone_print_state(drone);
        usleep(100000);
    }

    drone->state = FLYING;
}

// Function to land the drone
void drone_land(struct drone *drone) {
    if (drone->state != FLYING) {
        printf("Error: Drone is not in FLYING state.\n");
        return;
    }

    drone->state = LANDING;

    // Simulate landing
    for (int i = 0; i < 10; i++) {
        drone->altitude--;
        printf(CLEAR_SCREEN);
        drone_print_state(drone);
        usleep(100000);
    }

    drone->state = IDLE;
}

// Function to move the drone forward
void drone_move_forward(struct drone *drone) {
    if (drone->state != FLYING) {
        printf("Error: Drone is not in FLYING state.\n");
        return;
    }

    drone->y++;
}

// Function to move the drone backward
void drone_move_backward(struct drone *drone) {
    if (drone->state != FLYING) {
        printf("Error: Drone is not in FLYING state.\n");
        return;
    }

    drone->y--;
}

// Function to move the drone left
void drone_move_left(struct drone *drone) {
    if (drone->state != FLYING) {
        printf("Error: Drone is not in FLYING state.\n");
        return;
    }

    drone->x--;
}

// Function to move the drone right
void drone_move_right(struct drone *drone) {
    if (drone->state != FLYING) {
        printf("Error: Drone is not in FLYING state.\n");
        return;
    }

    drone->x++;
}

// Function to rotate the drone left
void drone_rotate_left(struct drone *drone) {
    if (drone->state != FLYING) {
        printf("Error: Drone is not in FLYING state.\n");
        return;
    }

    drone->z--;
}

// Function to rotate the drone right
void drone_rotate_right(struct drone *drone) {
    if (drone->state != FLYING) {
        printf("Error: Drone is not in FLYING state.\n");
        return;
    }

    drone->z++;
}

// Function to flip the drone
void drone_flip(struct drone *drone) {
    if (drone->state != FLYING) {
        printf("Error: Drone is not in FLYING state.\n");
        return;
    }

    // Simulate flipping
    for (int i = 0; i < 10; i++) {
        drone->z += 36;
        printf(CLEAR_SCREEN);
        drone_print_state(drone);
        usleep(100000);
    }
}

// Function to print the menu
void drone_print_menu() {
    printf("\n");
    printf("Commands:\n");
    printf("1) Take Off\n");
    printf("2) Land\n");
    printf("3) Move Forward\n");
    printf("4) Move Backward\n");
    printf("5) Move Left\n");
    printf("6) Move Right\n");
    printf("7) Rotate Left\n");
    printf("8) Rotate Right\n");
    printf("9) Flip\n");
    printf("10) Stop\n");
    printf("\n");
}

int main() {
    // Initialize the drone
    struct drone drone;
    drone_init(&drone);

    // Print the menu
    drone_print_menu();

    // Get the user's input
    int command;
    while (1) {
        printf("Enter a command: ");
        scanf("%d", &command);

        switch (command) {
            case TAKE_OFF:
                drone_take_off(&drone);
                break;
            case LAND:
                drone_land(&drone);
                break;
            case MOVE_FORWARD:
                drone_move_forward(&drone);
                break;
            case MOVE_BACKWARD:
                drone_move_backward(&drone);
                break;
            case MOVE_LEFT:
                drone_move_left(&drone);
                break;
            case MOVE_RIGHT:
                drone_move_right(&drone);
                break;
            case ROTATE_LEFT:
                drone_rotate_left(&drone);
                break;
            case ROTATE_RIGHT:
                drone_rotate_right(&drone);
                break;
            case FLIP:
                drone_flip(&drone);
                break;
            case STOP:
                return 0;
            default:
                printf("Invalid command.\n");
        }

        printf(CLEAR_SCREEN);
        drone_print_state(&drone);
    }

    return 0;
}