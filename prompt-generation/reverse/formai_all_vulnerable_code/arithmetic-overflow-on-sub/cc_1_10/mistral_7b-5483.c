//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SPEED 50
#define MIN_SPEED 0

typedef struct {
    char name[20];
    int speed;
    int x;
    int y;
} Vehicle;

void move_vehicle(Vehicle* vehicle, int direction, int distance) {
    switch (direction) {
        case 'F':
            if (vehicle->speed + distance <= MAX_SPEED) {
                vehicle->speed += distance;
                vehicle->x += distance;
            } else {
                vehicle->speed = MAX_SPEED;
                vehicle->x += MAX_SPEED;
            }
            break;
        case 'B':
            if (vehicle->speed - distance >= MIN_SPEED) {
                vehicle->speed -= distance;
                vehicle->x -= distance;
            } else {
                vehicle->speed = MIN_SPEED;
                vehicle->x -= MIN_SPEED;
            }
            break;
        case 'L':
            vehicle->y -= distance;
            break;
        case 'R':
            vehicle->y += distance;
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }
}

void print_vehicle(Vehicle vehicle) {
    printf("Vehicle %s is at position (%d, %d) and moving at %d km/h.\n", vehicle.name, vehicle.x, vehicle.y, vehicle.speed);
}

int main() {
    Vehicle my_car = {"My Car", MIN_SPEED, 0, 0};
    char direction;
    int distance;

    while (1) {
        printf("\nRemote Control:\n");
        printf("Enter direction (F/B/L/R): ");
        scanf("%c", &direction);
        printf("Enter distance: ");
        scanf("%d", &distance);

        move_vehicle(&my_car, direction, distance);
        print_vehicle(my_car);
    }

    return 0;
}