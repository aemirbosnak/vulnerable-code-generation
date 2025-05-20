//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11  // Gravitational constant
#define dt 0.001  // Time step

typedef struct {
  double m;  // Mass
  double x;  // X-coordinate
  double y;  // Y-coordinate
  double vx;  // X-velocity
  double vy;  // Y-velocity
} Particle;

int main() {
  int n;  // Number of particles
  printf("Enter the number of particles: ");
  scanf("%d", &n);

  Particle *particles = malloc(n * sizeof(Particle));

  // Initialize the particles
  for (int i = 0; i < n; i++) {
    printf("Enter the mass, x-coordinate, y-coordinate, x-velocity, and y-velocity of particle %d: ", i);
    scanf("%lf %lf %lf %lf %lf", &particles[i].m, &particles[i].x, &particles[i].y, &particles[i].vx, &particles[i].vy);
  }

  // Run the simulation
  for (int t = 0; t < 1000; t++) {
    // Calculate the forces on each particle
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (i == j) continue;

        double dx = particles[j].x - particles[i].x;
        double dy = particles[j].y - particles[i].y;
        double r = sqrt(dx * dx + dy * dy);

        double f = G * particles[i].m * particles[j].m / (r * r);

        particles[i].vx += f * dx / r * dt;
        particles[i].vy += f * dy / r * dt;
      }
    }

    // Update the positions and velocities of each particle
    for (int i = 0; i < n; i++) {
      particles[i].x += particles[i].vx * dt;
      particles[i].y += particles[i].vy * dt;
    }

    // Print the positions of the particles
    printf("Positions at t = %d:\n", t);
    for (int i = 0; i < n; i++) {
      printf("Particle %d: (%.2f, %.2f)\n", i, particles[i].x, particles[i].y);
    }
  }

  free(particles);

  return 0;
}