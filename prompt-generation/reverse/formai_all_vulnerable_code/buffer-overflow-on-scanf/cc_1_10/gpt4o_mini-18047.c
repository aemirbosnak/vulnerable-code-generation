//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 5

typedef struct {
    int x;
    int y;
} Vehicle;

void displayGrid(Vehicle *vehicle) {
    printf("\nCurrent Position: (%d, %d)\n", vehicle->x, vehicle->y);
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == vehicle->y && j == vehicle->x) {
                printf("[V] ");
            } else {
                printf("[ ] ");
            }
        }
        printf("\n");
    }
}

void moveVehicle(Vehicle *vehicle, char command) {
    switch (command) {
        case 'w': // Move up
            if (vehicle->y > 0) vehicle->y--;
            break;
        case 's': // Move down
            if (vehicle->y < GRID_SIZE - 1) vehicle->y++;
            break;
        case 'a': // Move left
            if (vehicle->x > 0) vehicle->x--;
            break;
        case 'd': // Move right
            if (vehicle->x < GRID_SIZE - 1) vehicle->x++;
            break;
        default:
            printf("Invalid command. Use w/a/s/d to move, or q to quit.\n");
            break;
    }
}

void controlVehicle(Vehicle *vehicle) {
    char command;
    displayGrid(vehicle);
    printf("Enter command (w/a/s/d to move, q to quit): ");
    scanf(" %c", &command);

    if (command == 'q') {
        printf("Simulation ended. Final Position: (%d, %d)\n", vehicle->x, vehicle->y);
        return;
    }

    moveVehicle(vehicle, command);
    controlVehicle(vehicle); // Recursive call to continue controlling
}

int main() {
    Vehicle vehicle = {0, 0}; // Start at top-left corner
    printf("Remote Control Vehicle Simulation\n");
    controlVehicle(&vehicle);
    return 0;
}