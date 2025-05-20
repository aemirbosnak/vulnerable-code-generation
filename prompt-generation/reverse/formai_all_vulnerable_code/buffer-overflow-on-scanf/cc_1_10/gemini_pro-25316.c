//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11 // Gravitational constant

// Planet structure
typedef struct planet {
    double mass;
    double x, y, z; // Position
    double vx, vy, vz; // Velocity
} planet;

// Simulation parameters
int num_planets;
double timestep;
double simulation_time;

// Initialize planets
void initialize_planets(planet *planets) {
    // Set masses
    planets[0].mass = 1e30; // Sun
    planets[1].mass = 5.972e24; // Earth
    planets[2].mass = 1.899e27; // Jupiter
    planets[3].mass = 5.685e26; // Saturn
    planets[4].mass = 8.683e25; // Uranus
    planets[5].mass = 1.024e26; // Neptune

    // Set initial positions and velocities
    planets[0].x = 0;
    planets[0].y = 0;
    planets[0].z = 0;
    planets[0].vx = 0;
    planets[0].vy = 0;
    planets[0].vz = 0;

    planets[1].x = -1.521e11;
    planets[1].y = 0;
    planets[1].z = 0;
    planets[1].vx = 0;
    planets[1].vy = 30000;
    planets[1].vz = 0;

    planets[2].x = -6.267e11;
    planets[2].y = 0;
    planets[2].z = 0;
    planets[2].vx = 0;
    planets[2].vy = 13070;
    planets[2].vz = 0;

    planets[3].x = -1.201e12;
    planets[3].y = 0;
    planets[3].z = 0;
    planets[3].vx = 0;
    planets[3].vy = 9680;
    planets[3].vz = 0;

    planets[4].x = -2.735e12;
    planets[4].y = 0;
    planets[4].z = 0;
    planets[4].vx = 0;
    planets[4].vy = 6800;
    planets[4].vz = 0;

    planets[5].x = -4.495e12;
    planets[5].y = 0;
    planets[5].z = 0;
    planets[5].vx = 0;
    planets[5].vy = 5430;
    planets[5].vz = 0;
}

// Calculate gravitational force between two planets
void calculate_force(planet *planets, int i, int j) {
    double dx = planets[j].x - planets[i].x;
    double dy = planets[j].y - planets[i].y;
    double dz = planets[j].z - planets[i].z;

    double r = sqrt(dx*dx + dy*dy + dz*dz);
    double f = G * planets[i].mass * planets[j].mass / (r*r);

    // Calculate the force vector
    planets[i].vx += f * dx / r;
    planets[i].vy += f * dy / r;
    planets[i].vz += f * dz / r;

    planets[j].vx -= f * dx / r;
    planets[j].vy -= f * dy / r;
    planets[j].vz -= f * dz / r;
}

// Update positions and velocities
void update_positions(planet *planets) {
    for (int i = 0; i < num_planets; i++) {
        // Update positions
        planets[i].x += planets[i].vx * timestep;
        planets[i].y += planets[i].vy * timestep;
        planets[i].z += planets[i].vz * timestep;

        // Update velocities
        calculate_force(planets, i, 0);
        for (int j = 1; j < num_planets; j++) {
            if (i != j) {
                calculate_force(planets, i, j);
            }
        }
    }
}

// Print planet positions
void print_positions(planet *planets) {
    printf("Positions:\n");
    for (int i = 0; i < num_planets; i++) {
        printf("Planet %d:\n", i+1);
        printf("x: %.2e km\n", planets[i].x / 1000);
        printf("y: %.2e km\n", planets[i].y / 1000);
        printf("z: %.2e km\n", planets[i].z / 1000);
        printf("\n");
    }
}

// Main function
int main() {
    // Get simulation parameters
    printf("Enter the number of planets: ");
    scanf("%d", &num_planets);

    printf("Enter the timestep (in seconds): ");
    scanf("%lf", &timestep);

    printf("Enter the simulation time (in seconds): ");
    scanf("%lf", &simulation_time);

    // Allocate memory for planets
    planet *planets = (planet*) malloc(num_planets * sizeof(planet));

    // Initialize planets
    initialize_planets(planets);

    // Run simulation
    for (double t = 0; t < simulation_time; t += timestep) {
        update_positions(planets);
    }

    // Print planet positions
    print_positions(planets);

    // Free memory
    free(planets);

    return 0;
}