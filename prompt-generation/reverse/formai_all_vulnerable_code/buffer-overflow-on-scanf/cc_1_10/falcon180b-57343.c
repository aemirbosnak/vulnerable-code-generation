//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define TURN_RATE 5

typedef struct {
    int speed;
    int direction;
} vehicle_t;

void move_vehicle(vehicle_t *vehicle) {
    int dx = vehicle->speed * cos(vehicle->direction);
    int dy = vehicle->speed * sin(vehicle->direction);

    printf("Vehicle moved (%d, %d)\n", dx, dy);
}

void turn_vehicle(vehicle_t *vehicle, int angle) {
    vehicle->direction += angle;
    if (vehicle->direction > 360) {
        vehicle->direction -= 360;
    } else if (vehicle->direction < 0) {
        vehicle->direction += 360;
    }
}

int main() {
    srand(time(NULL));

    vehicle_t vehicle;
    vehicle.speed = rand() % (MAX_SPEED - MIN_SPEED + 1) + MIN_SPEED;
    vehicle.direction = rand() % 360;

    int choice;
    do {
        printf("Choose an option:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                move_vehicle(&vehicle);
                break;
            case 2:
                turn_vehicle(&vehicle, -TURN_RATE);
                break;
            case 3:
                turn_vehicle(&vehicle, TURN_RATE);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}