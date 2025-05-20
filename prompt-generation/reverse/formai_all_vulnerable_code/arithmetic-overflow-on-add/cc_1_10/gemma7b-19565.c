//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_ROTATION 90

typedef struct Vehicle {
    int x, y, direction, speed, rotation;
} Vehicle;

void moveVehicle(Vehicle *vehicle) {
    int dx, dy;

    switch (vehicle->direction) {
        case 0:
            dx = vehicle->speed;
            dy = 0;
            break;
        case 1:
            dx = vehicle->speed;
            dy = vehicle->speed;
            break;
        case 2:
            dx = 0;
            dy = -vehicle->speed;
            break;
        case 3:
            dx = -vehicle->speed;
            dy = 0;
            break;
    }

    vehicle->x += dx;
    vehicle->y += dy;
}

void turnVehicle(Vehicle *vehicle, int angle) {
    vehicle->rotation += angle;

    if (vehicle->rotation > MAX_ROTATION) {
        vehicle->rotation = MAX_ROTATION;
    } else if (vehicle->rotation < 0) {
        vehicle->rotation = 0;
    }
}

int main() {
    Vehicle vehicle;

    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.direction = 0;
    vehicle.speed = 5;
    vehicle.rotation = 0;

    time_t start_time = time(NULL);
    time_t end_time = start_time + 10;

    while (time(NULL) < end_time) {
        moveVehicle(&vehicle);
        turnVehicle(&vehicle, 10);

        printf("x: %d, y: %d, direction: %d, speed: %d, rotation: %d\n", vehicle.x, vehicle.y, vehicle.direction, vehicle.speed, vehicle.rotation);

        sleep(0.1);
    }

    return 0;
}