//FormAI DATASET v1.0 Category: Physics simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.673e-11 // Gravitational constant

typedef struct {
    double mass;
    double position[3];
    double velocity[3];
    double acceleration[3];
} Object;

void calculate_acceleration(Object* objects, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double r[3];
                double distance = 0;
                for (int k = 0; k < 3; k++) {
                    r[k] = objects[j].position[k] - objects[i].position[k];
                    distance += pow(r[k], 2);
                }
                distance = sqrt(distance);
                double magnitude = (G * objects[i].mass * objects[j].mass) / pow(distance, 2);
                for (int k = 0; k < 3; k++) {
                    objects[i].acceleration[k] += magnitude * r[k] / distance;
                }
            }
        }
    }
}

void update_velocity(Object* objects, int n, double time_step) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            objects[i].velocity[j] += objects[i].acceleration[j] * time_step;
            objects[i].acceleration[j] = 0;
        }
    }
}

void update_position(Object* objects, int n, double time_step) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            objects[i].position[j] += objects[i].velocity[j] * time_step;
        }
    }
}

int main() {
    int n = 3; // Number of objects

    Object objects[n];
    objects[0].mass = 5.97e24; // Mass of Earth
    objects[0].position[0] = 0;
    objects[0].position[1] = 0;
    objects[0].position[2] = 0;
    objects[0].velocity[0] = 0;
    objects[0].velocity[1] = 0;
    objects[0].velocity[2] = 0;
    objects[0].acceleration[0] = 0;
    objects[0].acceleration[1] = 0;
    objects[0].acceleration[2] = 0;

    objects[1].mass = 7.34e22; // Mass of Moon
    objects[1].position[0] = 384400000; // Distance from Earth to Moon
    objects[1].position[1] = 0;
    objects[1].position[2] = 0;
    objects[1].velocity[0] = 0;
    objects[1].velocity[1] = 1022; // Orbital speed of Moon
    objects[1].velocity[2] = 0;
    objects[1].acceleration[0] = 0;
    objects[1].acceleration[1] = 0;
    objects[1].acceleration[2] = 0;

    objects[2].mass = 1000; // Mass of small object
    objects[2].position[0] = -1000000; // Starting x position
    objects[2].position[1] = 0;
    objects[2].position[2] = 0;
    objects[2].velocity[0] = 0;
    objects[2].velocity[1] = 2000; // Starting y velocity
    objects[2].velocity[2] = 0;
    objects[2].acceleration[0] = 0;
    objects[2].acceleration[1] = 0;
    objects[2].acceleration[2] = 0;

    double time_step = 0.1; // Time step for simulation
    int num_steps = 1000; // Number of steps to simulate

    for (int i = 0; i < num_steps; i++) {
        calculate_acceleration(objects, n);
        update_velocity(objects, n, time_step);
        update_position(objects, n, time_step);

        printf("%lf,%lf,%lf\n", objects[2].position[0], objects[2].position[1], objects[2].position[2]);
    }

    return 0;
}