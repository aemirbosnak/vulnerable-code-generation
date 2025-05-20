//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_TURN 30

typedef struct {
    int x;
    int y;
    int direction;
    int speed;
} vehicle_t;

void move_vehicle(vehicle_t *vehicle) {
    if (vehicle->speed > 0) {
        if (vehicle->direction == 0) {
            vehicle->y -= vehicle->speed;
        } else {
            vehicle->x -= vehicle->speed;
        }
    }
}

void turn_vehicle(vehicle_t *vehicle, int turn) {
    if (turn > 0) {
        if (vehicle->direction == 0) {
            vehicle->direction = 1;
        } else {
            vehicle->direction = 0;
        }
    } else if (turn < 0) {
        if (vehicle->direction == 0) {
            vehicle->direction = -1;
        } else {
            vehicle->direction = 0;
        }
    }
}

int main() {
    vehicle_t vehicle;
    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.direction = 0;
    vehicle.speed = 0;

    int choice;
    while (1) {
        printf("Enter your choice:\n");
        printf("1. Move forward\n");
        printf("2. Turn left\n");
        printf("3. Turn right\n");
        printf("4. Stop\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (vehicle.speed < MAX_SPEED) {
                vehicle.speed++;
            }
            break;
        case 2:
            turn_vehicle(&vehicle, -MAX_TURN);
            break;
        case 3:
            turn_vehicle(&vehicle, MAX_TURN);
            break;
        case 4:
            if (vehicle.speed > 0) {
                vehicle.speed = 0;
            }
            break;
        default:
            printf("Invalid choice\n");
        }

        move_vehicle(&vehicle);
        printf("Current position: (%d, %d) Speed: %d Direction: %d\n", vehicle.x, vehicle.y, vehicle.speed, vehicle.direction);
        usleep(100000);
    }

    return 0;
}