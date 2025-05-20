//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_TURN 90
#define MIN_TURN -90

typedef struct {
    int speed;
    int turn;
} vehicle_t;

vehicle_t *create_vehicle() {
    vehicle_t *vehicle = (vehicle_t *)malloc(sizeof(vehicle_t));
    vehicle->speed = 0;
    vehicle->turn = 0;
    return vehicle;
}

void destroy_vehicle(vehicle_t *vehicle) {
    free(vehicle);
}

void move_vehicle(vehicle_t *vehicle, int speed, int turn) {
    if (speed < MIN_SPEED) {
        speed = MIN_SPEED;
    } else if (speed > MAX_SPEED) {
        speed = MAX_SPEED;
    }

    if (turn < MIN_TURN) {
        turn = MIN_TURN;
    } else if (turn > MAX_TURN) {
        turn = MAX_TURN;
    }

    printf("Vehicle is moving at %d km/h and turning by %d degrees\n", speed, turn);
}

int main() {
    srand(time(NULL));

    vehicle_t *vehicle = create_vehicle();

    int speed = rand() % MAX_SPEED + MIN_SPEED;
    int turn = rand() % MAX_TURN + MIN_TURN;

    move_vehicle(vehicle, speed, turn);

    destroy_vehicle(vehicle);

    return 0;
}