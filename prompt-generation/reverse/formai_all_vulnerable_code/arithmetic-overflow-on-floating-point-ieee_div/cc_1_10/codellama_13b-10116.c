//Code Llama-13B DATASET v1.0 Category: Simulation of the Solar System ; Style: modular
// solarsystem.c

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// constants
#define G 6.67408e-11
#define AU 149597890
#define EARTH_MASS 5.97237e24
#define SUN_MASS 1.9891e30

// structs
typedef struct {
  double x, y, z;
} vector_t;

typedef struct {
  double mass, radius;
  vector_t pos, vel;
} planet_t;

// functions
void init_planet(planet_t *planet, double mass, double radius, double x, double y, double z, double vx, double vy, double vz) {
  planet->mass = mass;
  planet->radius = radius;
  planet->pos.x = x;
  planet->pos.y = y;
  planet->pos.z = z;
  planet->vel.x = vx;
  planet->vel.y = vy;
  planet->vel.z = vz;
}

double distance(planet_t *p1, planet_t *p2) {
  double dx = p2->pos.x - p1->pos.x;
  double dy = p2->pos.y - p1->pos.y;
  double dz = p2->pos.z - p1->pos.z;
  return sqrt(dx*dx + dy*dy + dz*dz);
}

double force(planet_t *p1, planet_t *p2) {
  double r = distance(p1, p2);
  return G * p1->mass * p2->mass / (r * r);
}

void simulate(planet_t *planets, int num_planets, double time) {
  // calculate accelerations
  for (int i = 0; i < num_planets; i++) {
    for (int j = 0; j < num_planets; j++) {
      if (i != j) {
        double accel = force(&planets[i], &planets[j]) / planets[i].mass;
        planets[i].vel.x += accel * planets[j].pos.x * time;
        planets[i].vel.y += accel * planets[j].pos.y * time;
        planets[i].vel.z += accel * planets[j].pos.z * time;
      }
    }
  }

  // update positions
  for (int i = 0; i < num_planets; i++) {
    planets[i].pos.x += planets[i].vel.x * time;
    planets[i].pos.y += planets[i].vel.y * time;
    planets[i].pos.z += planets[i].vel.z * time;
  }
}

int main() {
  planet_t planets[] = {
    {EARTH_MASS, 6371, 0, 0, 0, 0, 0, 29.78, 0},
    {SUN_MASS, 0, 0, 0, 0, 0, 0, 0, 0}
  };

  int num_planets = sizeof(planets) / sizeof(planet_t);
  double time = 1;

  simulate(planets, num_planets, time);

  for (int i = 0; i < num_planets; i++) {
    printf("Planet %d:\n", i);
    printf("  x = %f\n", planets[i].pos.x);
    printf("  y = %f\n", planets[i].pos.y);
    printf("  z = %f\n", planets[i].pos.z);
    printf("  vx = %f\n", planets[i].vel.x);
    printf("  vy = %f\n", planets[i].vel.y);
    printf("  vz = %f\n", planets[i].vel.z);
  }

  return 0;
}