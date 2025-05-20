//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

typedef struct {
    float altitude;
    float latitude;
    float longitude;
} Drone;

void initializeDrone(Drone *drone) {
    drone->altitude = 0.0;
    drone->latitude = 0.0;
    drone->longitude = 0.0;
}

void showStatus(const Drone *drone) {
    printf("\n--- Drone Status ---\n");
    printf("Altitude: %.2f meters\n", drone->altitude);
    printf("Location: (%.2f, %.2f)\n", drone->latitude, drone->longitude);
    printf("---------------------\n");
}

void takeOff(Drone *drone) {
    if (drone->altitude <= 0) {
        drone->altitude += 10.0; // basic ascent
        printf("Taking off...\n");
    } else {
        printf("Drone is already in the air at %.2f meters.\n", drone->altitude);
    }
}

void land(Drone *drone) {
    if (drone->altitude > 0) {
        drone->altitude = 0;
        printf("Landing...\n");
    } else {
        printf("Drone is already on the ground.\n");
    }
}

void move(Drone *drone, float deltaLat, float deltaLong) {
    drone->latitude += deltaLat;
    drone->longitude += deltaLong;
    printf("Moving to new location: (%.2f, %.2f)\n", drone->latitude, drone->longitude);
}

void displayMenu() {
    printf("\n--- Drone Control Menu ---\n");
    printf("1. Take Off\n");
    printf("2. Land\n");
    printf("3. Move (latitude delta, longitude delta)\n");
    printf("4. Show Status\n");
    printf("5. Exit\n");
    printf("--------------------------\n");
}

int main() {
    Drone drone;
    char command[BUFFER_SIZE];
    float latDelta, longDelta;

    initializeDrone(&drone);

    while (1) {
        displayMenu();
        printf("Enter command: ");
        if (fgets(command, BUFFER_SIZE, stdin) != NULL) {
            command[strcspn(command, "\n")] = 0; // remove newline character
        } else {
            continue; // if fgets fails, skip to next loop
        }

        if (strcmp(command, "1") == 0) {
            takeOff(&drone);
        } else if (strcmp(command, "2") == 0) {
            land(&drone);
        } else if (strcmp(command, "3") == 0) {
            printf("Enter latitude delta: ");
            scanf("%f", &latDelta);
            printf("Enter longitude delta: ");
            scanf("%f", &longDelta);
            move(&drone, latDelta, longDelta);
            // Clear input buffer to prevent issues
            while (getchar() != '\n'); 
        } else if (strcmp(command, "4") == 0) {
            showStatus(&drone);
        } else if (strcmp(command, "5") == 0) {
            printf("Exiting control panel. Safe travels!\n");
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }

    return 0;
}