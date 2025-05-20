//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define drone states
typedef enum {
    IDLE,
    FLYING,
    LANDING,
    HOVERING
} DroneState;

// Drone structure
typedef struct {
    DroneState state;
    float altitude; // in meters
    float batteryLevel; // in percentage
} Drone;

// Function to initialize the drone
void initializeDrone(Drone *drone) {
    drone->state = IDLE;
    drone->altitude = 0.0;
    drone->batteryLevel = 100.0; // Fully charged
}

// Function to take off
void takeOff(Drone *drone) {
    if (drone->batteryLevel < 10.0) {
        printf("Battery too low to take off.\n");
        return;
    }
    drone->state = FLYING;
    drone->altitude = 5.0; // Taking off to 5 meters
    printf("Drone is taking off. Current altitude: %.2f meters\n", drone->altitude);
}

// Function to land
void land(Drone *drone) {
    if (drone->state == FLYING) {
        drone->altitude = 0.0; // Landing to 0 meters
        drone->state = LANDING;
        printf("Drone is landing. Current altitude: %.2f meters\n", drone->altitude);
        drone->state = IDLE;
    } else {
        printf("Drone is not flying.\n");
    }
}

// Function to hover
void hover(Drone *drone) {
    if (drone->state == FLYING) {
        drone->state = HOVERING;
        printf("Drone is hovering at %.2f meters.\n", drone->altitude);
    } else {
        printf("Drone is not in the air. Take off first.\n");
    }
}

// Function to check battery status
void checkBattery(Drone *drone) {
    printf("Battery level is at: %.2f%%\n", drone->batteryLevel);
}

// Function to update battery status (simulated)
void updateBattery(Drone *drone, float consumption) {
    drone->batteryLevel -= consumption;
    if (drone->batteryLevel < 0) {
        drone->batteryLevel = 0;
    }
}

// Function to simulate flight commands
void controlDrone(Drone *drone) {
    char command[20];

    while (1) {
        printf("Enter command (takeoff, land, hover, battery, exit): ");
        scanf("%s", command);

        if (strcmp(command, "takeoff") == 0) {
            takeOff(drone);
        } else if (strcmp(command, "land") == 0) {
            land(drone);
        } else if (strcmp(command, "hover") == 0) {
            hover(drone);
        } else if (strcmp(command, "battery") == 0) {
            checkBattery(drone);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid command. Please try again.\n");
        }

        updateBattery(drone, 5.0); // Simulating battery consumption per command
    }
}

int main() {
    Drone myDrone;
    initializeDrone(&myDrone);
    printf("Drone Remote Control Initialized.\n");
    controlDrone(&myDrone);
    return 0;
}