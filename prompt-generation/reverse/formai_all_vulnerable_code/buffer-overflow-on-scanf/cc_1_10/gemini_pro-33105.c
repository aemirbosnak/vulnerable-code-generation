//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant

typedef struct {
    double mass; // Mass of the body
    double x, y, z; // Position of the body
    double vx, vy, vz; // Velocity of the body
} Body;

int main() {
    int num_bodies;
    printf("Enter the number of bodies: ");
    scanf("%d", &num_bodies);

    Body *bodies = malloc(num_bodies * sizeof(Body));

    // Initialize the bodies
    for (int i = 0; i < num_bodies; i++) {
        printf("Enter the mass of body %d (kg): ", i + 1);
        scanf("%lf", &bodies[i].mass);

        printf("Enter the x, y, and z coordinates of body %d (m): ", i + 1);
        scanf("%lf %lf %lf", &bodies[i].x, &bodies[i].y, &bodies[i].z);

        printf("Enter the vx, vy, and vz components of velocity of body %d (m/s): ", i + 1);
        scanf("%lf %lf %lf", &bodies[i].vx, &bodies[i].vy, &bodies[i].vz);
    }

    // Simulate the motion of the bodies
    double dt = 0.001; // Time step
    for (int t = 0; t < 10000; t++) { // Time loop
        // Calculate the gravitational force on each body
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].vx = 0;
            bodies[i].vy = 0;
            bodies[i].vz = 0;

            for (int j = 0; j < num_bodies; j++) {
                if (i == j) continue;

                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dz = bodies[j].z - bodies[i].z;

                double r = sqrt(dx * dx + dy * dy + dz * dz);

                double force = G * bodies[i].mass * bodies[j].mass / (r * r);

                bodies[i].vx += force * dx / r;
                bodies[i].vy += force * dy / r;
                bodies[i].vz += force * dz / r;
            }
        }

        // Update the position and velocity of each body
        for (int i = 0; i < num_bodies; i++) {
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
            bodies[i].z += bodies[i].vz * dt;
        }
    }

    // Print the final positions of the bodies
    for (int i = 0; i < num_bodies; i++) {
        printf("Position of body %d (m): %.2f, %.2f, %.2f\n", i + 1, bodies[i].x, bodies[i].y, bodies[i].z);
    }

    return 0;
}