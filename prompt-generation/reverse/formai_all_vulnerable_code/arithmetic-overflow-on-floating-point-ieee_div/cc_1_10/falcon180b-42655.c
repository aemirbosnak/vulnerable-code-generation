//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265359
#define G 6.67430e-11

// Define the planet structure
struct planet {
    double x, y, z, vx, vy, vz, ax, ay, az;
    double m, r;
};

// Initialize the planet parameters
void init_planet(struct planet *p, double m, double r, double vx, double vy, double vz) {
    p->m = m;
    p->r = r;
    p->x = 0;
    p->y = 0;
    p->z = 0;
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
    p->ax = 0;
    p->ay = 0;
    p->az = 0;
}

// Calculate the gravitational force between two planets
void calc_gravity(struct planet *p1, struct planet *p2, double dt) {
    double dx = p2->x - p1->x;
    double dy = p2->y - p1->y;
    double dz = p2->z - p1->z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p1->m * p2->m / (r*r);
    p1->ax -= dx * f / r;
    p1->ay -= dy * f / r;
    p1->az -= dz * f / r;
    p2->ax += dx * f / r;
    p2->ay += dy * f / r;
    p2->az += dz * f / r;
}

// Update the planet positions and velocities
void update_planet(struct planet *p, double dt) {
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
}

// Main function
int main() {
    srand(time(NULL));

    // Initialize the planets
    struct planet earth, moon;
    init_planet(&earth, 5.972e24, 6378.14e3, 0, 0, 0);
    init_planet(&moon, 7.347e22, 1737.1e3, 384400, 0, 0);

    // Set the time step
    double dt = 0.01;

    // Simulate the gravity
    while (1) {
        calc_gravity(&earth, &moon, dt);
        update_planet(&earth, dt);
        update_planet(&moon, dt);

        // Print the planet positions
        printf("Earth: (%f, %f, %f)\n", earth.x, earth.y, earth.z);
        printf("Moon: (%f, %f, %f)\n", moon.x, moon.y, moon.z);

        // Exit the program
        if (fabs(earth.x - moon.x) < 1e-6 && fabs(earth.y - moon.y) < 1e-6 && fabs(earth.z - moon.z) < 1e-6) {
            break;
        }
    }

    return 0;
}