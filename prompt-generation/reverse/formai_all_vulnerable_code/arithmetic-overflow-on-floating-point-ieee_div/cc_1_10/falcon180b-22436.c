//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define G 6.674e-11

// Define the structure of a planet
typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Planet;

// Function to calculate the gravitational force between two planets
void gravity(Planet* p1, Planet* p2) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p1->mass * p2->mass / (r*r);
    p1->vx -= dx * f;
    p1->vy -= dy * f;
    p1->vz -= dz * f;
    p2->vx += dx * f;
    p2->vy += dy * f;
    p2->vz += dz * f;
}

// Function to update the position and velocity of a planet
void update_planet(Planet* p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    srand(time(NULL));

    // Initialize the planets
    Planet earth = {6.0e24, 0, 0, 0, 0, 0, 0};
    Planet moon = {7.3e22, 384400, 0, 0, 0, 0, 0};
    Planet sun = {1.0e30, 0, 0, 0, 0, 0, 0};

    // Set the initial velocities of the planets
    earth.vx = 29.8e3;
    earth.vy = 0;
    earth.vz = 0;
    moon.vx = 1022;
    moon.vy = 0;
    moon.vz = 0;

    // Simulate the gravity between the planets
    for (int i = 0; i < 10000; i++) {
        gravity(&earth, &sun);
        gravity(&moon, &earth);
        gravity(&moon, &sun);
        update_planet(&earth, 1);
        update_planet(&moon, 1);
    }

    // Print the final positions of the planets
    printf("Earth: (%f, %f, %f)\n", earth.x, earth.y, earth.z);
    printf("Moon: (%f, %f, %f)\n", moon.x, moon.y, moon.z);

    return 0;
}