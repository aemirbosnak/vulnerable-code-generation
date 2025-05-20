//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

// Structure for a planet
typedef struct {
    double mass; // Mass of the planet
    double x, y, z; // Position of the planet
    double vx, vy, vz; // Velocity of the planet
} Planet;

// Function to calculate the gravitational force between two planets
void gravity(Planet p1, Planet p2, double dt) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double F = G * p1.mass * p2.mass / (r*r);
    p1.vx -= F*dx/r*dt;
    p1.vy -= F*dy/r*dt;
    p1.vz -= F*dz/r*dt;
    p2.vx += F*dx/r*dt;
    p2.vy += F*dy/r*dt;
    p2.vz += F*dz/r*dt;
}

// Function to update the position of a planet
void update_position(Planet p, double dt) {
    p.x += p.vx*dt;
    p.y += p.vy*dt;
    p.z += p.vz*dt;
}

// Function to print the current state of the simulation
void print_state(int num_planets, Planet planets[], double dt) {
    printf("Time: %f\n", dt);
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d:\n", i+1);
        printf("Mass: %f\n", planets[i].mass);
        printf("Position: (%f, %f, %f)\n", planets[i].x, planets[i].y, planets[i].z);
        printf("Velocity: (%f, %f, %f)\n\n", planets[i].vx, planets[i].vy, planets[i].vz);
    }
}

// Main function
int main() {
    int num_planets;
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    Planet planets[num_planets];

    // Initialize the planets
    for (int i = 0; i < num_planets; i++) {
        printf("Enter the mass of planet %d: ", i+1);
        scanf("%lf", &planets[i].mass);
        planets[i].x = 0;
        planets[i].y = 0;
        planets[i].z = 0;
        planets[i].vx = 0;
        planets[i].vy = 0;
        planets[i].vz = 0;
    }

    // Simulate the gravity between the planets
    double dt = 0.001; // Time step
    while (1) {
        for (int i = 0; i < num_planets; i++) {
            for (int j = i+1; j < num_planets; j++) {
                gravity(planets[i], planets[j], dt);
            }
        }
        for (int i = 0; i < num_planets; i++) {
            update_position(planets[i], dt);
        }
        print_state(num_planets, planets, dt);
        dt *= 10; // Increase the time step for faster simulation
    }

    return 0;
}