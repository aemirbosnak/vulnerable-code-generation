//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: imaginative
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <unistd.h>

#define G 6.673e-11 // Gravitational constant (m^3 kg^-1 s^-2)
#define M_sun 1.989e30 // Mass of the sun (kg)

typedef struct body {
    double mass, radius;
    double position[3]; // x, y, and z coordinates
    double velocity[3]; // x, y, and z components of velocity
    double acceleration[3]; // x, y, and z components of acceleration
    char* name;
} Body;

double distance(Body a, Body b) {
    double x = a.position[0] - b.position[0];
    double y = a.position[1] - b.position[1];
    double z = a.position[2] - b.position[2];
    return sqrt(x*x + y*y + z*z);
}

double gravitational_force(Body a, Body b) {
    return G * a.mass * b.mass / pow(distance(a, b), 2.0);
}

double* acceleration(Body a, Body b) {
    double direction[3];
    double r = distance(a, b);
    direction[0] = (b.position[0] - a.position[0]) / r; // x-component of unit vector
    direction[1] = (b.position[1] - a.position[1]) / r; // y-component of unit vector
    direction[2] = (b.position[2] - a.position[2]) / r; // z-component of unit vector
    
    double force = gravitational_force(a, b);
    double acceleration[3];
    acceleration[0] = force / a.mass * direction[0];
    acceleration[1] = force / a.mass * direction[1];
    acceleration[2] = force / a.mass * direction[2];
    
    return acceleration;
}

void update_acceleration(Body* bodies, int num_bodies) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].acceleration[0] = 0;
        bodies[i].acceleration[1] = 0;
        bodies[i].acceleration[2] = 0;
        for (int j = 0; j < num_bodies; j++) {
            if (i != j) {
                double* acc = acceleration(bodies[i], bodies[j]);
                bodies[i].acceleration[0] += acc[0];
                bodies[i].acceleration[1] += acc[1];
                bodies[i].acceleration[2] += acc[2];
            }
        }
    }
}

void update_velocity(Body* bodies, int num_bodies, double dt) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].velocity[0] += bodies[i].acceleration[0] * dt;
        bodies[i].velocity[1] += bodies[i].acceleration[1] * dt;
        bodies[i].velocity[2] += bodies[i].acceleration[2] * dt;
    }
}

void update_position(Body* bodies, int num_bodies, double dt) {
    for (int i = 0; i < num_bodies; i++) {
        bodies[i].position[0] += bodies[i].velocity[0] * dt;
        bodies[i].position[1] += bodies[i].velocity[1] * dt;
        bodies[i].position[2] += bodies[i].velocity[2] * dt;
    }
}

void simulate(Body* bodies, int num_bodies, double dt, int time_steps) {
    for (int i = 0; i < time_steps; i++) {
        update_acceleration(bodies, num_bodies);
        update_velocity(bodies, num_bodies, dt);
        update_position(bodies, num_bodies, dt);
        printf("Step %d:\n", i);
        for (int j = 0; j < num_bodies; j++) {
            printf("%s position: (%.3e, %.3e, %.3e)\n", bodies[j].name, bodies[j].position[0], bodies[j].position[1], bodies[j].position[2]);
        }
        printf("\n");
    }
}

int main(void) {
    Body sun = {M_sun, 696000000, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, "Sun"};
    Body earth = {5.972e24, 6400000, {147000000000, 0, 0}, {0, 30000, 0}, {0, 0, 0}, "Earth"};
    Body moon = {7.342e22, 1738000, {147000000000 + 384400000, 0, 0}, {0, 3070, 0}, {0, 0, 0}, "Moon"};
    Body mercury = {3.285e23, 2439000, {57910000000, 0, 0}, {0, 47360, 0}, {0, 0, 0}, "Mercury"};
    Body venus = {4.867e24, 6052000, {108200000000, 0, 0}, {0, 35020, 0}, {0, 0, 0}, "Venus"};
    Body mars = {6.39e23, 3397000, {-227900000000, 0, 0}, {0, -24000, 0}, {0, 0, 0}, "Mars"};
    
    Body bodies[6] = {sun, earth, moon, mercury, venus, mars};
    
    simulate(bodies, 6, 3600*24, 365);

    return 0;
}