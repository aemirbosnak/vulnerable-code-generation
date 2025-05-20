//GEMINI-pro DATASET v1.0 Category: Simulation of the Solar System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
  double mass;
  double x, y, z;
  double vx, vy, vz;
} Body;

int main() {
  // Initialize the solar system
  Body sun = {1.989e30, 0, 0, 0, 0, 0, 0};
  Body earth = {5.972e24, 1.5e11, 0, 0, 0, 30000, 0};
  Body moon = {7.348e22, 3.844e8, 0, 0, 0, 1022, 0};

  // Set up the simulation
  double dt = 3600;
  int nsteps = 100000;

  // Run the simulation
  for (int i = 0; i < nsteps; i++) {
    // Calculate the gravitational force on each body
    double fx_sun = -G * sun.mass * earth.mass / pow(earth.x - sun.x, 3) * (earth.x - sun.x);
    double fy_sun = -G * sun.mass * earth.mass / pow(earth.y - sun.y, 3) * (earth.y - sun.y);
    double fz_sun = -G * sun.mass * earth.mass / pow(earth.z - sun.z, 3) * (earth.z - sun.z);
    double fx_earth = -G * earth.mass * moon.mass / pow(moon.x - earth.x, 3) * (moon.x - earth.x);
    double fy_earth = -G * earth.mass * moon.mass / pow(moon.y - earth.y, 3) * (moon.y - earth.y);
    double fz_earth = -G * earth.mass * moon.mass / pow(moon.z - earth.z, 3) * (moon.z - earth.z);

    // Update the velocities of each body
    earth.vx += dt * fx_sun / earth.mass;
    earth.vy += dt * fy_sun / earth.mass;
    earth.vz += dt * fz_sun / earth.mass;
    moon.vx += dt * fx_earth / moon.mass;
    moon.vy += dt * fy_earth / moon.mass;
    moon.vz += dt * fz_earth / moon.mass;

    // Update the positions of each body
    earth.x += dt * earth.vx;
    earth.y += dt * earth.vy;
    earth.z += dt * earth.vz;
    moon.x += dt * moon.vx;
    moon.y += dt * moon.vy;
    moon.z += dt * moon.vz;
  }

  // Print the final positions of the bodies
  printf("Sun: %.2e, %.2e, %.2e\n", sun.x, sun.y, sun.z);
  printf("Earth: %.2e, %.2e, %.2e\n", earth.x, earth.y, earth.z);
  printf("Moon: %.2e, %.2e, %.2e\n", moon.x, moon.y, moon.z);

  return 0;
}