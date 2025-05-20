//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

#define G 6.67430e-11 // Gravitational constant
#define TIME_STEP 0.01 // Simulation time step
#define NUM_STEPS 1000 // Number of simulation steps
#define DISTANCE_THRESHOLD 1.0 // Threshold to prevent division by zero

typedef struct {
    double mass; // Mass of the planet in kg
    double x, y; // Position in 2D space
    double vx, vy; // Velocity components
} Planet;

void printPlanetStatus(Planet* planet) {
    printf("Planet Mass: %.2e kg, Position: (%.2f, %.2f), Velocity: (%.2f, %.2f)\n",
           planet->mass, planet->x, planet->y, planet->vx, planet->vy);
}

double calculateDistance(Planet* p1, Planet* p2) {
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

void updateVelocity(Planet* p1, Planet* p2) {
    double distance = calculateDistance(p1, p2);
    if (distance < DISTANCE_THRESHOLD) return; // Prevent close encounters

    double force = (G * p1->mass * p2->mass) / (distance * distance);
    double fx = force * (p2->x - p1->x) / distance;
    double fy = force * (p2->y - p1->y) / distance;

    p1->vx += fx / p1->mass * TIME_STEP;
    p1->vy += fy / p1->mass * TIME_STEP;
    p2->vx -= fx / p2->mass * TIME_STEP;
    p2->vy -= fy / p2->mass * TIME_STEP;
}

void updatePosition(Planet* planet) {
    planet->x += planet->vx * TIME_STEP;
    planet->y += planet->vy * TIME_STEP;
}

void simulate(Planet* p1, Planet* p2) {
    for (int step = 0; step < NUM_STEPS; step++) {
        printf("Time: %.2fs\n", step * TIME_STEP);
        printPlanetStatus(p1);
        printPlanetStatus(p2);
        updateVelocity(p1, p2);
        updatePosition(p1);
        updatePosition(p2);
        sleep(1); // Pause for visibility
    }
}

int main() {
    Planet planet1 = {5.972e24, -1.0e11, 0.0, 0.0, 3.0e4}; // Earth-like planet
    Planet planet2 = {7.348e22, 0.0, 0.0, 0.0, 4.5e4}; // Moon-like planet

    printf("Simulating gravitational interaction between two planets:\n");
    simulate(&planet1, &planet2);

    return 0;
}