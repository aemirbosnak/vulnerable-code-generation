//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x, y, z;
    double vx, vy, vz;
    double m;
} Body;

const double G = 6.674e-11; // Gravitational constant

Body* createBody(double x, double y, double z, double vx, double vy, double vz, double m) {
    Body* body = malloc(sizeof(Body));
    body->x = x;
    body->y = y;
    body->z = z;
    body->vx = vx;
    body->vy = vy;
    body->vz = vz;
    body->m = m;
    return body;
}

void destroyBody(Body* body) {
    free(body);
}

void updateBody(Body* body, double dt) {
    body->x += body->vx * dt;
    body->y += body->vy * dt;
    body->z += body->vz * dt;
}

void calculateGravitationalForce(Body* body1, Body* body2) {
    double dx = body2->x - body1->x;
    double dy = body2->y - body1->y;
    double dz = body2->z - body1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * body1->m * body2->m / (r*r);
    body1->vx += f * dx / r;
    body1->vy += f * dy / r;
    body1->vz += f * dz / r;
    body2->vx -= f * dx / r;
    body2->vy -= f * dy / r;
    body2->vz -= f * dz / r;
}

int main() {
    int nbodies = 10;
    double dt = 0.01;
    double t = 0.0;
    Body* bodies[nbodies];

    // Create bodies
    bodies[0] = createBody(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    bodies[1] = createBody(1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    bodies[2] = createBody(0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    bodies[3] = createBody(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0);
    bodies[4] = createBody(2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    bodies[5] = createBody(0.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    bodies[6] = createBody(0.0, 0.0, 2.0, 0.0, 0.0, 0.0, 1.0);
    bodies[7] = createBody(3.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    bodies[8] = createBody(0.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0);
    bodies[9] = createBody(0.0, 0.0, 3.0, 0.0, 0.0, 0.0, 1.0);

    // Simulation loop
    while (t < 10.0) {
        // Update bodies
        for (int i = 0; i < nbodies; i++) {
            updateBody(bodies[i], dt);
        }

        // Calculate gravitational forces
        for (int i = 0; i < nbodies; i++) {
            for (int j = i + 1; j < nbodies; j++) {
                calculateGravitationalForce(bodies[i], bodies[j]);
            }
        }

        // Print bodies
        for (int i = 0; i < nbodies; i++) {
            printf("Body %d: (%.2f, %.2f, %.2f)\n", i, bodies[i]->x, bodies[i]->y, bodies[i]->z);
        }

        t += dt;
    }

    // Destroy bodies
    for (int i = 0; i < nbodies; i++) {
        destroyBody(bodies[i]);
    }

    return 0;
}