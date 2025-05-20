//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_VEHICLES 10
#define NAME_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    float speed; // Speed in meters per second
    float direction; // Direction in degrees
    float distance_traveled; // Distance traveled in meters
} Vehicle;

void initializeVehicle(Vehicle *v, const char *name) {
    strcpy(v->name, name);
    v->speed = 0.0;
    v->direction = 0.0;
    v->distance_traveled = 0.0;
}

void setSpeed(Vehicle *v, float speed) {
    v->speed = speed;
    printf("%s's speed set to %.2f m/s\n", v->name, v->speed);
}

void setDirection(Vehicle *v, float direction) {
    v->direction = direction;
    printf("%s's direction set to %.2f degrees\n", v->name, v->direction);
}

void moveVehicle(Vehicle *v, float time) {
    if (v->speed > 0) {
        v->distance_traveled += v->speed * time;
        printf("%s moved %.2f meters in %.2f seconds at a speed of %.2f m/s\n", 
               v->name, v->speed * time, time, v->speed);
    } else {
        printf("%s is stationary, cannot move\n", v->name);
    }
}

void displayStatus(Vehicle *v) {
    printf("Vehicle: %s\n", v->name);
    printf("Speed: %.2f m/s\n", v->speed);
    printf("Direction: %.2f degrees\n", v->direction);
    printf("Distance Traveled: %.2f meters\n\n", v->distance_traveled);
}

void listVehicles(Vehicle vehicles[], int count) {
    printf("List of Vehicles:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, vehicles[i].name);
    }
}

int main() {
    Vehicle vehicles[MAX_VEHICLES];
    int vehicleCount = 0;
    char command[50];
    char vehicleName[NAME_LENGTH];

    while (1) {
        printf("Commands: add <name>, speed <name> <value>, direction <name> <value>, move <name> <time>, status <name>, list, exit\n");
        printf("Enter command: ");
        scanf(" %[^\n]", command);
        
        if (strncmp(command, "add ", 4) == 0) {
            if (vehicleCount >= MAX_VEHICLES) {
                printf("Cannot add more vehicles. Max limit reached.\n");
                continue;
            }
            sscanf(command + 4, "%s", vehicleName);
            initializeVehicle(&vehicles[vehicleCount], vehicleName);
            vehicleCount++;
            printf("Vehicle %s added!\n", vehicleName);
            
        } else if (strncmp(command, "speed ", 6) == 0) {
            char tempName[NAME_LENGTH];
            float speedValue;
            sscanf(command + 6, "%s %f", tempName, &speedValue);
            for (int i = 0; i < vehicleCount; i++) {
                if (strcmp(vehicles[i].name, tempName) == 0) {
                    setSpeed(&vehicles[i], speedValue);
                    break;
                }
            }

        } else if (strncmp(command, "direction ", 10) == 0) {
            char tempName[NAME_LENGTH];
            float directionValue;
            sscanf(command + 10, "%s %f", tempName, &directionValue);
            for (int i = 0; i < vehicleCount; i++) {
                if (strcmp(vehicles[i].name, tempName) == 0) {
                    setDirection(&vehicles[i], directionValue);
                    break;
                }
            }

        } else if (strncmp(command, "move ", 5) == 0) {
            char tempName[NAME_LENGTH];
            float timeValue;
            sscanf(command + 5, "%s %f", tempName, &timeValue);
            for (int i = 0; i < vehicleCount; i++) {
                if (strcmp(vehicles[i].name, tempName) == 0) {
                    moveVehicle(&vehicles[i], timeValue);
                    break;
                }
            }

        } else if (strncmp(command, "status ", 7) == 0) {
            sscanf(command + 7, "%s", vehicleName);
            for (int i = 0; i < vehicleCount; i++) {
                if (strcmp(vehicles[i].name, vehicleName) == 0) {
                    displayStatus(&vehicles[i]);
                    break;
                }
            }

        } else if (strcmp(command, "list") == 0) {
            listVehicles(vehicles, vehicleCount);

        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting simulation...\n");
            break;

        } else {
            printf("Invalid command!\n");
        }
    }
    return 0;
}