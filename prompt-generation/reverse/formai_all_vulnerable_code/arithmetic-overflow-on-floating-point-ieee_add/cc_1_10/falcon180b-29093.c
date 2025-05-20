//Falcon-180B DATASET v1.0 Category: Drone Remote Control ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a drone
typedef struct {
    int id;
    char name[20];
    int batteryLevel;
    float x, y, z;
} Drone;

// Define the function to initialize a drone
void initDrone(Drone* drone, int id, char* name, int batteryLevel, float x, float y, float z) {
    drone->id = id;
    strcpy(drone->name, name);
    drone->batteryLevel = batteryLevel;
    drone->x = x;
    drone->y = y;
    drone->z = z;
}

// Define the function to move a drone
void moveDrone(Drone* drone, float dx, float dy, float dz) {
    drone->x += dx;
    drone->y += dy;
    drone->z += dz;
}

// Define the function to print a drone
void printDrone(Drone* drone) {
    printf("ID: %d\nName: %s\nBattery Level: %d%%\nPosition: (%f, %f, %f)\n", drone->id, drone->name, drone->batteryLevel, drone->x, drone->y, drone->z);
}

// Define the function to control a drone
void controlDrone(Drone* drone, char* command) {
    if (strcmp(command, "move") == 0) {
        float dx, dy, dz;
        scanf("%f %f %f", &dx, &dy, &dz);
        moveDrone(drone, dx, dy, dz);
    } else if (strcmp(command, "print") == 0) {
        printDrone(drone);
    } else {
        printf("Invalid command\n");
    }
}

// Define the main function
int main() {
    // Initialize the drone
    Drone drone1;
    initDrone(&drone1, 1, "Drone 1", 100, 0, 0, 0);

    // Control the drone
    char command[20];
    while (1) {
        printf("Enter command: ");
        scanf("%s", command);
        controlDrone(&drone1, command);
    }

    return 0;
}