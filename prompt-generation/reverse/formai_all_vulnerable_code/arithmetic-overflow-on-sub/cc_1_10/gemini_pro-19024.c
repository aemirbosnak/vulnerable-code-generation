//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the gravitational constant
#define G 6.674e-11

// Define the mass of the Earth
#define M_EARTH 5.972e24

// Define the radius of the Earth
#define R_EARTH 6.371e6

// Define the time step
#define DT 1.0

// Define the number of particles
#define N 1000

// Define the particle structure
typedef struct {
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
    // Generate a random position within a sphere of radius R_EARTH
    double r = R_EARTH * sqrt(drand48());
    double theta = 2 * M_PI * drand48();
    double phi = acos(2 * drand48() - 1);
    particles[i].x = r * sin(phi) * cos(theta);
    particles[i].y = r * sin(phi) * sin(theta);
    particles[i].z = r * cos(phi);

    // Generate a random velocity
    double v = sqrt(2 * G * M_EARTH / r);
    theta = 2 * M_PI * drand48();
    phi = acos(2 * drand48() - 1);
    particles[i].vx = v * sin(phi) * cos(theta);
    particles[i].vy = v * sin(phi) * sin(theta);
    particles[i].vz = v * cos(phi);

    // Set the mass of the particle
    particles[i].m = 1.0;
  }
}

// Calculate the force between two particles
void calculate_force(particle *particle1, particle *particle2, double *fx, double *fy, double *fz) {
  // Calculate the distance between the two particles
  double dx = particle2->x - particle1->x;
  double dy = particle2->y - particle1->y;
  double dz = particle2->z - particle1->z;
  double r = sqrt(dx * dx + dy * dy + dz * dz);

  // Calculate the force between the two particles
  *fx = -G * particle1->m * particle2->m * dx / (r * r * r);
  *fy = -G * particle1->m * particle2->m * dy / (r * r * r);
  *fz = -G * particle1->m * particle2->m * dz / (r * r * r);
}

// Update the velocity and position of the particles
void update_particles(particle *particles) {
  for (int i = 0; i < N; i++) {
    // Calculate the force on the particle
    double fx, fy, fz;
    fx = fy = fz = 0.0;
    for (int j = 0; j < N; j++) {
      if (i != j) {
        calculate_force(&particles[i], &particles[j], &fx, &fy, &fz);
      }
    }

    // Update the velocity of the particle
    particles[i].vx += fx * DT / particles[i].m;
    particles[i].vy += fy * DT / particles[i].m;
    particles[i].vz += fz * DT / particles[i].m;

    // Update the position of the particle
    particles[i].x += particles[i].vx * DT;
    particles[i].y += particles[i].vy * DT;
    particles[i].z += particles[i].vz * DT;
  }
}

// Main function
int main() {
  // Allocate memory for the particles
  particle *particles = malloc(N * sizeof(particle));

  // Initialize the particles
  initialize_particles(particles);

  // Simulate the physics
  for (int i = 0; i < 10000; i++) {
    // Update the particles
    update_particles(particles);

    // Print the positions of the particles
    for (int j = 0; j < N; j++) {
      printf("%f %f %f\n", particles[j].x, particles[j].y, particles[j].z);
    }
    printf("\n");
  }

  // Free the memory for the particles
  free(particles);

  return 0;
}