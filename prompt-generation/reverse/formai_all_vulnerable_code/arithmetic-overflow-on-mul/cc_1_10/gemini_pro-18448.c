//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.674e-11

// Define the mass of the planets
#define M_EARTH 5.972e24 // kg
#define M_MARS 6.417e23 // kg
#define M_JUPITER 1.899e27 // kg
#define M_SATURN 5.685e26 // kg
#define M_URANUS 8.683e25 // kg
#define M_NEPTUNE 1.024e26 // kg

// Define the time step
#define DT 100 // seconds

// Define the number of planets
#define N_PLANETS 6

// Define the positions and velocities of the planets
double x[N_PLANETS], y[N_PLANETS], z[N_PLANETS];
double vx[N_PLANETS], vy[N_PLANETS], vz[N_PLANETS];

// Initialize the positions and velocities of the planets
void initialize() {
  // Earth
  x[0] = 1.5e11; // meters
  y[0] = 0;
  z[0] = 0;
  vx[0] = 0;
  vy[0] = 30000; // meters per second
  vz[0] = 0;

  // Mars
  x[1] = 2.4e11; // meters
  y[1] = 0;
  z[1] = 0;
  vx[1] = 0;
  vy[1] = 24000; // meters per second
  vz[1] = 0;

  // Jupiter
  x[2] = 7.7e11; // meters
  y[2] = 0;
  z[2] = 0;
  vx[2] = 0;
  vy[2] = 13000; // meters per second
  vz[2] = 0;

  // Saturn
  x[3] = 1.4e12; // meters
  y[3] = 0;
  z[3] = 0;
  vx[3] = 0;
  vy[3] = 9000; // meters per second
  vz[3] = 0;

  // Uranus
  x[4] = 2.8e12; // meters
  y[4] = 0;
  z[4] = 0;
  vx[4] = 0;
  vy[4] = 6000; // meters per second
  vz[4] = 0;

  // Neptune
  x[5] = 4.5e12; // meters
  y[5] = 0;
  z[5] = 0;
  vx[5] = 0;
  vy[5] = 5000; // meters per second
  vz[5] = 0;
}

// Calculate the force between two planets
void calculate_force(int i, int j) {
  // Calculate the distance between the two planets
  double dx = x[i] - x[j];
  double dy = y[i] - y[j];
  double dz = z[i] - z[j];
  double r = sqrt(dx * dx + dy * dy + dz * dz);

  // Calculate the force between the two planets
  double f = G * M_EARTH * M_MARS / (r * r);

  // Calculate the direction of the force
  double fx = f * dx / r;
  double fy = f * dy / r;
  double fz = f * dz / r;

  // Apply the force to the two planets
  vx[i] += fx * DT / M_EARTH;
  vy[i] += fy * DT / M_EARTH;
  vz[i] += fz * DT / M_EARTH;

  vx[j] -= fx * DT / M_MARS;
  vy[j] -= fy * DT / M_MARS;
  vz[j] -= fz * DT / M_MARS;
}

// Update the positions and velocities of the planets
void update() {
  // Calculate the force between each pair of planets
  for (int i = 0; i < N_PLANETS; i++) {
    for (int j = i + 1; j < N_PLANETS; j++) {
      calculate_force(i, j);
    }
  }

  // Update the positions and velocities of the planets
  for (int i = 0; i < N_PLANETS; i++) {
    x[i] += vx[i] * DT;
    y[i] += vy[i] * DT;
    z[i] += vz[i] * DT;
  }
}

// Main function
int main() {
  // Initialize the positions and velocities of the planets
  initialize();

  // Simulate the motion of the planets for 1000 years
  for (int i = 0; i < 1000 * 365 * 24 * 60 * 60 / DT; i++) {
    // Update the positions and velocities of the planets
    update();

    // Print the positions of the planets
    printf("%f %f %f\n", x[0], y[0], z[0]);
    printf("%f %f %f\n", x[1], y[1], z[1]);
    printf("%f %f %f\n", x[2], y[2], z[2]);
    printf("%f %f %f\n", x[3], y[3], z[3]);
    printf("%f %f %f\n", x[4], y[4], z[4]);
    printf("%f %f %f\n", x[5], y[5], z[5]);
  }

  return 0;
}