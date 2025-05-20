//Falcon-180B DATASET v1.0 Category: Planet Gravity Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

// Structure for a planet
struct planet {
    double x, y, z, vx, vy, vz, mass;
};

// Function to calculate force between two planets
void force(struct planet p1, struct planet p2, double dx, double dy, double dz) {
    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * p1.mass * p2.mass / (r*r);
    p1.vx -= f*dx/r;
    p1.vy -= f*dy/r;
    p1.vz -= f*dz/r;
    p2.vx += f*dx/r;
    p2.vy += f*dy/r;
    p2.vz += f*dz/r;
}

// Function to update position and velocity of a planet
void update(struct planet p, double dt) {
    p.x += p.vx*dt;
    p.y += p.vy*dt;
    p.z += p.vz*dt;
}

// Main function
int main() {
    int n;
    printf("Enter the number of planets: ");
    scanf("%d", &n);

    // Allocate memory for planets
    struct planet *planets = (struct planet*)malloc(n*sizeof(struct planet));

    // Initialize planets
    for(int i=0; i<n; i++) {
        planets[i].mass = rand()%100;
        planets[i].x = rand()%1000 - 500;
        planets[i].y = rand()%1000 - 500;
        planets[i].z = rand()%1000 - 500;
        planets[i].vx = (rand()%100 - 50)/100.0;
        planets[i].vy = (rand()%100 - 50)/100.0;
        planets[i].vz = (rand()%100 - 50)/100.0;
    }

    // Simulation loop
    for(int i=0; i<1000; i++) {
        for(int j=0; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                force(planets[j], planets[k], planets[j].x-planets[k].x, planets[j].y-planets[k].y, planets[j].z-planets[k].z);
            }
            update(planets[j], 0.01);
        }
    }

    // Free memory
    free(planets);
    return 0;
}