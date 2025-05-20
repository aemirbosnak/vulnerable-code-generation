//FormAI DATASET v1.0 Category: Drone Remote Control ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_DRONES 10
#define MAX_DISTANCE 1000

typedef struct {
    int x;
    int y;
} Coordinates;

typedef struct {
    int id;
    char name[50];
    Coordinates coordinates;
} Drone;

typedef struct {
    int x;
    int y;
} Control;

int main() {
    Drone drones[MAX_DRONES];
    int num_drones = 0;

    // Add drones
    Drone drone1 = {1, "Drone 1", {0, 0}};
    drones[num_drones++] = drone1;

    Drone drone2 = {2, "Drone 2", {100, 200}};
    drones[num_drones++] = drone2;

    Drone drone3 = {3, "Drone 3", {300, 400}};
    drones[num_drones++] = drone3;

    // Simulate drone operation
    while (1) {
        // Print drone locations
        printf("\nCurrent Drone Locations\n");
        for (int i = 0; i < num_drones; i++) {
            printf("%s: (%d, %d)\n", drones[i].name, drones[i].coordinates.x, drones[i].coordinates.y);
        }

        // Prompt user for which drone to control
        printf("\nEnter Drone ID to move (0 to exit): ");
        int drone_id;
        scanf("%d", &drone_id);

        if (drone_id == 0) break;

        Drone* drone_to_control = NULL; // Find drone to control
        for (int i = 0; i < num_drones; i++) {
            if (drones[i].id == drone_id) {
                drone_to_control = &drones[i];
                break;
            }
        }

        if (drone_to_control == NULL) {
            printf("Invalid drone ID %d\n", drone_id);
            continue;
        }

        // Prompt user for drone control movement
        Control control_movement;
        printf("Enter control movement (x y): ");
        scanf("%d %d", &control_movement.x, &control_movement.y);

        // Validate control movement is within range of drone
        Coordinates new_coordinates = {drone_to_control->coordinates.x + control_movement.x, drone_to_control->coordinates.y + control_movement.y};
        if (new_coordinates.x < 0 || new_coordinates.x > MAX_DISTANCE || new_coordinates.y < 0 || new_coordinates.y > MAX_DISTANCE) {
            printf("Control movement out of range for drone %s\n", drone_to_control->name);
            continue;
        }

        // Update drone coordinates
        drone_to_control->coordinates = new_coordinates;

        // Print drone new location
        printf("%s: (%d, %d)\n", drone_to_control->name, drone_to_control->coordinates.x, drone_to_control->coordinates.y);
    }

    return 0;
}