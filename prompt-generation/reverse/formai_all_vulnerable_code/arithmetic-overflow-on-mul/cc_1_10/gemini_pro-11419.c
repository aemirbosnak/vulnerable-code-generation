//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double m;    // mass in kg
  double x;    // position in m
  double y;    // position in m
  double z;    // position in m
  double vx;   // velocity in m/s
  double vy;   // velocity in m/s
  double vz;   // velocity in m/s
} Body;

#define G 6.674e-11 // Gravitational constant in m^3 kg^-1 s^-2

// Initialize the Solar System bodies
Body bodies[] = {
  {1.989e30, 0, 0, 0, 0, 0, 0}, // Sun
  {5.972e24, 0, 1.5e11, 0, 0, 30000, 0}, // Earth
  {7.348e22, 0, 3.844e8, 0, 0, 12000, 0}, // Moon
  {1.899e27, 0, -2.4e12, 0, 0, 10000, 0}, // Jupiter
  {5.685e26, 0, -9.2e11, 0, 0, 9000, 0}, // Saturn
  {8.683e25, 0, -1.6e12, 0, 0, 8000, 0}, // Uranus
  {1.024e26, 0, -2.7e12, 0, 0, 7000, 0}, // Neptune
};

const int N_BODIES = sizeof(bodies) / sizeof(Body);

// Calculate the gravitational force between two bodies
double calc_force(Body *b1, Body *b2) {
  double dx = b2->x - b1->x;
  double dy = b2->y - b1->y;
  double dz = b2->z - b1->z;
  double r = sqrt(dx * dx + dy * dy + dz * dz);
  return (G * b1->m * b2->m) / (r * r);
}

// Update the positions and velocities of the bodies
void update_bodies() {
  // Calculate the gravitational forces between all pairs of bodies
  for (int i = 0; i < N_BODIES; i++) {
    bodies[i].vx += calc_force(&bodies[i], &bodies[(i + 1) % N_BODIES]) / bodies[i].m;
    bodies[i].vy += calc_force(&bodies[i], &bodies[(i + 1) % N_BODIES]) / bodies[i].m;
    bodies[i].vz += calc_force(&bodies[i], &bodies[(i + 1) % N_BODIES]) / bodies[i].m;
  }

  // Update the positions and velocities of the bodies
  for (int i = 0; i < N_BODIES; i++) {
    bodies[i].x += bodies[i].vx;
    bodies[i].y += bodies[i].vy;
    bodies[i].z += bodies[i].vz;
    bodies[i].vx += bodies[i].vx;
    bodies[i].vy += bodies[i].vy;
    bodies[i].vz += bodies[i].vz;
  }
}

// Main function
int main() {
  // Simulate the Solar System for 100 years
  for (int i = 0; i < 100 * 365 * 24 * 60 * 60; i++) {
    update_bodies();

    // Print the positions of the bodies
    for (int j = 0; j < N_BODIES; j++) {
      printf("%f %f %f\n", bodies[j].x, bodies[j].y, bodies[j].z);
    }
  }

  return 0;
}