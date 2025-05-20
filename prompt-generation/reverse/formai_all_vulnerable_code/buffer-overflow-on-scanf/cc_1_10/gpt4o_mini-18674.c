//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 10

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    char direction; // N, E, S, W
} Vehicle;

void initializeVehicle(Vehicle* vehicle) {
    vehicle->position.x = GRID_SIZE / 2;
    vehicle->position.y = GRID_SIZE / 2;
    vehicle->direction = 'N'; // start facing north
}

void printGrid(Vehicle* vehicle) {
    system("clear"); // Use "cls" for Windows
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (i == vehicle->position.y && j == vehicle->position.x) {
                printf("V ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void moveForward(Vehicle* vehicle) {
    switch (vehicle->direction) {
        case 'N': if (vehicle->position.y > 0) vehicle->position.y--; break;
        case 'E': if (vehicle->position.x < GRID_SIZE - 1) vehicle->position.x++; break;
        case 'S': if (vehicle->position.y < GRID_SIZE - 1) vehicle->position.y++; break;
        case 'W': if (vehicle->position.x > 0) vehicle->position.x--; break;
    }
}

void moveBackward(Vehicle* vehicle) {
    switch (vehicle->direction) {
        case 'N': if (vehicle->position.y < GRID_SIZE - 1) vehicle->position.y++; break;
        case 'E': if (vehicle->position.x > 0) vehicle->position.x--; break;
        case 'S': if (vehicle->position.y > 0) vehicle->position.y--; break;
        case 'W': if (vehicle->position.x < GRID_SIZE - 1) vehicle->position.x++; break;
    }
}

void turnLeft(Vehicle* vehicle) {
    switch (vehicle->direction) {
        case 'N': vehicle->direction = 'W'; break;
        case 'E': vehicle->direction = 'N'; break;
        case 'S': vehicle->direction = 'E'; break;
        case 'W': vehicle->direction = 'S'; break;
    }
}

void turnRight(Vehicle* vehicle) {
    switch (vehicle->direction) {
        case 'N': vehicle->direction = 'E'; break;
        case 'E': vehicle->direction = 'S'; break;
        case 'S': vehicle->direction = 'W'; break;
        case 'W': vehicle->direction = 'N'; break;
    }
}

void executeCommand(Vehicle* vehicle, char command) {
    switch (command) {
        case 'w': moveForward(vehicle); break; // Move Forward
        case 's': moveBackward(vehicle); break; // Move Backward
        case 'a': turnLeft(vehicle); break; // Turn Left
        case 'd': turnRight(vehicle); break; // Turn Right
        case 'q': exit(0); // Quit
        default: printf("Invalid Command!\n");
    }
}

int main() {
    Vehicle vehicle;
    initializeVehicle(&vehicle);

    char command;

    while (1) {
        printGrid(&vehicle);
        printf("Enter command (w/a/s/d to move, q to quit): ");
        scanf(" %c", &command);
        executeCommand(&vehicle, command);
    }

    return 0;
}