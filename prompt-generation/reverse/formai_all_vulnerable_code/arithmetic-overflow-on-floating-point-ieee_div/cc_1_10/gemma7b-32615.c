//Gemma-7B DATASET v1.0 Category: Planet Gravity Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

#define G 6.674e-11

typedef struct CelestialObject {
  char name[20];
  double mass;
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
} CelestialObject;

CelestialObject objects[] = {
  {"Sun", 1e30, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
  {"Earth", 5.97e24, -1.5e11, 0.0, 0.0, 0.0, 0.0, 0.0, -2.98e3}
};

void update_positions(void) {
  double t = 0.0;
  double dt = 0.01;
  for (int i = 0; i < 2; i++) {
    double ax_x = G * objects[i].mass * objects[0].mass / (objects[i].x - objects[0].x) * dt * dt;
    double ax_y = G * objects[i].mass * objects[0].mass / (objects[i].y - objects[0].y) * dt * dt;
    double ax_z = G * objects[i].mass * objects[0].mass / (objects[i].z - objects[0].z) * dt * dt;
    objects[i].vx += ax_x * dt;
    objects[i].vy += ax_y * dt;
    objects[i].vz += ax_z * dt;
    objects[i].x += objects[i].vx * dt;
    objects[i].y += objects[i].vy * dt;
    objects[i].z += objects[i].vz * dt;
  }
}

void print_positions(void) {
  for (int i = 0; i < 2; i++) {
    printf("%s position: (%.2f, %.2f, %.2f)\n", objects[i].name, objects[i].x, objects[i].y, objects[i].z);
  }
}

int main() {
  update_positions();
  print_positions();

  return 0;
}