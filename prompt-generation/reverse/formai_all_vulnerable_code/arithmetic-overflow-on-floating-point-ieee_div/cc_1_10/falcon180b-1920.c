//Falcon-180B DATASET v1.0 Category: Simulation of the Solar System ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define G 6.674e-11  // Gravitational constant

// Structure for a planet
typedef struct {
    char name[20];
    double mass;
    double radius;
    double x, y, z;
    double vx, vy, vz;
} Planet;

// Function to calculate gravitational force between two planets
void gravity(Planet p1, Planet p2) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);

    double force = G * p1.mass * p2.mass / (r*r);

    p1.vx -= force * dx / r;
    p1.vy -= force * dy / r;
    p1.vz -= force * dz / r;

    p2.vx += force * dx / r;
    p2.vy += force * dy / r;
    p2.vz += force * dz / r;
}

// Function to update position and velocity of a planet
void updatePlanet(Planet* planet, double dt) {
    planet->x += planet->vx * dt;
    planet->y += planet->vy * dt;
    planet->z += planet->vz * dt;
}

// Function to print a planet
void printPlanet(Planet planet) {
    printf("%.2f %.2f %.2f\n", planet.x, planet.y, planet.z);
}

// Main function
int main() {
    srand(time(NULL));

    // Initialize planets
    Planet earth = {"Earth", 5.972e24, 6371, 0, 0, 0, 0, 0, 0};
    Planet moon = {"Moon", 7.347e22, 1738, 384400, 0, 0, 0, 0, 0};
    Planet sun = {"Sun", 1.9885e30, 696342, 0, 0, 0, 0, 0, 0};

    // Add gravity between Earth and Moon
    gravity(earth, moon);

    // Simulate for 1000 seconds
    for (int i = 0; i < 1000; i++) {
        updatePlanet(&earth, 1);
        updatePlanet(&moon, 1);

        // Print current position of Earth and Moon
        printf("Earth: ");
        printPlanet(earth);
        printf("Moon: ");
        printPlanet(moon);

        // Add gravity between Earth and Sun
        gravity(earth, sun);
        gravity(moon, sun);
    }

    return 0;
}