//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11
#define PI 3.14159265359

// Structure for planet
typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
} Planet;

// Function for calculating gravitational force
void calc_force(Planet *p1, Planet *p2, double dx, double dy, double dz) {
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p1->mass * p2->mass / (r*r);
    p1->vx -= f*dx/r;
    p1->vy -= f*dy/r;
    p1->vz -= f*dz/r;
    p2->vx += f*dx/r;
    p2->vy += f*dy/r;
    p2->vz += f*dz/r;
}

// Function for updating planet position
void update_planet(Planet *p, double dt) {
    p->x += p->vx*dt;
    p->y += p->vy*dt;
    p->z += p->vz*dt;
}

// Function for main simulation loop
void simulate(Planet *planets, int num_planets, double dt) {
    for (int i = 0; i < num_planets; i++) {
        for (int j = i+1; j < num_planets; j++) {
            calc_force(&planets[i], &planets[j], planets[j].x-planets[i].x, planets[j].y-planets[i].y, planets[j].z-planets[i].z);
        }
        update_planet(&planets[i], dt);
    }
}

int main() {
    int num_planets;
    printf("Enter number of planets: ");
    scanf("%d", &num_planets);

    Planet *planets = malloc(num_planets * sizeof(Planet));

    for (int i = 0; i < num_planets; i++) {
        printf("Enter planet %d mass: ", i+1);
        scanf("%lf", &planets[i].mass);
        printf("Enter planet %d initial position (x y z): ", i+1);
        scanf("%lf %lf %lf", &planets[i].x, &planets[i].y, &planets[i].z);
        planets[i].vx = 0;
        planets[i].vy = 0;
        planets[i].vz = 0;
    }

    double dt = 0.01;
    int steps = 1000;

    for (int i = 0; i < steps; i++) {
        simulate(planets, num_planets, dt);
    }

    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d final position (x y z): %lf %lf %lf\n", i+1, planets[i].x, planets[i].y, planets[i].z);
    }

    free(planets);
    return 0;
}