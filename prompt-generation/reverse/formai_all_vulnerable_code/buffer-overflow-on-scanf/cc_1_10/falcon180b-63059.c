//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 0
#define TURN_RADIUS 20
#define MOVE_DISTANCE 10

typedef struct {
    int x, y;
} Point;

void draw_vehicle(Point vehicle) {
    printf("Vehicle is at (%d, %d)\n", vehicle.x, vehicle.y);
}

void move_vehicle(Point* vehicle, int speed, int direction) {
    int dx = 0;
    int dy = 0;

    if (direction == 0) {
        dy = -speed;
    } else if (direction == 1) {
        dx = speed;
    } else if (direction == 2) {
        dy = speed;
    } else if (direction == 3) {
        dx = -speed;
    }

    vehicle->x += dx;
    vehicle->y += dy;
}

void turn_vehicle(Point* vehicle, int direction) {
    int dx = 0;
    int dy = 0;

    if (direction == 0) {
        dy = -TURN_RADIUS;
    } else if (direction == 1) {
        dx = TURN_RADIUS;
    } else if (direction == 2) {
        dy = TURN_RADIUS;
    } else if (direction == 3) {
        dx = -TURN_RADIUS;
    }

    vehicle->x += dx;
    vehicle->y += dy;
}

int main() {
    Point vehicle = {0, 0};
    int speed = 0;
    int direction = 0;
    int choice;

    printf("Remote Control Vehicle Simulation\n");
    printf("Press 1 to move forward\n");
    printf("Press 2 to move backward\n");
    printf("Press 3 to turn left\n");
    printf("Press 4 to turn right\n");
    printf("Press 5 to stop\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                speed = MAX_SPEED;
                direction = 0;
                break;
            case 2:
                speed = -MAX_SPEED;
                direction = 0;
                break;
            case 3:
                speed = 0;
                direction = 1;
                break;
            case 4:
                speed = 0;
                direction = 3;
                break;
            case 5:
                speed = 0;
                direction = 0;
                break;
            default:
                printf("Invalid choice\n");
        }

        move_vehicle(&vehicle, speed, direction);
        draw_vehicle(vehicle);
    }

    return 0;
}