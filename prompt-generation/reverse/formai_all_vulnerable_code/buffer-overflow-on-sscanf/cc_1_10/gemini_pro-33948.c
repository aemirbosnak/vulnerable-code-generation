//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265358979323846

typedef struct {
    double x;
    double y;
} point;

typedef struct {
    point position;
    double yaw;
    double speed;
} drone;

void print_drone(drone d) {
    printf("Drone position: (%f, %f)\n", d.position.x, d.position.y);
    printf("Drone yaw: %f\n", d.yaw);
    printf("Drone speed: %f\n", d.speed);
}

void move_drone(drone *d, double dx, double dy, double dyaw, double dspeed) {
    d->position.x += dx;
    d->position.y += dy;
    d->yaw += dyaw;
    d->speed += dspeed;
}

void rotate_drone(drone *d, double dyaw) {
    d->yaw += dyaw;
}

void accelerate_drone(drone *d, double dspeed) {
    d->speed += dspeed;
}

int main() {
    drone d;
    d.position.x = 0.0;
    d.position.y = 0.0;
    d.yaw = 0.0;
    d.speed = 0.0;

    char input[100];
    while (fgets(input, 100, stdin) != NULL) {
        char command[100];
        double value;
        sscanf(input, "%s %lf", command, &value);

        if (strcmp(command, "move") == 0) {
            move_drone(&d, value * cos(d.yaw), value * sin(d.yaw), 0.0, 0.0);
        } else if (strcmp(command, "rotate") == 0) {
            rotate_drone(&d, value);
        } else if (strcmp(command, "accelerate") == 0) {
            accelerate_drone(&d, value);
        } else if (strcmp(command, "print") == 0) {
            print_drone(d);
        } else {
            printf("Unknown command: %s\n", command);
        }
    }

    return 0;
}