//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

// Structure to represent a planet
struct planet {
    double mass; // Mass of the planet
    double x, y, z; // Coordinates of the planet
    double vx, vy, vz; // Velocity of the planet
};

// Function to calculate the gravitational force between two planets
void gravity(struct planet p1, struct planet p2, double dt) {
    double dx = p2.x - p1.x;
    double dy = p2.y - p1.y;
    double dz = p2.z - p1.z;
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double force = G * p1.mass * p2.mass / (r*r);
    p1.vx -= force*dx/r*dt;
    p1.vy -= force*dy/r*dt;
    p1.vz -= force*dz/r*dt;
    p2.vx += force*dx/r*dt;
    p2.vy += force*dy/r*dt;
    p2.vz += force*dz/r*dt;
}

// Function to update the coordinates and velocity of a planet
void update_planet(struct planet p, double dt) {
    p.x += p.vx*dt;
    p.y += p.vy*dt;
    p.z += p.vz*dt;
}

// Function to print the coordinates and velocity of a planet
void print_planet(struct planet p) {
    printf("Planet at (%lf, %lf, %lf) with velocity (%lf, %lf, %lf)\n", p.x, p.y, p.z, p.vx, p.vy, p.vz);
}

int main() {
    int n;
    printf("Enter the number of planets: ");
    scanf("%d", &n);

    struct planet planets[n];

    // Initialize the planets
    for(int i=0; i<n; i++) {
        printf("Enter the mass of planet %d: ", i+1);
        scanf("%lf", &planets[i].mass);
        printf("Enter the initial coordinates of planet %d: ", i+1);
        scanf("%lf %lf %lf", &planets[i].x, &planets[i].y, &planets[i].z);
        printf("Enter the initial velocity of planet %d: ", i+1);
        scanf("%lf %lf %lf", &planets[i].vx, &planets[i].vy, &planets[i].vz);
    }

    // Simulate the gravity between the planets
    double dt = 0.01; // Time step
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            gravity(planets[i], planets[j], dt);
        }
        update_planet(planets[i], dt);
    }

    // Print the final coordinates and velocity of the planets
    printf("Final state of the planets:\n");
    for(int i=0; i<n; i++) {
        print_planet(planets[i]);
    }

    return 0;
}