//Falcon2-11B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SPEED 10
#define MAX_ANGLE 45
#define MAX_ACCELERATION 5
#define MAX_DECELERATION 5

typedef struct {
    int x;
    int y;
    int angle;
    int speed;
    int acceleration;
    int deceleration;
} vehicle_t;

int main() {
    vehicle_t rc_car = {0, 0, 0, 0, MAX_ACCELERATION, MAX_DECELERATION};
    int input = 0;

    printf("Welcome to the Remote Control Vehicle Simulation!\n");
    printf("Enter the direction (N, S, E, W): ");
    scanf("%d", &input);

    if (input == 1) {
        rc_car.x++;
    } else if (input == 2) {
        rc_car.y--;
    } else if (input == 3) {
        rc_car.angle++;
    } else if (input == 4) {
        rc_car.angle--;
    } else if (input == 5) {
        rc_car.speed += rc_car.acceleration;
        rc_car.acceleration = 0;
    } else if (input == 6) {
        rc_car.speed -= rc_car.deceleration;
        rc_car.deceleration = 0;
    } else {
        printf("Invalid input!\n");
    }

    if (rc_car.speed < 0) {
        rc_car.speed = 0;
    } else if (rc_car.speed > MAX_SPEED) {
        rc_car.speed = MAX_SPEED;
    }

    printf("Current position: (%d, %d)\n", rc_car.x, rc_car.y);
    printf("Current angle: %d degrees\n", rc_car.angle);
    printf("Current speed: %d\n", rc_car.speed);

    return 0;
}