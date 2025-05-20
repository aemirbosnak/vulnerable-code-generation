//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define G 6.674e-11

typedef struct Planet {
  char name[20];
  double mass;
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
} Planet;

int main() {
  Planet earth = {"Earth", 5.972e24, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
  Planet sun = {"Sun", 1.989e30, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};

  double dt = 0.01;
  int nsteps = 100000;

  for (int i = 0; i < nsteps; i++) {
    double ax_earth = G * sun.mass * earth.mass / (earth.x - sun.x) * (earth.y - sun.y) / (earth.z - sun.z) * 1e-11;
    double ay_earth = G * sun.mass * earth.mass / (earth.x - sun.x) * (earth.y - sun.y) / (earth.z - sun.z) * 1e-11;
    double az_earth = G * sun.mass * earth.mass / (earth.x - sun.x) * (earth.y - sun.y) / (earth.z - sun.z) * 1e-11;

    double ax_sun = G * earth.mass * sun.mass / (sun.x - earth.x) * (sun.y - earth.y) / (sun.z - earth.z) * 1e-11;
    double ay_sun = G * earth.mass * sun.mass / (sun.x - earth.x) * (sun.y - earth.y) / (sun.z - earth.z) * 1e-11;
    double az_sun = G * earth.mass * sun.mass / (sun.x - earth.x) * (sun.y - earth.y) / (sun.z - earth.z) * 1e-11;

    earth.vx += ax_earth * dt;
    earth.vy += ay_earth * dt;
    earth.vz += az_earth * dt;

    sun.vx += ax_sun * dt;
    sun.vy += ay_sun * dt;
    sun.vz += az_sun * dt;

    earth.x += earth.vx * dt;
    earth.y += earth.vy * dt;
    earth.z += earth.vz * dt;

    sun.x += sun.vx * dt;
    sun.y += sun.vy * dt;
    sun.z += sun.vz * dt;
  }

  printf("Earth's position: (%f, %f, %f)\n", earth.x, earth.y, earth.z);
  printf("Sun's position: (%f, %f, %f)\n", sun.x, sun.y, sun.z);

  return 0;
}