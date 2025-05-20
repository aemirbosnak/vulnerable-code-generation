//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.674e-11 // m^3 kg^-1 s^-2

// Define the mass of the Earth
#define M 5.972e24 // kg

// Define the radius of the Earth
#define R 6.371e6 // m

// Define the time step
#define DT 1 // s

// Define the number of particles
#define N 1000

// Define the initial positions and velocities of the particles
double x[N], y[N], z[N], vx[N], vy[N], vz[N];

// Initialize the positions and velocities of the particles
void init_particles() {
  for (int i = 0; i < N; i++) {
    // Generate a random position within a sphere of radius R
    double r = R * sqrt(drand48());
    double theta = 2 * M_PI * drand48();
    double phi = acos(2 * drand48() - 1);
    x[i] = r * sin(phi) * cos(theta);
    y[i] = r * sin(phi) * sin(theta);
    z[i] = r * cos(phi);

    // Generate a random velocity within a sphere of radius v_esc
    double v_esc = sqrt(2 * G * M / R);
    double v = v_esc * drand48();
    theta = 2 * M_PI * drand48();
    phi = acos(2 * drand48() - 1);
    vx[i] = v * sin(phi) * cos(theta);
    vy[i] = v * sin(phi) * sin(theta);
    vz[i] = v * cos(phi);
  }
}

// Calculate the gravitational force between two particles
void calculate_force(int i, int j, double *fx, double *fy, double *fz) {
  // Calculate the distance between the particles
  double dx = x[j] - x[i];
  double dy = y[j] - y[i];
  double dz = z[j] - z[i];
  double r = sqrt(dx * dx + dy * dy + dz * dz);

  // Calculate the gravitational force
  double f = G * M * M / (r * r);

  // Calculate the force components
  *fx = f * dx / r;
  *fy = f * dy / r;
  *fz = f * dz / r;
}

// Update the positions and velocities of the particles
void update_particles() {
  for (int i = 0; i < N; i++) {
    // Calculate the total force on the particle
    double fx = 0, fy = 0, fz = 0;
    for (int j = 0; j < N; j++) {
      if (i != j) {
        calculate_force(i, j, &fx, &fy, &fz);
      }
    }

    // Update the position of the particle
    x[i] += vx[i] * DT + 0.5 * fx * DT * DT;
    y[i] += vy[i] * DT + 0.5 * fy * DT * DT;
    z[i] += vz[i] * DT + 0.5 * fz * DT * DT;

    // Update the velocity of the particle
    vx[i] += fx * DT;
    vy[i] += fy * DT;
    vz[i] += fz * DT;
  }
}

// Main function
int main() {
  // Initialize the random number generator
  srand48(time(NULL));

  // Initialize the particles
  init_particles();

  // Simulate the physics
  for (int t = 0; t < 1000; t++) {
    // Update the particles
    update_particles();

    // Print the positions of the particles
    for (int i = 0; i < N; i++) {
      printf("%f %f %f\n", x[i], y[i], z[i]);
    }
    printf("\n");
  }

  return 0;
}