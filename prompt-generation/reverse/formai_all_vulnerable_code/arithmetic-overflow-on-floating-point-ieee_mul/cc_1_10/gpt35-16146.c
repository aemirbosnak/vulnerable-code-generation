//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 3
#define G 6.674e-11

struct planet {
  double mass;
  double radius;
  double position[DIM];
  double velocity[DIM];
  double acceleration[DIM];
};

struct planet planets[3];

double distance(double *r1, double *r2) {
  double dist = 0;
  for (int i = 0; i < DIM; i++) {
    dist += pow((r1[i] - r2[i]), 2);
  }
  return sqrt(dist);
}

void calc_acceleration(struct planet *p1, struct planet *p2) {
  double r_vector[DIM];
  double r = distance(p1->position, p2->position);
  for (int i = 0; i < DIM; i++) {
    r_vector[i] = p2->position[i] - p1->position[i];
  }
  double force_mag = G * p1->mass * p2->mass / pow(r, 2);
  for (int i = 0; i < DIM; i++) {
    p2->acceleration[i] -= r_vector[i] * force_mag / p2->mass;
    p1->acceleration[i] += r_vector[i] * force_mag / p1->mass;
  }
}

void update_positions(struct planet *p, double dt) {
  for (int i = 0; i < DIM; i++) {
    p->position[i] += p->velocity[i] * dt + 0.5 * p->acceleration[i] * pow(dt, 2);
  }
}

void update_velocities(struct planet *p, double dt) {
  for (int i = 0; i < DIM; i++) {
    p->velocity[i] += 0.5 * (p->acceleration[i] + p->acceleration[i] + p->acceleration[i]) * dt;
  }
}

int main() {
  planets[0].mass = 5.97e24;
  planets[0].radius = 6400e3;
  planets[0].position[0] = 0;
  planets[0].position[1] = 0;
  planets[0].position[2] = 0;
  planets[0].velocity[0] = 0;
  planets[0].velocity[1] = 0;
  planets[0].velocity[2] = 0;
  planets[0].acceleration[0] = 0;
  planets[0].acceleration[1] = 0;
  planets[0].acceleration[2] = 0;

  planets[1].mass = 7.34e22;
  planets[1].radius = 1737e3;
  planets[1].position[0] = 384400e3;
  planets[1].position[1] = 0;
  planets[1].position[2] = 0;
  planets[1].velocity[0] = 0;
  planets[1].velocity[1] = 1022;
  planets[1].velocity[2] = 0;
  planets[1].acceleration[0] = 0;
  planets[1].acceleration[1] = 0;
  planets[1].acceleration[2] = 0;

  planets[2].mass = 1898.19e24;
  planets[2].radius = 71492e3;
  planets[2].position[0] = 0;
  planets[2].position[1] = 778500000000;
  planets[2].position[2] = 0;
  planets[2].velocity[0] = 47262;
  planets[2].velocity[1] = 0;
  planets[2].velocity[2] = 0;
  planets[2].acceleration[0] = 0;
  planets[2].acceleration[1] = 0;
  planets[2].acceleration[2] = 0;

  double time = 0;
  double dt = 1000;
  double total_time = 31536000e5;  // 100 years
  int steps = (int)(total_time / dt);

  printf("Simulating planet gravity...\n");

  for (int i = 0; i < steps; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        if (j != k) {
          calc_acceleration(&planets[j], &planets[k]);
        }
      }
    }
    for (int j = 0; j < 3; j++) {
      update_positions(&planets[j], dt);
      update_velocities(&planets[j], dt);
    }
    time += dt;
  }

  printf("Simulation complete!\n");
}