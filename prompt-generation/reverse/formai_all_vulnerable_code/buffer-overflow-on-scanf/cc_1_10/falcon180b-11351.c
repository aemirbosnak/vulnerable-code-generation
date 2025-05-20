//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point position;
    double speed;
    double angle;
} Vehicle;

void move_vehicle(Vehicle* vehicle, double dt) {
    double dx = vehicle->speed * cos(vehicle->angle) * dt;
    double dy = vehicle->speed * sin(vehicle->angle) * dt;
    vehicle->position.x += dx;
    vehicle->position.y += dy;
}

void turn_vehicle(Vehicle* vehicle, double angle_delta, double dt) {
    vehicle->angle += angle_delta * dt;
}

int main() {
    Vehicle vehicle = {
       .position = {0, 0},
       .speed = 1.0,
       .angle = 0.0
    };

    double dt = 0.1;
    int running = 1;

    while (running) {
        system("clear");
        printf("Current position: (%lf, %lf)\n", vehicle.position.x, vehicle.position.y);
        printf("Current speed: %lf\n", vehicle.speed);
        printf("Current angle: %lf\n", vehicle.angle);

        char input[100];
        scanf("%s", input);

        if (strcmp(input, "up") == 0) {
            vehicle.speed += 0.1;
        } else if (strcmp(input, "down") == 0) {
            vehicle.speed -= 0.1;
        } else if (strcmp(input, "left") == 0) {
            turn_vehicle(&vehicle, -0.1, dt);
        } else if (strcmp(input, "right") == 0) {
            turn_vehicle(&vehicle, 0.1, dt);
        } else if (strcmp(input, "quit") == 0) {
            running = 0;
        }

        move_vehicle(&vehicle, dt);

        usleep(100000);
    }

    return 0;
}