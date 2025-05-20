//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Struct for holding drone coordinates
struct Coordinates {
    int x;
    int y;
    int z;
};

// Struct for holding drone speed and direction
struct Velocity {
    int x;
    int y;
    int z;
};

// Function for moving drone coordinates
void moveDrone(struct Coordinates* coords, struct Velocity* vel) {
    coords->x += vel->x;
    coords->y += vel->y;
    coords->z += vel->z;
}

int main() {

    // Initialize drone coordinates and velocity
    struct Coordinates droneCords = {0, 0, 0};
    struct Velocity droneVel = {0, 0, 0};

    printf("Drone Remote Control Program:\n");

    // Main program loop
    while (1) {

        // Print current drone coordinates and velocity
        printf("\nCurrent coordinates: (%d, %d, %d)\n", droneCords.x, droneCords.y, droneCords.z);
        printf("Current velocity: (%d, %d, %d)\n", droneVel.x, droneVel.y, droneVel.z);

        // Prompt user for movement commands
        printf("Enter movement command: ");
        char movementCommand;
        scanf(" %c", &movementCommand);

        // Execute movement commands
        switch(movementCommand) {
            case 'w':
                droneVel.z += 1;
                break;
            case 's':
                droneVel.z -= 1;
                break;
            case 'a':
                droneVel.x -= 1;
                break;
            case 'd':
                droneVel.x += 1;
                break;
            case 'q':
                droneVel.y += 1;
                break;
            case 'e':
                droneVel.y -= 1;
                break;
            case 'm':
                printf("Enter x, y, and z velocity: ");
                scanf("%d %d %d", &droneVel.x, &droneVel.y, &droneVel.z);
                break;
            case 'p':
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid command.\n");
        }

        // Move drone coordinates based on velocity
        moveDrone(&droneCords, &droneVel);
    }

    return 0;
}