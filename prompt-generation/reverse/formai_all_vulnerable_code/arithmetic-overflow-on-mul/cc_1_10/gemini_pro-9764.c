//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Define the mass and radius of the Earth
#define EARTH_MASS 5.972e24 // kg
#define EARTH_RADIUS 6.371e6 // m

// Define the gravitational constant
#define G 6.674e-11 // m^3 kg^-1 s^-2

// Define the time step
#define DT 1 // s

// Define the number of particles
#define N 1000

// Define the particle structure
typedef struct {
  double x, y, z; // Position (m)
  double vx, vy, vz; // Velocity (m/s)
  double m; // Mass (kg)
} Particle;

// Initialize the particles
Particle *particles;

void initializeParticles() {
  // Set the random seed
  srand(time(NULL));

  // Allocate memory for the particles
  particles = malloc(N * sizeof(Particle));

  // Initialize the particle positions and velocities
  for (int i = 0; i < N; i++) {
    // Set the particle's position
    particles[i].x = (2 * rand() / (RAND_MAX + 1.0) - 1.0) * EARTH_RADIUS;
    particles[i].y = (2 * rand() / (RAND_MAX + 1.0) - 1.0) * EARTH_RADIUS;
    particles[i].z = (2 * rand() / (RAND_MAX + 1.0) - 1.0) * EARTH_RADIUS;

    // Set the particle's velocity
    particles[i].vx = (2 * rand() / (RAND_MAX + 1.0) - 1.0) * 100;
    particles[i].vy = (2 * rand() / (RAND_MAX + 1.0) - 1.0) * 100;
    particles[i].vz = (2 * rand() / (RAND_MAX + 1.0) - 1.0) * 100;

    // Set the particle's mass
    particles[i].m = 1e4; // kg
  }
}

// Update the particle positions and velocities
void updateParticles() {
  // Calculate the gravitational force on each particle
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      // Calculate the distance between the particles
      double dx = particles[i].x - particles[j].x;
      double dy = particles[i].y - particles[j].y;
      double dz = particles[i].z - particles[j].z;
      double r = sqrt(dx * dx + dy * dy + dz * dz);

      // Calculate the gravitational force
      double f = G * particles[i].m * particles[j].m / (r * r);

      // Calculate the acceleration on each particle
      particles[i].vx += f * dx / r * DT / particles[i].m;
      particles[i].vy += f * dy / r * DT / particles[i].m;
      particles[i].vz += f * dz / r * DT / particles[i].m;
      
      particles[j].vx -= f * dx / r * DT / particles[j].m;
      particles[j].vy -= f * dy / r * DT / particles[j].m;
      particles[j].vz -= f * dz / r * DT / particles[j].m;
    }
  }

  // Update the particle positions
  for (int i = 0; i < N; i++) {
    particles[i].x += particles[i].vx * DT;
    particles[i].y += particles[i].vy * DT;
    particles[i].z += particles[i].vz * DT;
  }
}

// Main function
int main() {
  // Initialize the particles
  initializeParticles();

  // Update the particles for 1000 time steps
  for (int i = 0; i < 1000; i++) {
    updateParticles();
  }

  // Print the final particle positions
  for (int i = 0; i < N; i++) {
    printf("%f %f %f\n", particles[i].x, particles[i].y, particles[i].z);
  }

  // Free the memory allocated for the particles
  free(particles);

  return 0;
}