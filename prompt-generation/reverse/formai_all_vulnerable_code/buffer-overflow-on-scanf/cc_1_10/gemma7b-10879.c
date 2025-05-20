//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

typedef struct Vehicle {
    int x, y, facing, speed;
    char key_pressed;
} Vehicle;

Vehicle vehicle;

void initialize_vehicle() {
    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.facing = 0;
    vehicle.speed = 0;
    vehicle.key_pressed = '\0';
}

void move_vehicle() {
    switch (vehicle.key_pressed) {
        case 'w':
            vehicle.speed = MAX_SPEED;
            vehicle.facing = 0;
            break;
        case 'a':
            vehicle.speed = MAX_SPEED;
            vehicle.facing = 90;
            break;
        case 's':
            vehicle.speed = MAX_SPEED;
            vehicle.facing = 180;
            break;
        case 'd':
            vehicle.speed = MAX_SPEED;
            vehicle.facing = 270;
            break;
        default:
            vehicle.speed = 0;
            break;
    }

    switch (vehicle.facing) {
        case 0:
            vehicle.x++;
            break;
        case 90:
            vehicle.y++;
            break;
        case 180:
            vehicle.x--;
            break;
        case 270:
            vehicle.y--;
            break;
    }
}

int main() {
    initialize_vehicle();

    while (1) {
        printf("Enter a key: ");
        scanf("%c", &vehicle.key_pressed);

        move_vehicle();

        printf("Position: (%d, %d)\n", vehicle.x, vehicle.y);
    }

    return 0;
}