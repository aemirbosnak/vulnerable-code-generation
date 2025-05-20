//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11   // gravitational constant
#define M_EARTH 5.97e24  // mass of Earth
#define R_EARTH 6371000 // radius of Earth

// define a structure for a planet
typedef struct {
    double mass;
    double radius;
    double x;
    double y;
    double z;
    double vx;
    double vy;
    double vz;
    double ax;
    double ay;
    double az;
} Planet;

// calculate the distance between two planets
double calculateDistance(Planet planet1, Planet planet2) {
    double dx = planet1.x - planet2.x;
    double dy = planet1.y - planet2.y;
    double dz = planet1.z - planet2.z;
    return sqrt(dx*dx + dy*dy + dz*dz);
}

// calculate the gravitational force between two planets
double calculateForce(Planet planet1, Planet planet2) {
    double distance = calculateDistance(planet1, planet2);
    return G * planet1.mass * planet2.mass / (distance * distance);
}

// calculate the acceleration of a planet
void calculateAcceleration(Planet *p, Planet planets[], int numPlanets) {
    double fx = 0, fy = 0, fz = 0;
    for(int i = 0; i < numPlanets; i++) {
        if(p == &planets[i]) continue;
        double force = calculateForce(*p, planets[i]);
        double distance = calculateDistance(*p, planets[i]);
        fx += force * (planets[i].x - p->x) / distance;
        fy += force * (planets[i].y - p->y) / distance;
        fz += force * (planets[i].z - p->z) / distance;
    }
    p->ax = fx / p->mass;
    p->ay = fy / p->mass;
    p->az = fz / p->mass;
}

// update the velocity and position of a planet based on its acceleration
void updatePlanet(Planet *p, double dt) {
    p->vx += p->ax * dt;
    p->vy += p->ay * dt;
    p->vz += p->az * dt;
    p->x += p->vx * dt;
    p->y += p->vy * dt;
    p->z += p->vz * dt;
}

int main() {
    int numPlanets = 3;
    Planet planets[numPlanets];

    // planet 1 - Earth
    planets[0].mass = M_EARTH;
    planets[0].radius = R_EARTH;
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;

    // planet 2 - Moon
    planets[1].mass = 7.36e22;
    planets[1].radius = 1737100;
    planets[1].x = 384400000;
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 1022;
    planets[1].vz = 0;

    // planet 3 - Sun
    planets[2].mass = 1.99e30;
    planets[2].radius = 696340000;
    planets[2].x = 0;
    planets[2].y = 0;
    planets[2].z = 0;
    planets[2].vx = 0;
    planets[2].vy = 0;
    planets[2].vz = 0;

    double dt = 3600; // time step: 1 hour
    for(int i = 0; i < 365*24; i++) { // simulate for 1 year
        // calculate acceleration of each planet
        for(int j = 0; j < numPlanets; j++) {
            calculateAcceleration(&planets[j], planets, numPlanets);
        }
        // update position and velocity of each planet
        for(int j = 0; j < numPlanets; j++) {
            updatePlanet(&planets[j], dt);
        }
        // print the position of the Moon every day
        if((i+1) % 24 == 0) {
            printf("Day %d: (%.0f, %.0f, %.0f)\n", (i+1)/24, planets[1].x, planets[1].y, planets[1].z);
        }
    }

    return 0;
}