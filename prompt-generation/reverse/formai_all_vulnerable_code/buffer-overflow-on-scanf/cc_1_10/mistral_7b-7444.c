//MISTRAL-7B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define PI 3.14159265358979323846

typedef struct {
    double x, y, theta, velocity, max_velocity;
} vehicle;

void update_vehicle(vehicle *vehicle, char input) {
    switch(input) {
        case 'f':
            vehicle->velocity += vehicle->max_velocity * 0.1;
            break;
        case 'b':
            vehicle->velocity -= vehicle->max_velocity * 0.1;
            break;
        case 'l':
            vehicle->theta -= PI / 180.0;
            break;
        case 'r':
            vehicle->theta += PI / 180.0;
            break;
        case 's':
            vehicle->velocity = 0.0;
            break;
        default:
            break;
    }

    // Update position based on velocity and angle
    double dx = vehicle->velocity * cos(vehicle->theta);
    double dy = vehicle->velocity * sin(vehicle->theta);
    vehicle->x += dx;
    vehicle->y += dy;
}

int main() {
    vehicle car = {0.0, 0.0, 0.0, 5.0, 10.0};
    char input;

    while(1) {
        printf("Enter command (f/b/l/r/s): ");
        scanf(" %c", &input);

        update_vehicle(&car, input);

        printf("Position: (%lf, %lf)\n", car.x, car.y);
        printf("Angle: %lf degrees\n", car.theta * 180.0 / PI);
        printf("Velocity: %lf\n", car.velocity);
        printf("\n");
    }

    return 0;
}