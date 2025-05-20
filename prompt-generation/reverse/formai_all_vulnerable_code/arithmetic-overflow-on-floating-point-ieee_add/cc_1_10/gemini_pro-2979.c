//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Gravitational constant
#define G 6.67408e-11

// Masses of the planets (in Earth masses)
#define EARTH_MASS 1.0
#define MARS_MASS 0.64171
#define JUPITER_MASS 317.83
#define SATURN_MASS 95.159

// Radii of the planets (in Earth radii)
#define EARTH_RADIUS 1.0
#define MARS_RADIUS 0.533
#define JUPITER_RADIUS 11.21
#define SATURN_RADIUS 9.44

// Number of time steps
#define NUM_STEPS 1000

// Time step (in seconds)
#define DT 3600

// Array to store the positions of the planets
double positions[4][3];

// Array to store the velocities of the planets
double velocities[4][3];

// Function to calculate the gravitational force between two planets
void calculate_force(double *f, double m1, double m2, double *r) {
  double r_mag = sqrt(r[0] * r[0] + r[1] * r[1] + r[2] * r[2]);
  double f_mag = G * m1 * m2 / (r_mag * r_mag);
  f[0] = f_mag * r[0] / r_mag;
  f[1] = f_mag * r[1] / r_mag;
  f[2] = f_mag * r[2] / r_mag;
}

// Function to update the positions and velocities of the planets
void update_positions_and_velocities() {
  // Calculate the forces between the planets
  double f[4][3];
  for (int i = 0; i < 4; i++) {
    for (int j = i + 1; j < 4; j++) {
      calculate_force(f[i], positions[i][0], positions[j][0], positions[j] - positions[i]);
      calculate_force(f[j], positions[j][0], positions[i][0], positions[i] - positions[j]);
    }
  }

  // Update the positions and velocities of the planets
  for (int i = 0; i < 4; i++) {
    positions[i][0] += velocities[i][0] * DT;
    positions[i][1] += velocities[i][1] * DT;
    positions[i][2] += velocities[i][2] * DT;
    velocities[i][0] += f[i][0] * DT / positions[i][0];
    velocities[i][1] += f[i][1] * DT / positions[i][0];
    velocities[i][2] += f[i][2] * DT / positions[i][0];
  }
}

// Function to print the positions of the planets
void print_positions() {
  printf("Positions of the planets (in Earth radii):\n");
  for (int i = 0; i < 4; i++) {
    printf("Planet %d: (%.2f, %.2f, %.2f)\n", i + 1, positions[i][0], positions[i][1], positions[i][2]);
  }
}

int main() {
  // Initialize the positions and velocities of the planets
  positions[0][0] = 0.0;
  positions[0][1] = 0.0;
  positions[0][2] = 0.0;
  velocities[0][0] = 0.0;
  velocities[0][1] = 0.0;
  velocities[0][2] = 0.0;
  positions[1][0] = 1.5 * EARTH_RADIUS;
  positions[1][1] = 0.0;
  positions[1][2] = 0.0;
  velocities[1][0] = 0.0;
  velocities[1][1] = 2 * M_PI * positions[1][0] / (24 * 3600);
  velocities[1][2] = 0.0;
  positions[2][0] = 5.2 * EARTH_RADIUS;
  positions[2][1] = 0.0;
  positions[2][2] = 0.0;
  velocities[2][0] = 0.0;
  velocities[2][1] = 2 * M_PI * positions[2][0] / (12 * 3600);
  velocities[2][2] = 0.0;
  positions[3][0] = 9.5 * EARTH_RADIUS;
  positions[3][1] = 0.0;
  positions[3][2] = 0.0;
  velocities[3][0] = 0.0;
  velocities[3][1] = 2 * M_PI * positions[3][0] / (10 * 3600);
  velocities[3][2] = 0.0;

  // Simulate the motion of the planets
  for (int i = 0; i < NUM_STEPS; i++) {
    update_positions_and_velocities();
  }

  // Print the final positions of the planets
  print_positions();

  return 0;
}