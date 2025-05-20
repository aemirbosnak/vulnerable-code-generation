//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MIN_SPEED 1
#define ACCELERATION 0.1
#define DECELERATION 0.1
#define TURN_RADIUS 50
#define FORWARD_DISTANCE 500
#define TURN_DISTANCE 100

typedef struct {
    int x;
    int y;
    int speed;
    int direction;
} Vehicle;

void moveVehicle(Vehicle* vehicle, int speed, int direction) {
    if (direction == 1) {
        vehicle->x += speed;
        vehicle->y -= speed;
    } else {
        vehicle->x -= speed;
        vehicle->y += speed;
    }
}

void turnVehicle(Vehicle* vehicle, int direction) {
    if (direction == 1) {
        vehicle->direction = 1;
    } else {
        vehicle->direction = -1;
    }
}

void accelerateVehicle(Vehicle* vehicle) {
    vehicle->speed += ACCELERATION;
    if (vehicle->speed > MAX_SPEED) {
        vehicle->speed = MAX_SPEED;
    }
}

void decelerateVehicle(Vehicle* vehicle) {
    vehicle->speed -= DECELERATION;
    if (vehicle->speed < MIN_SPEED) {
        vehicle->speed = MIN_SPEED;
    }
}

int main() {
    srand(time(NULL));

    Vehicle vehicle;
    vehicle.x = rand() % 1000;
    vehicle.y = rand() % 1000;
    vehicle.speed = MIN_SPEED;
    vehicle.direction = 1;

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
                moveVehicle(&vehicle, vehicle.speed, vehicle.direction);
                break;
            case 2:
                turnVehicle(&vehicle, -1);
                break;
            case 3:
                turnVehicle(&vehicle, 1);
                break;
            case 4:
                accelerateVehicle(&vehicle);
                break;
            case 5:
                decelerateVehicle(&vehicle);
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Current position: (%d, %d)\n", vehicle.x, vehicle.y);
        printf("Current speed: %d\n", vehicle.speed);
        printf("Current direction: %d\n", vehicle.direction);
    } while (1);

    return 0;
}