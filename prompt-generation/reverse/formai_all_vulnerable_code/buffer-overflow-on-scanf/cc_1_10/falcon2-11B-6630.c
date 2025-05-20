//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define LEFT_FORWARD 0
#define RIGHT_FORWARD 1
#define LEFT_BACKWARD 2
#define RIGHT_BACKWARD 3

typedef struct {
    int x;
    int y;
    int angle;
    int speed;
} Vehicle;

void move_vehicle(Vehicle* v, int direction) {
    switch(direction) {
        case LEFT_FORWARD:
            v->x -= v->speed;
            v->angle += 2;
            break;
        case RIGHT_FORWARD:
            v->x += v->speed;
            v->angle -= 2;
            break;
        case LEFT_BACKWARD:
            v->x -= v->speed;
            v->angle -= 2;
            break;
        case RIGHT_BACKWARD:
            v->x += v->speed;
            v->angle += 2;
            break;
    }
}

int main() {
    Vehicle vehicle;
    vehicle.x = 0;
    vehicle.y = 0;
    vehicle.angle = 0;
    vehicle.speed = 10;

    while(1) {
        printf("Vehicle position: (%d, %d)\n", vehicle.x, vehicle.y);
        printf("Vehicle angle: %d\n", vehicle.angle);
        printf("Vehicle speed: %d\n\n", vehicle.speed);

        int direction;
        printf("Enter direction (1-4): ");
        scanf("%d", &direction);

        move_vehicle(&vehicle, direction);
    }

    return 0;
}