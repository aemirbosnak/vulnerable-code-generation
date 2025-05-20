//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the mass of the sun
#define SUN_MASS 1.989e30

// Define the mass of the planets
#define MERCURY_MASS 3.285e23
#define VENUS_MASS 4.867e24
#define EARTH_MASS 5.972e24
#define MARS_MASS 6.417e23
#define JUPITER_MASS 1.899e27
#define SATURN_MASS 5.685e26
#define URANUS_MASS 8.683e25
#define NEPTUNE_MASS 1.024e26

// Define the gravitational constant
#define G 6.674e-11

// Define the time step
#define DT 10000

// Define the number of planets
#define NUM_PLANETS 8

// Define the structure of a planet
typedef struct {
  double mass;
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
} Planet;

// Initialize the planets
Planet planets[] = {
  {SUN_MASS, 0, 0, 0, 0, 0, 0},
  {MERCURY_MASS, 0, 0, 0, 0, 0, 0},
  {VENUS_MASS, 0, 0, 0, 0, 0, 0},
  {EARTH_MASS, 0, 0, 0, 0, 0, 0},
  {MARS_MASS, 0, 0, 0, 0, 0, 0},
  {JUPITER_MASS, 0, 0, 0, 0, 0, 0},
  {SATURN_MASS, 0, 0, 0, 0, 0, 0},
  {URANUS_MASS, 0, 0, 0, 0, 0, 0},
  {NEPTUNE_MASS, 0, 0, 0, 0, 0, 0}
};

// Compute the force between two planets
void compute_force(Planet *p1, Planet *p2) {
  double dx = p2->x - p1->x;
  double dy = p2->y - p1->y;
  double dz = p2->z - p1->z;
  double r = sqrt(dx*dx + dy*dy + dz*dz);
  double f = G * p1->mass * p2->mass / (r*r);
  p1->vx += f * dx / p1->mass;
  p1->vy += f * dy / p1->mass;
  p1->vz += f * dz / p1->mass;
  p2->vx -= f * dx / p2->mass;
  p2->vy -= f * dy / p2->mass;
  p2->vz -= f * dz / p2->mass;
}

// Update the positions and velocities of the planets
void update_planets() {
  for (int i = 0; i < NUM_PLANETS; i++) {
    for (int j = i + 1; j < NUM_PLANETS; j++) {
      compute_force(&planets[i], &planets[j]);
    }
    planets[i].x += planets[i].vx * DT;
    planets[i].y += planets[i].vy * DT;
    planets[i].z += planets[i].vz * DT;
  }
}

// Print the positions of the planets
void print_planets() {
  for (int i = 0; i < NUM_PLANETS; i++) {
    printf("Planet %d: (%.2f, %.2f, %.2f)\n", i, planets[i].x, planets[i].y, planets[i].z);
  }
}

// Main function
int main() {
  // Update the planets for 10000 time steps
  for (int i = 0; i < 10000; i++) {
    update_planets();
  }

  // Print the positions of the planets
  print_planets();

  return 0;
}