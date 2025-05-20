//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: real-life
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define G 6.67430e-11 // Universal gravitational constant

typedef struct {
    double mass; // mass of the celestial body (in kg)
    double x;    // x position (in meters)
    double y;    // y position (in meters)
    double vx;   // velocity in x direction (in m/s)
    double vy;   // velocity in y direction (in m/s)
} CelestialBody;

void initializeBody(CelestialBody *body, double mass, double x, double y, double vx, double vy) {
    body->mass = mass;
    body->x = x;
    body->y = y;
    body->vx = vx;
    body->vy = vy;
}

double calculateDistance(CelestialBody *body1, CelestialBody *body2) {
    return sqrt(pow(body2->x - body1->x, 2) + pow(body2->y - body1->y, 2));
}

void updateVelocity(CelestialBody *body, CelestialBody *otherBody, double timeStep) {
    double distance = calculateDistance(body, otherBody);
    if (distance == 0) return; // avoid division by zero

    double force = G * (body->mass * otherBody->mass) / (distance * distance);
    double fx = force * (otherBody->x - body->x) / distance; // Force in x direction
    double fy = force * (otherBody->y - body->y) / distance; // Force in y direction

    double ax = fx / body->mass; // Acceleration in x direction
    double ay = fy / body->mass; // Acceleration in y direction

    body->vx += ax * timeStep; // Update velocity in x
    body->vy += ay * timeStep; // Update velocity in y
}

void updatePosition(CelestialBody *body, double timeStep) {
    body->x += body->vx * timeStep; // Update position in x
    body->y += body->vy * timeStep; // Update position in y
}

void printBodyState(CelestialBody *body, double time) {
    printf("Time: %.2f s | ", time);
    printf("Mass: %.2e kg | ", body->mass);
    printf("Position: (%.2f m, %.2f m) | ", body->x, body->y);
    printf("Velocity: (%.2f m/s, %.2f m/s)\n", body->vx, body->vy);
}

int main() {
    const double timeStep = 1.0; // in seconds
    const double totalTime = 100.0; // total simulation time in seconds
    const int numSteps = (int)(totalTime / timeStep);

    CelestialBody sun;
    CelestialBody planet;

    initializeBody(&sun, 1.989e30, 0.0, 0.0, 0.0, 0.0); // Sun
    initializeBody(&planet, 5.972e24, 1.496e11, 0.0, 0.0, 29783.0); // Earth

    printf("Initial States:\n");
    printBodyState(&sun, 0);
    printBodyState(&planet, 0);
    
    for (int step = 1; step <= numSteps; ++step) {
        double currentTime = step * timeStep;

        updateVelocity(&planet, &sun, timeStep);
        updatePosition(&sun, timeStep); // Sun remains static in this model
        updatePosition(&planet, timeStep);

        printBodyState(&sun, currentTime);
        printBodyState(&planet, currentTime);
    }

    return 0;
}