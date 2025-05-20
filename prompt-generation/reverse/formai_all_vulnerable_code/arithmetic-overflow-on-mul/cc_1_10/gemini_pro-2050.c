//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.674e-11

// Define the mass of the Earth
#define EARTH_MASS 5.972e24

// Define the radius of the Earth
#define EARTH_RADIUS 6.371e6

// Define the time step
#define DT 1.0

// Define the number of particles
#define N 1000

// Define the particle data structure
typedef struct particle {
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
  double m;
} particle;

// Initialize the particles
void initialize_particles(particle *particles) {
  for (int i = 0; i < N; i++) {
    // Generate a random position within a sphere of radius EARTH_RADIUS
    double r = EARTH_RADIUS * sqrt(drand48());
    double theta = 2 * M_PI * drand48();
    double phi = acos(2 * drand48() - 1);
    particles[i].x = r * sin(theta) * cos(phi);
    particles[i].y = r * sin(theta) * sin(phi);
    particles[i].z = r * cos(theta);

    // Generate a random velocity
    double v = sqrt(G * EARTH_MASS / r);
    double alpha = 2 * M_PI * drand48();
    double beta = acos(2 * drand48() - 1);
    particles[i].vx = v * sin(alpha) * cos(beta);
    particles[i].vy = v * sin(alpha) * sin(beta);
    particles[i].vz = v * cos(alpha);

    // Set the mass
    particles[i].m = 1.0;
  }
}

// Update the particle positions and velocities
void update_particles(particle *particles, double dt) {
  for (int i = 0; i < N; i++) {
    // Calculate the acceleration on the particle
    double ax = 0.0;
    double ay = 0.0;
    double az = 0.0;
    for (int j = 0; j < N; j++) {
      if (i == j) continue;

      // Calculate the distance between the particles
      double dx = particles[i].x - particles[j].x;
      double dy = particles[i].y - particles[j].y;
      double dz = particles[i].z - particles[j].z;
      double r = sqrt(dx * dx + dy * dy + dz * dz);

      // Calculate the force between the particles
      double f = G * particles[i].m * particles[j].m / (r * r);

      // Calculate the acceleration on the particle
      ax += f * dx / r;
      ay += f * dy / r;
      az += f * dz / r;
    }

    // Update the particle's velocity
    particles[i].vx += ax * dt;
    particles[i].vy += ay * dt;
    particles[i].vz += az * dt;

    // Update the particle's position
    particles[i].x += particles[i].vx * dt;
    particles[i].y += particles[i].vy * dt;
    particles[i].z += particles[i].vz * dt;
  }
}

// Main function
int main() {
  // Allocate memory for the particles
  particle *particles = malloc(N * sizeof(particle));

  // Initialize the particles
  initialize_particles(particles);

  // Update the particles for a number of time steps
  for (int t = 0; t < 1000; t++) {
    // Update the particle positions and velocities
    update_particles(particles, DT);

    // Print the particle positions
    for (int i = 0; i < N; i++) {
      printf("%f %f %f\n", particles[i].x, particles[i].y, particles[i].z);
    }
  }

  // Free the memory allocated for the particles
  free(particles);

  return 0;
}