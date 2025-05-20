//GPT-4o-mini DATASET v1.0 Category: Planet Gravity Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define GRAVITY_CONSTANT 6.67430e-11  // m^3 kg^-1 s^-2
#define PI 3.14159265
#define MAX_BODIES 100

// Struct to represent celestial bodies
typedef struct {
    char name[30];
    double mass; // in kg
    double position[2]; // x, y coordinates in meters
    double velocity[2]; // vx, vy coordinates in meters/sec
} CelestialBody;

// Function prototypes
void initializeBodies(CelestialBody bodies[], int numBodies);
void calculateForces(CelestialBody bodies[], int numBodies);
void updatePositions(CelestialBody bodies[], int numBodies, double timeStep);
void printBodyStates(const CelestialBody bodies[], int numBodies);
double calculateDistance(CelestialBody a, CelestialBody b);
void configureSim(int *numBodies, double *timeStep, int *iterations);

int main() {
    CelestialBody bodies[MAX_BODIES];
    int numBodies;
    double timeStep;
    int iterations;

    // Configuration step
    configureSim(&numBodies, &timeStep, &iterations);

    // Initialize celestial bodies
    initializeBodies(bodies, numBodies);

    // Simulation loop
    for (int i = 0; i < iterations; i++) {
        printf("Iteration %d:\n", i + 1);
        calculateForces(bodies, numBodies);
        updatePositions(bodies, numBodies, timeStep);
        printBodyStates(bodies, numBodies);
        printf("\n");
    }

    return 0;
}

// Function to configure simulation parameters
void configureSim(int *numBodies, double *timeStep, int *iterations) {
    printf("Enter the number of celestial bodies (up to %d): ", MAX_BODIES);
    scanf("%d", numBodies);
    if (*numBodies > MAX_BODIES || *numBodies < 1) {
        printf("Invalid number of bodies. Set to 1.\n");
        *numBodies = 1;
    }

    printf("Enter simulation time step (in seconds): ");
    scanf("%lf", timeStep);

    printf("Enter number of iterations to simulate: ");
    scanf("%d", iterations);
}

// Function to initialize celestial bodies
void initializeBodies(CelestialBody bodies[], int numBodies) {
    for (int i = 0; i < numBodies; i++) {
        printf("Enter name, mass (kg), position (x y in meters), and velocity (vx vy in m/s) for body %d:\n", i + 1);
        scanf("%s %lf %lf %lf %lf %lf", bodies[i].name, &bodies[i].mass, 
              &bodies[i].position[0], &bodies[i].position[1], 
              &bodies[i].velocity[0], &bodies[i].velocity[1]);
    }
}

// Function to calculate gravitational forces on each body
void calculateForces(CelestialBody bodies[], int numBodies) {
    for (int i = 0; i < numBodies; i++) {
        double totalForce[2] = {0, 0};
        for (int j = 0; j < numBodies; j++) {
            if (i != j) {
                double distance = calculateDistance(bodies[i], bodies[j]);
                double forceMagnitude = (GRAVITY_CONSTANT * bodies[i].mass * bodies[j].mass) / (distance * distance);
                double direction[2] = {(bodies[j].position[0] - bodies[i].position[0]) / distance,
                                       (bodies[j].position[1] - bodies[i].position[1]) / distance};
                totalForce[0] += forceMagnitude * direction[0];
                totalForce[1] += forceMagnitude * direction[1];
            }
        }
        // Update velocity based on the calculated total force
        bodies[i].velocity[0] += totalForce[0] / bodies[i].mass;
        bodies[i].velocity[1] += totalForce[1] / bodies[i].mass;
    }
}

// Function to update positions of each body based on velocity and time step
void updatePositions(CelestialBody bodies[], int numBodies, double timeStep) {
    for (int i = 0; i < numBodies; i++) {
        bodies[i].position[0] += bodies[i].velocity[0] * timeStep;
        bodies[i].position[1] += bodies[i].velocity[1] * timeStep;
    }
}

// Function to print the current state of each body
void printBodyStates(const CelestialBody bodies[], int numBodies) {
    for (int i = 0; i < numBodies; i++) {
        printf("Body: %s, Mass: %.2e kg, Position: (%.2f, %.2f) m, Velocity: (%.2f, %.2f) m/s\n", 
                bodies[i].name, bodies[i].mass, 
                bodies[i].position[0], bodies[i].position[1], 
                bodies[i].velocity[0], bodies[i].velocity[1]);
    }
}

// Function to calculate the distance between two celestial bodies
double calculateDistance(CelestialBody a, CelestialBody b) {
    return sqrt(pow(b.position[0] - a.position[0], 2) + pow(b.position[1] - a.position[1], 2));
}