//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Body;

int main() {
    int nbodies;
    printf("Enter the number of bodies: ");
    scanf("%d", &nbodies);

    Body *bodies = malloc(nbodies * sizeof(Body));

    for (int i = 0; i < nbodies; i++) {
        printf("Enter the mass, x, y, z, vx, vy, vz of body %d: ", i + 1);
        scanf("%lf %lf %lf %lf %lf %lf %lf",
              &bodies[i].mass, &bodies[i].x, &bodies[i].y, &bodies[i].z,
              &bodies[i].vx, &bodies[i].vy, &bodies[i].vz);
    }

    double dt;
    printf("Enter the time step: ");
    scanf("%lf", &dt);

    double t = 0;
    while (t < 1000) {
        for (int i = 0; i < nbodies; i++) {
            double ax = 0, ay = 0, az = 0;
            for (int j = 0; j < nbodies; j++) {
                if (i == j) continue;

                double dx = bodies[j].x - bodies[i].x;
                double dy = bodies[j].y - bodies[i].y;
                double dz = bodies[j].z - bodies[i].z;

                double r = sqrt(dx * dx + dy * dy + dz * dz);
                double f = G * bodies[i].mass * bodies[j].mass / (r * r * r);

                ax += f * dx / r;
                ay += f * dy / r;
                az += f * dz / r;
            }

            bodies[i].vx += ax * dt;
            bodies[i].vy += ay * dt;
            bodies[i].vz += az * dt;

            bodies[i].x += bodies[i].vx * dt;
            bodies[i].y += bodies[i].vy * dt;
            bodies[i].z += bodies[i].vz * dt;
        }

        t += dt;
    }

    printf("Final positions and velocities:\n");
    for (int i = 0; i < nbodies; i++) {
        printf("Body %d: (%.2lf, %.2lf, %.2lf) (%.2lf, %.2lf, %.2lf)\n",
              i + 1, bodies[i].x, bodies[i].y, bodies[i].z,
              bodies[i].vx, bodies[i].vy, bodies[i].vz);
    }

    free(bodies);
    return 0;
}