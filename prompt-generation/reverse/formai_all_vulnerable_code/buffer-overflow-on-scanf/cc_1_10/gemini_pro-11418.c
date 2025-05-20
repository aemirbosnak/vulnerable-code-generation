//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define EPS 1e-6
#define MAX_BODIES 100

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Body;

int main() {
    int i, j, n;
    double dt;
    Body bodies[MAX_BODIES];

    printf("Enter the number of bodies: ");
    scanf("%d", &n);

    printf("Enter the masses and positions of the bodies:\n");
    for (i = 0; i < n; i++) {
        printf("Body %d:\n", i);
        printf("Mass: ");
        scanf("%lf", &bodies[i].mass);
        printf("Position (x, y, z): ");
        scanf("%lf %lf %lf", &bodies[i].x, &bodies[i].y, &bodies[i].z);
        printf("Velocity (vx, vy, vz): ");
        scanf("%lf %lf %lf", &bodies[i].vx, &bodies[i].vy, &bodies[i].vz);
    }

    printf("Enter the time step: ");
    scanf("%lf", &dt);

    // Main simulation loop
    while (1) {
        // Calculate the forces on each body
        for (i = 0; i < n; i++) {
            bodies[i].vx = 0.0;
            bodies[i].vy = 0.0;
            bodies[i].vz = 0.0;
            for (j = 0; j < n; j++) {
                if (i != j) {
                    double dx = bodies[j].x - bodies[i].x;
                    double dy = bodies[j].y - bodies[i].y;
                    double dz = bodies[j].z - bodies[i].z;
                    double r = sqrt(dx * dx + dy * dy + dz * dz);
                    double f = G * bodies[i].mass * bodies[j].mass / (r * r * r);
                    bodies[i].vx += f * dx / r;
                    bodies[i].vy += f * dy / r;
                    bodies[i].vz += f * dz / r;
                }
            }
        }

        // Update the positions and velocities of the bodies
        for (i = 0; i < n; i++) {
            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
            bodies[i].z += bodies[i].vz * dt;
        }

        // Check if any bodies are colliding
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dz = bodies[j].z - bodies[i].z;
                double r = sqrt(dx * dx + dy * dy + dz * dz);
                if (r < EPS) {
                    // Collision detected!
                    printf("Collision detected between bodies %d and %d!\n", i, j);
                    exit(0);
                }
            }
        }
    }

    return 0;
}