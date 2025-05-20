//Code Llama-13B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

typedef struct {
    int x;
    int y;
    int z;
} Point;

typedef struct {
    Point position;
    int speed;
    int direction;
} Vehicle;

void initializeVehicle(Vehicle* vehicle) {
    vehicle->position.x = 0;
    vehicle->position.y = 0;
    vehicle->position.z = 0;
    vehicle->speed = 0;
    vehicle->direction = 0;
}

void updateVehicle(Vehicle* vehicle, int input) {
    switch (input) {
        case 'w':
            vehicle->position.x += vehicle->speed;
            break;
        case 's':
            vehicle->position.x -= vehicle->speed;
            break;
        case 'a':
            vehicle->position.y -= vehicle->speed;
            break;
        case 'd':
            vehicle->position.y += vehicle->speed;
            break;
        case 'z':
            vehicle->position.z += vehicle->speed;
            break;
        case 'x':
            vehicle->position.z -= vehicle->speed;
            break;
        default:
            break;
    }
}

int main() {
    Vehicle vehicle;
    initializeVehicle(&vehicle);

    while (1) {
        char input;
        scanf("%c", &input);

        updateVehicle(&vehicle, input);

        printf("Vehicle position: (%d, %d, %d)\n", vehicle.position.x, vehicle.position.y, vehicle.position.z);
    }

    return 0;
}