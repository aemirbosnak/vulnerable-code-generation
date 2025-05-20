//GEMINI-pro DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Vehicle data structure
typedef struct {
    int x;
    int y;
    int direction; // 0: up, 1: right, 2: down, 3: left
} Vehicle;

// Remote control data structure
typedef struct {
    bool up;
    bool down;
    bool left;
    bool right;
} RemoteControl;

// Function to initialize vehicle
Vehicle* init_vehicle(int x, int y, int direction) {
    Vehicle *vehicle = malloc(sizeof(Vehicle));
    vehicle->x = x;
    vehicle->y = y;
    vehicle->direction = direction;
    return vehicle;
}

// Function to initialize remote control
RemoteControl* init_remote_control() {
    RemoteControl *remote_control = malloc(sizeof(RemoteControl));
    remote_control->up = false;
    remote_control->down = false;
    remote_control->left = false;
    remote_control->right = false;
    return remote_control;
}

// Function to update vehicle position based on remote control input
void update_vehicle_position(Vehicle *vehicle, RemoteControl *remote_control) {
    if (remote_control->up) {
        vehicle->direction = 0;
        vehicle->y--;
    } else if (remote_control->down) {
        vehicle->direction = 2;
        vehicle->y++;
    } else if (remote_control->left) {
        vehicle->direction = 3;
        vehicle->x--;
    } else if (remote_control->right) {
        vehicle->direction = 1;
        vehicle->x++;
    }
}

// Main function
int main() {
    // Initialize vehicle and remote control
    Vehicle *vehicle = init_vehicle(0, 0, 0);
    RemoteControl *remote_control = init_remote_control();

    // Loop until user quits
    while (true) {
        // Get remote control input
        printf("Enter remote control commands (up, down, left, right, q to quit): ");
        char command[256];
        scanf("%s", command);

        // Update vehicle position based on remote control input
        if (strcmp(command, "up") == 0) {
            remote_control->up = true;
        } else if (strcmp(command, "down") == 0) {
            remote_control->down = true;
        } else if (strcmp(command, "left") == 0) {
            remote_control->left = true;
        } else if (strcmp(command, "right") == 0) {
            remote_control->right = true;
        } else if (strcmp(command, "q") == 0) {
            break;
        } else {
            printf("Invalid command.\n");
        }

        // Update vehicle position
        update_vehicle_position(vehicle, remote_control);

        // Print vehicle position
        printf("Vehicle position: (%d, %d)\n", vehicle->x, vehicle->y);
    }

    // Free memory
    free(vehicle);
    free(remote_control);

    return 0;
}