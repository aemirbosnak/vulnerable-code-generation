//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Vehicle {
    int x;
    int y;
    int heading;
    int speed;
};

void move_vehicle(struct Vehicle* vehicle, int dx, int dy) {
    vehicle->x += dx;
    vehicle->y += dy;
    vehicle->heading += (dx + dy) / 2;
    vehicle->speed = (dx - dy) / 2;
}

void print_vehicle(struct Vehicle* vehicle) {
    printf("X: %d, Y: %d, Heading: %d, Speed: %d\n", vehicle->x, vehicle->y, vehicle->heading, vehicle->speed);
}

int main() {
    struct Vehicle rc_vehicle;
    rc_vehicle.x = 0;
    rc_vehicle.y = 0;
    rc_vehicle.heading = 0;
    rc_vehicle.speed = 0;

    printf("Initial position: (%d, %d), Heading: %d, Speed: %d\n", rc_vehicle.x, rc_vehicle.y, rc_vehicle.heading, rc_vehicle.speed);

    int input_direction = 0;
    int input_speed = 0;

    while (true) {
        printf("Enter direction (N, E, S, W) and speed (1-5): ");
        scanf("%d %d", &input_direction, &input_speed);

        if (input_direction == 0 && input_speed == 0) {
            break;
        }

        if (input_direction == 'N') {
            move_vehicle(&rc_vehicle, 0, 1);
        } else if (input_direction == 'E') {
            move_vehicle(&rc_vehicle, 1, 0);
        } else if (input_direction == 'S') {
            move_vehicle(&rc_vehicle, 0, -1);
        } else if (input_direction == 'W') {
            move_vehicle(&rc_vehicle, -1, 0);
        }

        rc_vehicle.speed = input_speed;

        printf("New position: (%d, %d), Heading: %d, Speed: %d\n", rc_vehicle.x, rc_vehicle.y, rc_vehicle.heading, rc_vehicle.speed);
    }

    return 0;
}