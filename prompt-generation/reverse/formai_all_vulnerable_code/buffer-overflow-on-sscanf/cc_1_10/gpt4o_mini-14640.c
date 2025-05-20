//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct {
    float altitude;
    float speed;
    int isFlying;
} Drone;

void initializeDrone(Drone *drone) {
    drone->altitude = 0.0;
    drone->speed = 0.0;
    drone->isFlying = 0; // 0 for not flying, 1 for flying
}

void takeOff(Drone *drone) {
    if (drone->isFlying) {
        printf("Drone is already flying!\n");
    } else {
        printf("Taking off...\n");
        drone->altitude = 10.0; // Set altitude when taking off
        drone->isFlying = 1;
        printf("Drone is now flying at %.2f meters altitude.\n", drone->altitude);
    }
}

void land(Drone *drone) {
    if (!drone->isFlying) {
        printf("Drone is already on the ground!\n");
    } else {
        printf("Landing...\n");
        drone->altitude = 0.0;
        drone->isFlying = 0;
        printf("Drone has landed safely.\n");
    }
}

void ascend(Drone *drone, float altitudeGain) {
    if (!drone->isFlying) {
        printf("Drone is not in flight. Please take off first.\n");
    } else {
        drone->altitude += altitudeGain;
        printf("Ascending... New altitude: %.2f meters\n", drone->altitude);
    }
}

void descend(Drone *drone, float altitudeLoss) {
    if (!drone->isFlying) {
        printf("Drone is not in flight. Please take off first.\n");
    } else {
        drone->altitude -= altitudeLoss;
        if (drone->altitude < 0) {
            drone->altitude = 0;
            printf("Descending... New altitude: 0.0 meters. Landing.\n");
            land(drone);
        } else {
            printf("Descending... New altitude: %.2f meters\n", drone->altitude);
        }
    }
}

void setSpeed(Drone *drone, float newSpeed) {
    if (!drone->isFlying) {
        printf("Drone is not in flight. Please take off first.\n");
    } else {
        drone->speed = newSpeed;
        printf("Speed set to %.2f m/s.\n", drone->speed);
    }
}

void printStatus(Drone *drone) {
    printf("\n--- Drone Status ---\n");
    printf("Altitude: %.2f meters\n", drone->altitude);
    printf("Speed: %.2f m/s\n", drone->speed);
    printf("Flying: %s\n", drone->isFlying ? "Yes" : "No");
    printf("---------------------\n");
}

int main() {
    Drone myDrone;
    initializeDrone(&myDrone);
    
    char command[100];

    printf("Welcome to the Drone Remote Control!\n");
    printf("Commands: takeoff | land | ascend <value> | descend <value> | speed <value> | status | exit\n");

    while (1) {
        printf("\nEnter command: ");
        fgets(command, sizeof(command), stdin);
        command[strcspn(command, "\n")] = 0; // Remove the newline character

        if (strcmp(command, "takeoff") == 0) {
            takeOff(&myDrone);
        } else if (strcmp(command, "land") == 0) {
            land(&myDrone);
        } else if (strncmp(command, "ascend", 6) == 0) {
            float value;
            sscanf(command + 7, "%f", &value);
            ascend(&myDrone, value);
        } else if (strncmp(command, "descend", 7) == 0) {
            float value;
            sscanf(command + 8, "%f", &value);
            descend(&myDrone, value);
        } else if (strncmp(command, "speed", 5) == 0) {
            float value;
            sscanf(command + 6, "%f", &value);
            setSpeed(&myDrone, value);
        } else if (strcmp(command, "status") == 0) {
            printStatus(&myDrone);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the drone control program.\n");
            break;
        } else {
            printf("Unknown command! Please try again.\n");
        }
    }

    return 0;
}