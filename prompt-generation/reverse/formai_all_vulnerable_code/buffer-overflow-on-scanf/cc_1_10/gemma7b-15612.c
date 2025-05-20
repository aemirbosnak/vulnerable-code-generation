//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_ROTATION 90

typedef struct RemoteControlVehicle {
    int x;
    int y;
    int direction;
    int speed;
} RemoteControlVehicle;

RemoteControlVehicle vehicle;

void moveVehicle(int direction, int speed) {
    switch (direction) {
        case 0:
            vehicle.x++;
            break;
        case 1:
            vehicle.y++;
            break;
        case 2:
            vehicle.x--;
            break;
        case 3:
            vehicle.y--;
            break;
    }

    vehicle.speed = speed;
}

int main() {
    int command;
    int direction;
    int speed;

    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.direction = 0;
    vehicle.speed = 0;

    while (1) {
        printf("Enter command (0-3, 4-8): ");
        scanf("%d", &command);

        switch (command) {
            case 0:
                moveVehicle(0, MAX_SPEED);
                break;
            case 1:
                moveVehicle(1, MAX_SPEED);
                break;
            case 2:
                moveVehicle(2, MAX_SPEED);
                break;
            case 3:
                moveVehicle(3, MAX_SPEED);
                break;
            case 4:
                vehicle.direction = (vehicle.direction + MAX_ROTATION) % MAX_ROTATION;
                break;
            case 5:
                vehicle.direction = (vehicle.direction - MAX_ROTATION) % MAX_ROTATION;
                break;
            case 6:
                vehicle.speed++;
                break;
            case 7:
                vehicle.speed--;
                break;
            case 8:
                exit(0);
                break;
        }

        printf("Vehicle position: (%d, %d)\n", vehicle.x, vehicle.y);
        printf("Vehicle direction: %d\n", vehicle.direction);
        printf("Vehicle speed: %d\n", vehicle.speed);
    }

    return 0;
}