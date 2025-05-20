//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67 // Gravitational force constant

typedef struct {
    double x, y; // Coordinates of the planet
    double vx, vy; // Velocity of the planet
    double mass; // Mass of the planet
} Planet;

void update_velocities(Planet *p1, Planet *p2, double dt) {
    // Calculate the gravitational force between the two planets
    double distance = sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
    double force = (G * p1->mass * p2->mass) / pow(distance, 2);
    double acceleration1 = force / p1->mass;
    double acceleration2 = force / p2->mass;

    // Update the velocities of the two planets
    p1->vx += acceleration1 * (p2->x - p1->x) / distance * dt;
    p1->vy += acceleration1 * (p2->y - p1->y) / distance * dt;
    p2->vx -= acceleration2 * (p2->x - p1->x) / distance * dt;
    p2->vy -= acceleration2 * (p2->y - p1->y) / distance * dt;
}

void update_positions(Planet *p, double dt) {
    // Update the position of the planet based on its velocity
    p->x += p->vx * dt;
    p->y += p->vy * dt;
}

int main(void) {
    // Define the planets and their initial conditions
    Planet earth = {0, 0, 0, 0, 5.97e24}; // mass of earth is 5.97 x 10^24 kg
    Planet moon = {385000000, 0, 0, 1022, 7.34e22}; // mass of moon is 7.34 x 10^22 kg
    double dt = 86400; // time step of one day

    // Simulate the movement of the planets for one year (365 days)
    for (int i = 0; i < 365; i++) {
        update_velocities(&earth, &moon, dt);
        update_positions(&earth, dt);
        update_positions(&moon, dt);

        // Print out the position of the moon at the end of each day
        if (i % 10 == 0) { // Print only every 10th day for performance reasons
            printf("Day %d: x = %fm, y = %fm\n", i, moon.x, moon.y);
        }
    }

    return 0;
}