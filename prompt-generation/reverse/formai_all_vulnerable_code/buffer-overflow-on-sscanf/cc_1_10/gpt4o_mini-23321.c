//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define COMMAND_BUFFER_SIZE 256

typedef struct {
    float altitude;
    float latitude;
    float longitude;
    float speed;
} Drone;

void initDrone(Drone *drone) {
    drone->altitude = 0.0;
    drone->latitude = 0.0;
    drone->longitude = 0.0;
    drone->speed = 0.0;
    printf("Drone initialized.\n");
}

void takeOff(Drone *drone) {
    drone->altitude = 5.0; // Take off to 5 meters
    printf("Drone took off to altitude: %.2f meters\n", drone->altitude);
}

void land(Drone *drone) {
    drone->altitude = 0.0;
    printf("Drone landed. Current altitude: %.2f meters\n", drone->altitude);
}

void moveForward(Drone *drone, float distance) {
    // Simulate movement by changing latitude
    drone->latitude += distance;
    printf("Drone moved forward by: %.2f meters. Current latitude: %.2f\n", distance, drone->latitude);
}

void moveBackward(Drone *drone, float distance) {
    drone->latitude -= distance;
    printf("Drone moved backward by: %.2f meters. Current latitude: %.2f\n", distance, drone->latitude);
}

void moveLeft(Drone *drone, float distance) {
    // Simulate lateral movement by changing longitude
    drone->longitude -= distance;
    printf("Drone moved left by: %.2f meters. Current longitude: %.2f\n", distance, drone->longitude);
}

void moveRight(Drone *drone, float distance) {
    drone->longitude += distance;
    printf("Drone moved right by: %.2f meters. Current longitude: %.2f\n", distance, drone->longitude);
}

void changeSpeed(Drone *drone, float newSpeed) {
    drone->speed = newSpeed;
    printf("Drone speed changed to: %.2f m/s\n", drone->speed);
}

void hover(Drone *drone) {
    printf("Drone is hovering at altitude: %.2f meters\n", drone->altitude);
}

void showStatus(Drone *drone) {
    printf("\n--- Drone Status ---\n");
    printf("Altitude: %.2f meters\n", drone->altitude);
    printf("Latitude: %.2f\n", drone->latitude);
    printf("Longitude: %.2f\n", drone->longitude);
    printf("Speed: %.2f m/s\n", drone->speed);
    printf("---------------------\n");
}

void processCommand(Drone *drone, const char *command) {
    char cmd[COMMAND_BUFFER_SIZE];
    float param;

    if (sscanf(command, "%s %f", cmd, &param) < 1) {
        printf("Invalid command.\n");
        return;
    }

    if (strcmp(cmd, "takeoff") == 0) {
        takeOff(drone);
    } else if (strcmp(cmd, "land") == 0) {
        land(drone);
    } else if (strcmp(cmd, "forward") == 0) {
        moveForward(drone, param);
    } else if (strcmp(cmd, "backward") == 0) {
        moveBackward(drone, param);
    } else if (strcmp(cmd, "left") == 0) {
        moveLeft(drone, param);
    } else if (strcmp(cmd, "right") == 0) {
        moveRight(drone, param);
    } else if (strcmp(cmd, "speed") == 0) {
        changeSpeed(drone, param);
    } else if (strcmp(cmd, "hover") == 0) {
        hover(drone);
    } else if (strcmp(cmd, "status") == 0) {
        showStatus(drone);
    } else {
        printf("Unknown command: %s\n", cmd);
    }
}

int main() {
    Drone drone;
    char command[COMMAND_BUFFER_SIZE];

    initDrone(&drone);
    
    printf("Welcome to the Drone Remote Control Program!\n");
    printf("Commands: \ntakeoff | land | forward <distance> | backward <distance> | "
           "left <distance> | right <distance> | speed <value> | hover | status | exit\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, COMMAND_BUFFER_SIZE, stdin);
        command[strcspn(command, "\n")] = '\0'; // Remove newline character

        if (strcmp(command, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        }

        processCommand(&drone, command);
    }

    return 0;
}