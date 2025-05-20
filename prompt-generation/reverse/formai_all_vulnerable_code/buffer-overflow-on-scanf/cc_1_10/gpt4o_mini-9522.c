//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LEN 100
#define MAX_DRONES 10

typedef struct {
    int id;
    char name[50];
    int altitude;  // in meters
    int speed;     // in km/h
    int camera_active; // 1 for active, 0 for inactive
} Drone;

void initialize_drone(Drone *drone, int id, const char *name) {
    drone->id = id;
    strcpy(drone->name, name);
    drone->altitude = 0; // Start on the ground
    drone->speed = 0;    // Stationary
    drone->camera_active = 0;
}

void take_off(Drone *drone) {
    drone->altitude = 100; // Default take-off altitude
    printf("%s is taking off to an altitude of %d meters.\n", drone->name, drone->altitude);
}

void land(Drone *drone) {
    drone->altitude = 0; // Set altitude back to ground level
    printf("%s is landing.\n", drone->name);
}

void set_speed(Drone *drone, int speed) {
    drone->speed = speed;
    printf("%s is now flying at %d km/h.\n", drone->name, drone->speed);
}

void toggle_camera(Drone *drone) {
    drone->camera_active = !drone->camera_active;
    const char *status = drone->camera_active ? "active" : "inactive";
    printf("The camera on %s is now %s.\n", drone->name, status);
}

void display_drone_status(Drone *drone) {
    printf("\nDrone ID: %d\n", drone->id);
    printf("Name: %s\n", drone->name);
    printf("Altitude: %d meters\n", drone->altitude);
    printf("Speed: %d km/h\n", drone->speed);
    printf("Camera: %s\n\n", drone->camera_active ? "Active" : "Inactive");
}

void display_menu() {
    printf("Drone Control Menu:\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Set Speed\n");
    printf("4. Toggle Camera\n");
    printf("5. Display Status\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Drone drones[MAX_DRONES];
    int drone_count = 0;

    // Initialize Drones
    for (int i = 0; i < MAX_DRONES; i++) {
        char drone_name[50];
        sprintf(drone_name, "Drone%d", i + 1);
        initialize_drone(&drones[i], i + 1, drone_name);
        drone_count++;
    }

    int choice;
    int drone_id;
    int speed;

    while (1) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Take Off
                printf("Enter drone ID to take off: ");
                scanf("%d", &drone_id);
                if (drone_id > 0 && drone_id <= drone_count) {
                    take_off(&drones[drone_id - 1]);
                } else {
                    printf("Invalid drone ID!\n");
                }
                break;

            case 2: // Land
                printf("Enter drone ID to land: ");
                scanf("%d", &drone_id);
                if (drone_id > 0 && drone_id <= drone_count) {
                    land(&drones[drone_id - 1]);
                } else {
                    printf("Invalid drone ID!\n");
                }
                break;

            case 3: // Set Speed
                printf("Enter drone ID to set speed: ");
                scanf("%d", &drone_id);
                if (drone_id > 0 && drone_id <= drone_count) {
                    printf("Enter speed (km/h): ");
                    scanf("%d", &speed);
                    set_speed(&drones[drone_id - 1], speed);
                } else {
                    printf("Invalid drone ID!\n");
                }
                break;

            case 4: // Toggle Camera
                printf("Enter drone ID to toggle camera: ");
                scanf("%d", &drone_id);
                if (drone_id > 0 && drone_id <= drone_count) {
                    toggle_camera(&drones[drone_id - 1]);
                } else {
                    printf("Invalid drone ID!\n");
                }
                break;

            case 5: // Display Status
                printf("Enter drone ID to display status: ");
                scanf("%d", &drone_id);
                if (drone_id > 0 && drone_id <= drone_count) {
                    display_drone_status(&drones[drone_id - 1]);
                } else {
                    printf("Invalid drone ID!\n");
                }
                break;

            case 6: // Exit
                printf("Exiting Drone Control System.\n");
                exit(0);
                break;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    }

    return 0;
}