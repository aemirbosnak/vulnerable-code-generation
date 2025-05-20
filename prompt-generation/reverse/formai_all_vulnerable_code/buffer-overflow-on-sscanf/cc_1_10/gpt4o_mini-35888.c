//GPT-4o-mini DATASET v1.0 Category: Drone Remote Control ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ALTITUDE 100
#define MIN_ALTITUDE 0

typedef struct {
    int altitude;  // The current altitude of the drone
    int speed;     // The current speed of the drone
} Drone;

void printWelcomeMessage() {
    printf("============================================\n");
    printf("       Welcome to the Drone Control!       \n");
    printf("============================================\n");
}

void printDroneStatus(const Drone *drone) {
    printf("Current altitude: %d meters\n", drone->altitude);
    printf("Current speed: %d m/s\n", drone->speed);
}

void increaseAltitude(Drone *drone, int increment) {
    drone->altitude += increment;
    if (drone->altitude > MAX_ALTITUDE) {
        drone->altitude = MAX_ALTITUDE;
        printf("Maximum altitude reached!\n");
    } else {
        printf("Increasing altitude by %d meters...\n", increment);
    }
}

void decreaseAltitude(Drone *drone, int decrement) {
    drone->altitude -= decrement;
    if (drone->altitude < MIN_ALTITUDE) {
        drone->altitude = MIN_ALTITUDE;
        printf("Drone is at ground level!\n");
    } else {
        printf("Decreasing altitude by %d meters...\n", decrement);
    }
}

void setSpeed(Drone *drone, int speed) {
    drone->speed = speed;
    printf("Setting speed to %d m/s...\n", speed);
}

void executeCommand(Drone *drone, char *command) {
    char action[MAX_COMMAND_LENGTH];
    int value;

    // Parsing the command
    if (sscanf(command, "%s %d", action, &value) == 2) {
        if (strcmp(action, "up") == 0) {
            increaseAltitude(drone, value);
        } else if (strcmp(action, "down") == 0) {
            decreaseAltitude(drone, value);
        } else if (strcmp(action, "speed") == 0) {
            setSpeed(drone, value);
        } else {
            printf("Unknown command: %s\n", action);
        }
    } else if (strcmp(command, "status") == 0) {
        printDroneStatus(drone);
    } else {
        printf("Command must be in the format: <action> <value>\n");
    }
}

int main() {
    Drone drone = {0, 0};
    char command[MAX_COMMAND_LENGTH];

    printWelcomeMessage();

    // Main control loop
    while (1) {
        printf("> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0';  // Remove trailing newline

        if (strcmp(command, "exit") == 0) {
            printf("Exiting the Drone Control. Safe flying!\n");
            break;
        } else {
            executeCommand(&drone, command);
            printDroneStatus(&drone);
        }
    }

    return 0;
}