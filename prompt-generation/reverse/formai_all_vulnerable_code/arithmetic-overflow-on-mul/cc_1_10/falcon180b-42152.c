//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define GRAVITY 6.674e-11
#define PLANET_RADIUS 6371e3
#define PLANET_MASS 5.972e24
#define TIME_STEP 60

typedef struct {
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
} Planet;

void init_planet(Planet *planet) {
    double theta = 2 * M_PI * rand() / RAND_MAX;
    double phi = acos(2 * rand() / RAND_MAX - 1);

    planet->x = PLANET_RADIUS * sin(phi) * cos(theta);
    planet->y = PLANET_RADIUS * sin(phi) * sin(theta);
    planet->z = PLANET_RADIUS * cos(phi);

    planet->vx = (2 * rand() / RAND_MAX - 1) * 100;
    planet->vy = (2 * rand() / RAND_MAX - 1) * 100;
    planet->vz = (2 * rand() / RAND_MAX - 1) * 100;
}

void update_position(Planet *planet, double dt) {
    planet->x += planet->vx * dt;
    planet->y += planet->vy * dt;
    planet->z += planet->vz * dt;
}

void update_velocity(Planet *planet, double dt) {
    double r = sqrt(planet->x * planet->x + planet->y * planet->y + planet->z * planet->z);
    double force = GRAVITY * PLANET_MASS / pow(r, 2);

    planet->vx += force * planet->x / r * dt;
    planet->vy += force * planet->y / r * dt;
    planet->vz += force * planet->z / r * dt;
}

int main() {
    srand(time(NULL));

    int num_planets = 100;
    Planet planets[num_planets];

    for (int i = 0; i < num_planets; i++) {
        init_planet(&planets[i]);
    }

    while (1) {
        for (int i = 0; i < num_planets; i++) {
            update_position(&planets[i], TIME_STEP);
            update_velocity(&planets[i], TIME_STEP);
        }
    }

    return 0;
}