//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NUM_PLANETS 5

typedef struct Planet {
  char name[20];
  double mass;
  double x, y, z;
  double vx, vy, vz;
} Planet;

Planet planets[NUM_PLANETS] = {
  {"Sun", 1e30, 0, 0, 0, 0, 0},
  {"Earth", 5.972e24, 1.518e11, 0, 0, 0, 0},
  {"Mars", 0.643e24, 2.48e11, 0, 0, 0, 0},
  {"Jupiter", 5.972e24, 5.20e11, 0, 0, 0, 0},
  {"Saturn", 5.972e24, 9.54e11, 0, 0, 0, 0}
};

double calculate_force(double mass1, double mass2, double distance) {
  return (6.674e-11 * mass1 * mass2) / distance;
}

void update_positions(double dt) {
  for (int i = 0; i < NUM_PLANETS; i++) {
    double acceleration_x = calculate_force(planets[i].mass, planets[0].mass, planets[i].x - planets[0].x) * dt;
    double acceleration_y = calculate_force(planets[i].mass, planets[0].mass, planets[i].y - planets[0].y) * dt;
    double acceleration_z = calculate_force(planets[i].mass, planets[0].mass, planets[i].z - planets[0].z) * dt;

    planets[i].vx += acceleration_x * dt;
    planets[i].vy += acceleration_y * dt;
    planets[i].vz += acceleration_z * dt;

    planets[i].x += planets[i].vx * dt;
    planets[i].y += planets[i].vy * dt;
    planets[i].z += planets[i].vz * dt;
  }
}

int main() {
  double dt = 0.01;
  int num_steps = 100000;

  for (int i = 0; i < num_steps; i++) {
    update_positions(dt);
  }

  for (int i = 0; i < NUM_PLANETS; i++) {
    printf("%s's position: (%.2lf, %.2lf, %.2lf)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
  }

  return 0;
}