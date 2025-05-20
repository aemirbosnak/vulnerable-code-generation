//Falcon-180B DATASET v1.0 Category: Physics simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant
#define PI 3.14159265358979323846 // Pi
#define STEP_SIZE 0.01 // Step size for numerical integration

// Function to calculate the force between two particles
double force(double r, double m1, double m2) {
    double F = G * m1 * m2 / (r * r);
    return F;
}

// Function to calculate the acceleration due to gravity
double acceleration(double r, double m1, double m2) {
    double F = force(r, m1, m2);
    double a = F / m1;
    return a;
}

// Function to update the position and velocity of a particle
void update_particle(double *pos, double *vel, double acc, double dt) {
    double new_pos = *pos + *vel * dt + 0.5 * acc * dt * dt;
    *pos = new_pos;
    *vel += acc * dt;
}

// Function to integrate the motion of a particle
void integrate_motion(double *pos, double *vel, double m1, double m2, double dt) {
    double r = sqrt(pow(*pos - m2, 2.0));
    double F = force(r, m1, m2);
    double a = acceleration(r, m1, m2);
    update_particle(pos, vel, a, dt);
}

int main() {
    double m1 = 1.0; // Mass of particle 1
    double m2 = 10.0; // Mass of particle 2
    double dt = STEP_SIZE; // Time step for numerical integration

    double pos1 = 0.0; // Initial position of particle 1
    double vel1 = 0.0; // Initial velocity of particle 1

    double pos2 = 1.0; // Initial position of particle 2
    double vel2 = 0.0; // Initial velocity of particle 2

    double time = 0.0; // Initial time

    while (time < 100.0) {
        integrate_motion(&pos1, &vel1, m1, m2, dt);
        integrate_motion(&pos2, &vel2, m2, m1, dt);

        printf("Time: %f\n", time);
        printf("Position of particle 1: %f\n", pos1);
        printf("Position of particle 2: %f\n", pos2);
        printf("Velocity of particle 1: %f\n", vel1);
        printf("Velocity of particle 2: %f\n", vel2);

        time += dt;
    }

    return 0;
}