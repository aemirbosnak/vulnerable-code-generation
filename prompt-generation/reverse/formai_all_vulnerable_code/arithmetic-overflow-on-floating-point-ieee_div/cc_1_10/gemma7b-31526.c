//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: mathematical
#include <stdio.h>
#include <math.h>

#define G 6.67408e-11 // Gravitational constant

typedef struct Particle {
  double mass;
  double x;
  double y;
  double z;
  double ax;
  double ay;
  double az;
} Particle;

int main() {
  Particle particle1 = {
    .mass = 10,
    .x = 0,
    .y = 0,
    .z = 0,
    .ax = 0,
    .ay = 0,
    .az = -9.81
  };

  double dt = 0.01; // Time step

  for (int i = 0; i < 1000; i++) {
    // Calculate acceleration due to gravity
    double ax_g = G * particle1.mass / (particle1.x * particle1.x + particle1.y * particle1.y + particle1.z * particle1.z) * particle1.mass;
    double ay_g = G * particle1.mass / (particle1.x * particle1.x + particle1.y * particle1.y + particle1.z * particle1.z) * particle1.mass;
    double az_g = -9.81;

    // Update acceleration
    particle1.ax = ax_g;
    particle1.ay = ay_g;
    particle1.az = az_g;

    // Update position and velocity
    particle1.x += particle1.ax * dt;
    particle1.y += particle1.ay * dt;
    particle1.z += particle1.az * dt;

    // Print position
    printf("%f, %f, %f\n", particle1.x, particle1.y, particle1.z);
  }

  return 0;
}