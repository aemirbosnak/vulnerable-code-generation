//GPT-4o-mini DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 10

typedef struct {
    int x;
    int y;
} Position;

typedef struct {
    Position position;
    char direction; // 'N', 'E', 'S', 'W'
} Vehicle;

void initializeVehicle(Vehicle *v) {
    v->position.x = MAP_SIZE / 2;
    v->position.y = MAP_SIZE / 2;
    v->direction = 'N'; // Initially facing North
}

void displayVehicleStatus(Vehicle *v) {
    printf("Vehicle is at position (%d, %d) facing %c\n", v->position.x, v->position.y, v->direction);
}

void moveForward(Vehicle *v) {
    switch (v->direction) {
        case 'N': v->position.y = (v->position.y - 1 + MAP_SIZE) % MAP_SIZE; break;
        case 'E': v->position.x = (v->position.x + 1) % MAP_SIZE; break;
        case 'S': v->position.y = (v->position.y + 1) % MAP_SIZE; break;
        case 'W': v->position.x = (v->position.x - 1 + MAP_SIZE) % MAP_SIZE; break;
    }
    printf("Moving Forward!\n");
}

void moveBackward(Vehicle *v) {
    switch (v->direction) {
        case 'N': v->position.y = (v->position.y + 1) % MAP_SIZE; break;
        case 'E': v->position.x = (v->position.x - 1 + MAP_SIZE) % MAP_SIZE; break;
        case 'S': v->position.y = (v->position.y - 1 + MAP_SIZE) % MAP_SIZE; break;
        case 'W': v->position.x = (v->position.x + 1) % MAP_SIZE; break;
    }
    printf("Moving Backward!\n");
}

void turnLeft(Vehicle *v) {
    switch (v->direction) {
        case 'N': v->direction = 'W'; break;
        case 'E': v->direction = 'N'; break;
        case 'S': v->direction = 'E'; break;
        case 'W': v->direction = 'S'; break;
    }
    printf("Turning Left!\n");
}

void turnRight(Vehicle *v) {
    switch (v->direction) {
        case 'N': v->direction = 'E'; break;
        case 'E': v->direction = 'S'; break;
        case 'S': v->direction = 'W'; break;
        case 'W': v->direction = 'N'; break;
    }
    printf("Turning Right!\n");
}

void stopVehicle() {
    printf("Vehicle Stopped!\n");
}

void displayInstructions() {
    printf("Control your vehicle:\n");
    printf("F - Move Forward\n");
    printf("B - Move Backward\n");
    printf("L - Turn Left\n");
    printf("R - Turn Right\n");
    printf("S - Stop\n");
    printf("Q - Quit\n");
}

int main() {
    Vehicle vehicle;
    char command;

    initializeVehicle(&vehicle);
    displayInstructions();
    displayVehicleStatus(&vehicle);

    while (1) {
        printf("Enter command: ");
        scanf(" %c", &command);

        switch (command) {
            case 'F': moveForward(&vehicle); break;
            case 'B': moveBackward(&vehicle); break;
            case 'L': turnLeft(&vehicle); break;
            case 'R': turnRight(&vehicle); break;
            case 'S': stopVehicle(); break;
            case 'Q': printf("Exiting simulation.\n"); exit(0);
            default: printf("Invalid command! Please try again.\n"); continue;
        }
        displayVehicleStatus(&vehicle);
    }

    return 0;
}