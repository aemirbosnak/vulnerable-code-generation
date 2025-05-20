//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 1
#define INITIAL_SPEED 50
#define ACCELERATION 10
#define DECELERATION 5
#define TURN_RADIUS 20
#define TURN_SPEED 5
#define WAIT_TIME 100

typedef struct {
    int x;
    int y;
    int speed;
    int direction;
} Vehicle;

void init_vehicle(Vehicle *vehicle) {
    vehicle->x = 0;
    vehicle->y = 0;
    vehicle->speed = INITIAL_SPEED;
    vehicle->direction = 0;
}

void move_vehicle(Vehicle *vehicle) {
    if (vehicle->direction == 0) {
        vehicle->y += vehicle->speed;
    } else {
        vehicle->x += vehicle->speed;
    }
}

void turn_vehicle(Vehicle *vehicle, int turn) {
    if (turn == 1) {
        vehicle->direction = 1;
    } else if (turn == -1) {
        vehicle->direction = 0;
    }
}

void accelerate_vehicle(Vehicle *vehicle) {
    if (vehicle->speed < MAX_SPEED) {
        vehicle->speed += ACCELERATION;
    }
}

void decelerate_vehicle(Vehicle *vehicle) {
    if (vehicle->speed > MIN_SPEED) {
        vehicle->speed -= DECELERATION;
    }
}

void main() {
    srand(time(NULL));

    Vehicle vehicle;
    init_vehicle(&vehicle);

    int choice;
    do {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Accelerate\n");
        printf("5. Decelerate\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_vehicle(&vehicle);
                break;
            case 2:
                turn_vehicle(&vehicle, -1);
                break;
            case 3:
                turn_vehicle(&vehicle, 1);
                break;
            case 4:
                accelerate_vehicle(&vehicle);
                break;
            case 5:
                decelerate_vehicle(&vehicle);
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Current position: (%d, %d)\n", vehicle.x, vehicle.y);
        printf("Current speed: %d\n", vehicle.speed);
        printf("Current direction: %d\n", vehicle.direction);

        usleep(WAIT_TIME * 1000);
    } while (1);
}