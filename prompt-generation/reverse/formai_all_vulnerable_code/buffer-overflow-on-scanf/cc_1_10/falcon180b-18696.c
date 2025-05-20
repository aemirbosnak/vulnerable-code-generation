//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1

#define MAX_TURN_RATE 10
#define MIN_TURN_RATE 1

typedef struct {
    int speed;
    int turn_rate;
} Vehicle;

void initialize_vehicle(Vehicle* vehicle) {
    vehicle->speed = 0;
    vehicle->turn_rate = 0;
}

void accelerate(Vehicle* vehicle) {
    if (vehicle->speed < MAX_SPEED) {
        vehicle->speed++;
    }
}

void decelerate(Vehicle* vehicle) {
    if (vehicle->speed > MIN_SPEED) {
        vehicle->speed--;
    }
}

void turn_left(Vehicle* vehicle) {
    if (vehicle->turn_rate < MAX_TURN_RATE) {
        vehicle->turn_rate++;
    }
}

void turn_right(Vehicle* vehicle) {
    if (vehicle->turn_rate > MIN_TURN_RATE) {
        vehicle->turn_rate--;
    }
}

int main() {
    Vehicle vehicle;
    initialize_vehicle(&vehicle);

    int choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Accelerate\n");
        printf("2. Decelerate\n");
        printf("3. Turn left\n");
        printf("4. Turn right\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                accelerate(&vehicle);
                printf("Vehicle accelerated.\n");
                break;
            case 2:
                decelerate(&vehicle);
                printf("Vehicle decelerated.\n");
                break;
            case 3:
                turn_left(&vehicle);
                printf("Vehicle turned left.\n");
                break;
            case 4:
                turn_right(&vehicle);
                printf("Vehicle turned right.\n");
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }

        printf("Current speed: %d\n", vehicle.speed);
        printf("Current turn rate: %d\n", vehicle.turn_rate);
    }

    return 0;
}