//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

// Define the mass and radius of the Earth
#define EARTH_MASS 5.972e24 // kg
#define EARTH_RADIUS 6.371e6 // m

// Define the gravitational constant
#define G 6.674e-11 // m^3 kg^-1 s^-2

// Define the timestep
#define DT 1 // s

// Create a structure to represent a celestial body
typedef struct CelestialBody {
    double mass; // kg
    double radius; // m
    double x; // m
    double y; // m
    double z; // m
    double vx; // m/s
    double vy; // m/s
    double vz; // m/s
} CelestialBody;

// Create a function to calculate the force between two celestial bodies
void calculateForce(CelestialBody *body1, CelestialBody *body2) {
    // Calculate the distance between the two bodies
    double dx = body1->x - body2->x;
    double dy = body1->y - body2->y;
    double dz = body1->z - body2->z;
    double distance = sqrt(dx * dx + dy * dy + dz * dz);

    // Calculate the force between the two bodies
    double force = G * body1->mass * body2->mass / (distance * distance);

    // Calculate the direction of the force
    double fx = force * dx / distance;
    double fy = force * dy / distance;
    double fz = force * dz / distance;

    // Apply the force to the first body
    body1->vx += fx / body1->mass * DT;
    body1->vy += fy / body1->mass * DT;
    body1->vz += fz / body1->mass * DT;

    // Apply the force to the second body
    body2->vx -= fx / body2->mass * DT;
    body2->vy -= fy / body2->mass * DT;
    body2->vz -= fz / body2->mass * DT;
}

// Create a function to update the position of a celestial body
void updatePosition(CelestialBody *body) {
    // Update the position of the body
    body->x += body->vx * DT;
    body->y += body->vy * DT;
    body->z += body->vz * DT;
}

// Create a function to simulate the solar system
void simulateSolarSystem() {
    // Create an array of celestial bodies
    CelestialBody bodies[] = {
        // The Sun
        {
            1.989e30, // kg
            6.957e8, // m
            0, // m
            0, // m
            0, // m
            0, // m/s
            0, // m/s
            0, // m/s
        },
        // The Earth
        {
            EARTH_MASS, // kg
            EARTH_RADIUS, // m
            1.5e11, // m
            0, // m
            0, // m
            0, // m/s
            30e3, // m/s
            0, // m/s
        },
        // The Moon
        {
            7.348e22, // kg
            1.737e6, // m
            1.5e11 + 3.844e8, // m
            0, // m
            0, // m
            0, // m/s
            0, // m/s
            1.2e3, // m/s
        },
    };

    // Simulate the solar system for 100 years
    for (int i = 0; i < 100 * 365 * 24 * 60 * 60 / DT; i++) {
        // Calculate the force between each pair of celestial bodies
        for (int j = 0; j < sizeof(bodies) / sizeof(CelestialBody); j++) {
            for (int k = j + 1; k < sizeof(bodies) / sizeof(CelestialBody); k++) {
                calculateForce(&bodies[j], &bodies[k]);
            }
        }

        // Update the position of each celestial body
        for (int j = 0; j < sizeof(bodies) / sizeof(CelestialBody); j++) {
            updatePosition(&bodies[j]);
        }

        // Print the position of each celestial body
        for (int j = 0; j < sizeof(bodies) / sizeof(CelestialBody); j++) {
            printf("Body %d: (%f, %f, %f)\n", j, bodies[j].x, bodies[j].y, bodies[j].z);
        }
    }
}

int main() {
    simulateSolarSystem();
    return 0;
}