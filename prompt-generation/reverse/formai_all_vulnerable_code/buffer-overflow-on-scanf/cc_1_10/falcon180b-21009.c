//Falcon-180B DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846
#define MAX_SPEED 10.0
#define MIN_SPEED 0.1
#define ACCELERATION_FACTOR 0.1
#define TURN_RATE_FACTOR 0.05
#define DISTANCE_SENSOR_RANGE 50.0

typedef struct {
    double x;
    double y;
    double theta;
    double speed;
    int direction;
} Vehicle;

void initialize_vehicle(Vehicle *vehicle) {
    vehicle->x = 0.0;
    vehicle->y = 0.0;
    vehicle->theta = 0.0;
    vehicle->speed = MIN_SPEED;
    vehicle->direction = 1;
}

void move_forward(Vehicle *vehicle) {
    double dx = cos(vehicle->theta) * vehicle->speed;
    double dy = sin(vehicle->theta) * vehicle->speed;
    vehicle->x += dx;
    vehicle->y += dy;
}

void turn_left(Vehicle *vehicle) {
    vehicle->theta -= TURN_RATE_FACTOR;
}

void turn_right(Vehicle *vehicle) {
    vehicle->theta += TURN_RATE_FACTOR;
}

void accelerate(Vehicle *vehicle) {
    if (vehicle->speed < MAX_SPEED) {
        vehicle->speed += ACCELERATION_FACTOR;
    }
}

void decelerate(Vehicle *vehicle) {
    if (vehicle->speed > MIN_SPEED) {
        vehicle->speed -= ACCELERATION_FACTOR;
    }
}

void set_direction(Vehicle *vehicle, int direction) {
    vehicle->direction = direction;
    if (direction == -1) {
        vehicle->speed = -vehicle->speed;
    }
}

void check_distance_sensor(Vehicle *vehicle, double distance) {
    if (distance < DISTANCE_SENSOR_RANGE) {
        decelerate(vehicle);
    }
}

int main() {
    Vehicle vehicle;
    initialize_vehicle(&vehicle);

    while (1) {
        printf("Enter command (f/b/l/r/a/d/s/q): ");
        char command;
        scanf("%c", &command);

        switch (command) {
        case 'f':
            move_forward(&vehicle);
            break;
        case 'b':
            move_forward(&vehicle);
            turn_left(&vehicle);
            break;
        case 'l':
            turn_left(&vehicle);
            break;
        case 'r':
            turn_right(&vehicle);
            break;
        case 'a':
            accelerate(&vehicle);
            break;
        case 'd':
            decelerate(&vehicle);
            break;
        case's':
            check_distance_sensor(&vehicle, 5.0);
            break;
        case 'q':
            exit(0);
        default:
            printf("Invalid command\n");
        }
    }

    return 0;
}