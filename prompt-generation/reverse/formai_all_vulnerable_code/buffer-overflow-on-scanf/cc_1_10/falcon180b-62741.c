//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define MAX_TURN 20
#define MIN_TURN 1
#define MAX_ACCELERATION 5
#define MIN_ACCELERATION 1
#define MAX_DECELERATION 5
#define MIN_DECELERATION 1
#define MAX_STEPS 10000

typedef struct {
    int speed;
    int turn;
    int acceleration;
    int deceleration;
    int steps;
} vehicle_t;

void initialize_vehicle(vehicle_t* vehicle) {
    vehicle->speed = MIN_SPEED;
    vehicle->turn = 0;
    vehicle->acceleration = MIN_ACCELERATION;
    vehicle->deceleration = MIN_DECELERATION;
    vehicle->steps = 0;
}

void update_vehicle(vehicle_t* vehicle) {
    vehicle->steps++;
    if (vehicle->steps >= MAX_STEPS) {
        printf("Vehicle has reached maximum steps.\n");
        exit(EXIT_FAILURE);
    }
    if (vehicle->speed >= MAX_SPEED) {
        vehicle->acceleration = MIN_ACCELERATION;
    } else if (vehicle->speed <= MIN_SPEED) {
        vehicle->deceleration = MIN_DECELERATION;
    }
    if (vehicle->turn >= MAX_TURN) {
        vehicle->turn = MIN_TURN;
    } else if (vehicle->turn <= MIN_TURN) {
        vehicle->turn = MAX_TURN;
    }
    vehicle->speed += vehicle->acceleration;
    vehicle->turn += vehicle->deceleration;
}

void print_vehicle_status(vehicle_t* vehicle) {
    printf("Vehicle speed: %d\n", vehicle->speed);
    printf("Vehicle turn: %d\n", vehicle->turn);
    printf("Vehicle steps: %d\n", vehicle->steps);
}

int main() {
    vehicle_t vehicle;
    initialize_vehicle(&vehicle);
    while (1) {
        printf("Enter speed (1-%d): ", MAX_SPEED);
        scanf("%d", &vehicle.speed);
        printf("Enter turn (1-%d): ", MAX_TURN);
        scanf("%d", &vehicle.turn);
        update_vehicle(&vehicle);
        print_vehicle_status(&vehicle);
        usleep(100000);
    }
    return 0;
}