//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_VEHICLES 5

typedef struct {
    char name[30];
    int position;
    int direction; // 0: stopped, 1: forward, 2: backward
} Vehicle;

Vehicle vehicles[MAX_VEHICLES];
int vehicleCount = 0;

void addVehicle(const char *name) {
    if (vehicleCount < MAX_VEHICLES) {
        strncpy(vehicles[vehicleCount].name, name, sizeof(vehicles[vehicleCount].name) - 1);
        vehicles[vehicleCount].position = 0;
        vehicles[vehicleCount].direction = 0;
        vehicleCount++;
        printf("Vehicle '%s' added successfully.\n", name);
    } else {
        printf("Vehicle limit reached. Cannot add more vehicles.\n");
    }
}

void moveVehicle(int index, int direction) {
    if (index < 0 || index >= vehicleCount) {
        printf("Invalid vehicle index!\n");
        return;
    }

    if (direction == 1) {
        vehicles[index].position += 1;
        vehicles[index].direction = 1;
        printf("Vehicle '%s' moved forward. New position: %d\n", vehicles[index].name, vehicles[index].position);
    } else if (direction == 2) {
        vehicles[index].position -= 1;
        vehicles[index].direction = 2;
        printf("Vehicle '%s' moved backward. New position: %d\n", vehicles[index].name, vehicles[index].position);
    } else {
        printf("Vehicle '%s' stopped.\n", vehicles[index].name);
        vehicles[index].direction = 0;
    }
}

void listVehicles() {
    printf("\nCurrent Vehicles:\n");
    for (int i = 0; i < vehicleCount; i++) {
        printf("Index: %d, Name: %s, Position: %d, Direction: %s\n", 
               i, vehicles[i].name, vehicles[i].position,
               vehicles[i].direction == 0 ? "Stopped" : (vehicles[i].direction == 1 ? "Forward" : "Backward"));
    }
}

int main() {
    char command[MAX_COMMAND_LENGTH];
    char vehicleName[30];
    int index, direction;

    printf("Welcome to the Remote Control Vehicle Simulator!\n");

    while (1) {
        printf("\nEnter a command (add/list/move/stop/exit): ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = 0; // Remove trailing newline

        if (strcmp(command, "add") == 0) {
            printf("Enter vehicle name: ");
            fgets(vehicleName, sizeof(vehicleName), stdin);
            vehicleName[strcspn(vehicleName, "\n")] = 0; // Remove trailing newline
            addVehicle(vehicleName);
        } else if (strcmp(command, "list") == 0) {
            listVehicles();
        } else if (strcmp(command, "move") == 0) {
            printf("Enter vehicle index (0 to %d): ", vehicleCount - 1);
            scanf("%d", &index);
            printf("Enter direction (1: forward, 2: backward): ");
            scanf("%d", &direction);
            getchar(); // Clear the newline character from input buffer
            moveVehicle(index, direction);
        } else if (strcmp(command, "stop") == 0) {
            printf("Enter vehicle index (0 to %d): ", vehicleCount - 1);
            scanf("%d", &index);
            getchar(); // Clear the newline character from input buffer
            moveVehicle(index, 0);
        } else if (strcmp(command, "exit") == 0) {
            printf("Exiting the simulator. Goodbye!\n");
            break;
        } else {
            printf("Invalid command! Please try again.\n");
        }
    }

    return 0;
}