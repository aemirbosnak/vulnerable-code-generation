//Gemma-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10

typedef struct Vehicle {
    int x;
    int y;
    int direction;
    int speed;
} Vehicle;

Vehicle vehicle;

void update_vehicle() {
    switch (vehicle.direction) {
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

    vehicle.speed--;
    if (vehicle.speed <= 0) {
        vehicle.speed = 0;
    }
}

int main() {
    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.direction = 0;
    vehicle.speed = MAX_SPEED;

    time_t start_time = time(NULL);
    time_t end_time = start_time + 10;

    while (time(NULL) < end_time) {
        update_vehicle();
        sleep(0.1);
    }

    printf("Vehicle position: (%d, %d)\n", vehicle.x, vehicle.y);

    return 0;
}