//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_VEHICLES 10
#define MAX_COMMAND_SIZE 50

typedef enum {
    STOPPED,
    MOVING_FORWARD,
    MOVING_BACKWARD
} VehicleState;

typedef struct {
    char name[20];
    VehicleState state;
    int speed; // speed can be between 0 and 100
} RemoteControlVehicle;

RemoteControlVehicle vehicles[MAX_VEHICLES];
int vehicleCount = 0;

void initializeVehicle(char *name) {
    if (vehicleCount >= MAX_VEHICLES) {
        printf("Maximum vehicle limit reached.\n");
        return;
    }
    strcpy(vehicles[vehicleCount].name, name);
    vehicles[vehicleCount].state = STOPPED;
    vehicles[vehicleCount].speed = 0;
    vehicleCount++;
    printf("Vehicle '%s' initialized!\n", name);
}

void startVehicle(char *name) {
    for (int i = 0; i < vehicleCount; i++) {
        if (strcmp(vehicles[i].name, name) == 0) {
            if (vehicles[i].state == STOPPED) {
                vehicles[i].state = MOVING_FORWARD;
                vehicles[i].speed = 10; // default speed
                printf("Vehicle '%s' started moving forward at speed %d\n", name, vehicles[i].speed);
            } else {
                printf("Vehicle '%s' is already in motion.\n", name);
            }
            return;
        }
    }
    printf("Vehicle '%s' not found.\n", name);
}

void stopVehicle(char *name) {
    for (int i = 0; i < vehicleCount; i++) {
        if (strcmp(vehicles[i].name, name) == 0) {
            vehicles[i].state = STOPPED;
            vehicles[i].speed = 0;
            printf("Vehicle '%s' has stopped.\n", name);
            return;
        }
    }
    printf("Vehicle '%s' not found.\n", name);
}

void setSpeed(char *name, int speed) {
    for (int i = 0; i < vehicleCount; i++) {
        if (strcmp(vehicles[i].name, name) == 0) {
            if (speed >= 0 && speed <= 100) {
                vehicles[i].speed = speed;
                printf("Speed of vehicle '%s' set to %d\n", name, speed);
            } else {
                printf("Invalid speed. Please enter a value between 0 and 100.\n");
            }
            return;
        }
    }
    printf("Vehicle '%s' not found.\n", name);
}

void displayStatus() {
    printf("\nVehicle Status:\n");
    for (int i = 0; i < vehicleCount; i++) {
        printf("Name: %s, State: %s, Speed: %d\n", vehicles[i].name,
            vehicles[i].state == STOPPED ? "Stopped" : (vehicles[i].state == MOVING_FORWARD ? "Moving Forward" : "Moving Backward"),
            vehicles[i].speed);
    }
    printf("\n");
}

void executeCommand(char *command) {
    char vehicleName[20];
    int speed;

    if (sscanf(command, "initialize %s", vehicleName) == 1) {
        initializeVehicle(vehicleName);
    } else if (sscanf(command, "start %s", vehicleName) == 1) {
        startVehicle(vehicleName);
    } else if (sscanf(command, "stop %s", vehicleName) == 1) {
        stopVehicle(vehicleName);
    } else if (sscanf(command, "set_speed %s %d", vehicleName, &speed) == 2) {
        setSpeed(vehicleName, speed);
    } else if (strcmp(command, "status") == 0) {
        displayStatus();
    } else {
        printf("Unknown command: %s\n", command);
    }
}

int main() {
    char command[MAX_COMMAND_SIZE];

    printf("Remote Control Vehicle Simulation\n");
    printf("Commands:\n");
    printf("initialize <vehicle_name>\n");
    printf("start <vehicle_name>\n");
    printf("stop <vehicle_name>\n");
    printf("set_speed <vehicle_name> <speed>\n");
    printf("status\n");
    printf("exit\n");

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_SIZE, stdin);
        command[strcspn(command, "\n")] = 0; // remove newline character

        if (strcmp(command, "exit") == 0) {
            break;
        }

        executeCommand(command);
    }

    printf("Exiting simulation.\n");
    return 0;
}