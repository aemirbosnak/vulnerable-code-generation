//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define G 6.67408e-11 // Gravitational constant

typedef struct {
    double mass;
    double x, y, z;
    double vx, vy, vz;
    double fx, fy, fz;
} Planet;

Planet planets[10000];
int num_planets = 0;

void add_planet(double mass, double x, double y, double z, double vx, double vy, double vz) {
    planets[num_planets].mass = mass;
    planets[num_planets].x = x;
    planets[num_planets].y = y;
    planets[num_planets].z = z;
    planets[num_planets].vx = vx;
    planets[num_planets].vy = vy;
    planets[num_planets].vz = vz;
    planets[num_planets].fx = 0;
    planets[num_planets].fy = 0;
    planets[num_planets].fz = 0;
    num_planets++;
}

void calculate_forces() {
    for (int i = 0; i < num_planets; i++) {
        for (int j = i + 1; j < num_planets; j++) {
            double dx = planets[j].x - planets[i].x;
            double dy = planets[j].y - planets[i].y;
            double dz = planets[j].z - planets[i].z;
            double r = sqrt(dx * dx + dy * dy + dz * dz);
            double f = G * planets[i].mass * planets[j].mass / (r * r);
            planets[i].fx += f * dx / r;
            planets[i].fy += f * dy / r;
            planets[i].fz += f * dz / r;
            planets[j].fx -= f * dx / r;
            planets[j].fy -= f * dy / r;
            planets[j].fz -= f * dz / r;
        }
    }
}

void update_velocities(double dt) {
    for (int i = 0; i < num_planets; i++) {
        planets[i].vx += dt * planets[i].fx / planets[i].mass;
        planets[i].vy += dt * planets[i].fy / planets[i].mass;
        planets[i].vz += dt * planets[i].fz / planets[i].mass;
    }
}

void update_positions(double dt) {
    for (int i = 0; i < num_planets; i++) {
        planets[i].x += dt * planets[i].vx;
        planets[i].y += dt * planets[i].vy;
        planets[i].z += dt * planets[i].vz;
    }
}

void print_planets() {
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d:\n", i);
        printf("  Mass: %f\n", planets[i].mass);
        printf("  Position: (%f, %f, %f)\n", planets[i].x, planets[i].y, planets[i].z);
        printf("  Velocity: (%f, %f, %f)\n", planets[i].vx, planets[i].vy, planets[i].vz);
        printf("  Forces: (%f, %f, %f)\n", planets[i].fx, planets[i].fy, planets[i].fz);
    }
}

int main() {
    srand(time(NULL));

    // Add some planets
    add_planet(1e24, 0, 0, 0, 0, 0, 0); // Sun
    add_planet(5.972e24, 1.496e11, 0, 0, 0, 30000, 0); // Earth
    add_planet(10.7e25, 1.511e12, 0, 0, 0, 24000, 0); // Mars
    add_planet(1.899e27, 0, 0, 0, 12200, 0, 0); // Jupiter
    add_planet(5.685e26, 0, 0, 0, 9600, 0, 0); // Saturn
    add_planet(8.683e25, 0, 0, 0, 6800, 0, 0); // Uranus
    add_planet(1.024e26, 0, 0, 0, 5400, 0, 0); // Neptune

    // Simulate the motion of the planets
    double dt = 1000;
    for (int i = 0; i < 10000; i++) {
        calculate_forces();
        update_velocities(dt);
        update_positions(dt);
        print_planets();
    }

    return 0;
}