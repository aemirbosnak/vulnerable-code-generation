//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: ephemeral
#include <stdio.h>

#define NUM_PLANETS 5
#define G_CONST 6.6743e-11

struct planet {
  char name[50];
  double mass;
  double x, y, z;
  double vx, vy, vz;
};

void calcGravity(struct planet *p1, struct planet *p2, double *fx, double *fy, double *fz) {
  // Calculate the force of gravity between two planets
  double distance, force;

  distance = sqrt(pow(p1->x - p2->x, 2) + pow(p1->y - p2->y, 2) + pow(p1->z - p2->z, 2));
  force = G_CONST * p1->mass * p2->mass / pow(distance, 2);

  *fx = force * (p2->x - p1->x) / distance;
  *fy = force * (p2->y - p1->y) / distance;
  *fz = force * (p2->z - p1->z) / distance;
}

void updatePositions(struct planet planets[NUM_PLANETS], double timestep) {
  // Update the positions and velocities of all the planets
  int i, j;
  double fx, fy, fz;

  for (i = 0; i < NUM_PLANETS; i++) {
    for (j = 0; j < NUM_PLANETS; j++) {
      if (i == j) {
        continue;
      }

      calcGravity(&planets[i], &planets[j], &fx, &fy, &fz);

      planets[i].vx += fx / planets[i].mass * timestep;
      planets[i].vy += fy / planets[i].mass * timestep;
      planets[i].vz += fz / planets[i].mass * timestep;

      planets[i].x += planets[i].vx * timestep;
      planets[i].y += planets[i].vy * timestep;
      planets[i].z += planets[i].vz * timestep;
    }
  }
}

void printPlanets(struct planet planets[NUM_PLANETS]) {
  // Print the positions and velocities of all the planets
  int i;

  for (i = 0; i < NUM_PLANETS; i++) {
    printf("%s: (%lf, %lf, %lf)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    printf("Velocity: (%lf, %lf, %lf)\n\n", planets[i].vx, planets[i].vy, planets[i].vz);
  }
}

int main() {
  struct planet planets[NUM_PLANETS] = {
    {"Mercury", 3.285e23, 0.3871e11, 0.0, 0.0, 0.0, 47.872e3, 0.0},
    {"Venus", 4.867e24, 0.7233e11, 0.0, 0.0, 0.0, 35.02e3, 0.0},
    {"Earth", 5.972e24, 1.0e11, 0.0, 0.0, 0.0, 29.78e3, 0.0},
    {"Mars", 6.39e23, 1.524e11, 0.0, 0.0, 0.0, 24.077e3, 0.0},
    {"Jupiter", 1.898e27, 5.203e11, 0.0, 0.0, 0.0, 13.07e3, 0.0}
  };

  double timestep = 3600;

  int i;
  for (i = 0; i < 10; i++) {
    printf("After %d hours:\n", i);
    updatePositions(planets, timestep);
    printPlanets(planets);
  }

  return 0;
}