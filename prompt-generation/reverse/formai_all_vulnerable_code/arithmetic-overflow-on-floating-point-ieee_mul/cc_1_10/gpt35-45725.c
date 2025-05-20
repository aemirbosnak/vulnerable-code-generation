//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: interoperable
#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979323846

typedef struct {
    double x, y;
} Vector;

typedef struct {
    Vector position, velocity;
    double mass;
} Body;

void updateVelocity(Body *body, Vector acceleration, double timeStep) {
    body->velocity.x += acceleration.x * timeStep;
    body->velocity.y += acceleration.y * timeStep;
}

void updatePosition(Body *body, double timeStep) {
    body->position.x += body->velocity.x * timeStep;
    body->position.y += body->velocity.y * timeStep;
}

Vector calcGravitationalForce(Body *body1, Body *body2) {
    double distance = sqrt(pow(body1->position.x - body2->position.x, 2) + pow(body1->position.y - body2->position.y, 2));
    double forceMagnitude = (body1->mass * body2->mass) / pow(distance, 2);
    double forceX = forceMagnitude * (body2->position.x - body1->position.x) / distance;
    double forceY = forceMagnitude * (body2->position.y - body1->position.y) / distance;
    Vector force = { forceX, forceY };
    return force;
}

void simulate(Body *bodies, int numBodies, double timeStep, double simulationTime) {
    for (double time = 0; time < simulationTime; time += timeStep) {
        for (int i = 0; i < numBodies; ++i) {
            Vector acceleration = { 0, 0 };
            for (int j = 0; j < numBodies; ++j) {
                if (i == j) continue;
                Vector force = calcGravitationalForce(&bodies[i], &bodies[j]);
                acceleration.x += force.x / bodies[i].mass;
                acceleration.y += force.y / bodies[i].mass;
            }
            updateVelocity(&bodies[i], acceleration, timeStep);
        }
        for (int i = 0; i < numBodies; ++i) {
            updatePosition(&bodies[i], timeStep);
        }
    }
}

int main() {
    Body sun = { { 0, 0 }, { 0, 0 }, 1989000.0e24 };
    Body earth = { { 147e9, 0 }, { 0, 30e3 }, 5.97e24 };
    Body moon = { { 147e9 + 384400000, 0 }, { 0, 30.3e3 }, 7.342e22 };
    Body bodies[3] = { sun, earth, moon };
    simulate(bodies, 3, 86400, 365.25 * 24 * 3600);
    for (int i = 0; i < 3; ++i) {
        printf("Body %d: position = (%e, %e), velocity = (%e, %e)\n", i, bodies[i].position.x, bodies[i].position.y, bodies[i].velocity.x, bodies[i].velocity.y);
    }
    return 0;
}