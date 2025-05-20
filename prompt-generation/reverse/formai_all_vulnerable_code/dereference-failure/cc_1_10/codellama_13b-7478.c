//Code Llama-13B DATASET v1.0 Category: Planet Gravity Simulation ; Style: high level of detail
// Planet Gravity Simulation in C

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define constants
#define G 6.67408e-11 // Gravitational constant
#define PI 3.14159 // Pi

// Define struct for planet data
typedef struct {
  double mass;
  double x, y, z;
  double vx, vy, vz;
} Planet;

// Define struct for simulation data
typedef struct {
  double time;
  double dt;
  int nplanets;
  Planet *planets;
} Simulation;

// Function to initialize simulation data
void init_simulation(Simulation *sim) {
  // Set time and time step
  sim->time = 0;
  sim->dt = 1;
  // Set number of planets
  sim->nplanets = 2;
  // Allocate memory for planet data
  sim->planets = malloc(sim->nplanets * sizeof(Planet));
  // Initialize planet data
  for (int i = 0; i < sim->nplanets; i++) {
    sim->planets[i].mass = 1;
    sim->planets[i].x = 0;
    sim->planets[i].y = 0;
    sim->planets[i].z = 0;
    sim->planets[i].vx = 0;
    sim->planets[i].vy = 0;
    sim->planets[i].vz = 0;
  }
}

// Function to compute gravitational force between two planets
double compute_gravitational_force(Planet *p1, Planet *p2) {
  double r = sqrt((p1->x - p2->x) * (p1->x - p2->x) +
                  (p1->y - p2->y) * (p1->y - p2->y) +
                  (p1->z - p2->z) * (p1->z - p2->z));
  double force = G * p1->mass * p2->mass / r;
  return force;
}

// Function to update planet positions and velocities
void update_planet_positions_and_velocities(Simulation *sim) {
  // Compute gravitational force between each pair of planets
  for (int i = 0; i < sim->nplanets; i++) {
    for (int j = 0; j < sim->nplanets; j++) {
      if (i != j) {
        double force = compute_gravitational_force(&sim->planets[i], &sim->planets[j]);
        // Update velocity
        sim->planets[i].vx += force * (sim->planets[j].x - sim->planets[i].x) / sim->planets[i].mass;
        sim->planets[i].vy += force * (sim->planets[j].y - sim->planets[i].y) / sim->planets[i].mass;
        sim->planets[i].vz += force * (sim->planets[j].z - sim->planets[i].z) / sim->planets[i].mass;
        // Update position
        sim->planets[i].x += sim->dt * sim->planets[i].vx;
        sim->planets[i].y += sim->dt * sim->planets[i].vy;
        sim->planets[i].z += sim->dt * sim->planets[i].vz;
      }
    }
  }
}

// Function to update time
void update_time(Simulation *sim) {
  sim->time += sim->dt;
}

// Function to print simulation data
void print_simulation_data(Simulation *sim) {
  printf("Time: %lf\n", sim->time);
  for (int i = 0; i < sim->nplanets; i++) {
    printf("Planet %d:\n", i);
    printf("  Mass: %lf\n", sim->planets[i].mass);
    printf("  Position: (%lf, %lf, %lf)\n", sim->planets[i].x, sim->planets[i].y, sim->planets[i].z);
    printf("  Velocity: (%lf, %lf, %lf)\n", sim->planets[i].vx, sim->planets[i].vy, sim->planets[i].vz);
  }
}

int main() {
  // Initialize simulation
  Simulation sim;
  init_simulation(&sim);
  // Print initial simulation data
  print_simulation_data(&sim);
  // Update simulation for 100 time steps
  for (int i = 0; i < 100; i++) {
    update_planet_positions_and_velocities(&sim);
    update_time(&sim);
    print_simulation_data(&sim);
  }
  // Free memory
  free(sim.planets);
  return 0;
}