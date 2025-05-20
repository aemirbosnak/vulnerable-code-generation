//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

struct vehicle {
    int x, y;
    int speed;
};

void move_vehicle(struct vehicle *vehicle, int direction) {
    if (direction == 1) {
        vehicle->y++;
    } else if (direction == -1) {
        vehicle->y--;
    }
    vehicle->x += vehicle->speed * direction;
}

void display_vehicle(struct vehicle *vehicle) {
    printf("Vehicle at position (%d,%d)\n", vehicle->x, vehicle->y);
}

int main() {
    struct vehicle vehicle;
    int direction = 1;
    int speed = 5;

    srand(time(0));
    vehicle.x = rand() % 20;
    vehicle.y = rand() % 20;

    while (1) {
        move_vehicle(&vehicle, direction);
        display_vehicle(&vehicle);
        if (vehicle.x < 0 || vehicle.x >= 20 || vehicle.y < 0 || vehicle.y >= 20) {
            direction = -direction;
        }
        if (direction == 1) {
            if (vehicle.speed < MAX_SPEED) {
                vehicle.speed++;
            }
        } else {
            if (vehicle.speed > 1) {
                vehicle.speed--;
            }
        }
        usleep(200000);
    }

    return 0;
}