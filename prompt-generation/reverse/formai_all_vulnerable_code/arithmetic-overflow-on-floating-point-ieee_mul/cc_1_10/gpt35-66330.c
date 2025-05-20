//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: expert-level
#include <stdio.h>
#include <math.h>

#define G 6.67e-11 // Gravitational constant
#define N 3 // Number of planets
#define MAX_STEPS 10000 // Maximum simulation steps

// Define planet properties
struct Planet {
  char name[10];
  double mass;
  double radius;
  double x;
  double y;
  double z;
  double vx;
  double vy;
  double vz;
};

// Define initial conditions
struct Planet planets[N] = {
  {"Earth", 5.97e24, 6371e3, 0, 0, 0, 0, 0, 0},
  {"Mars", 6.42e23, 3390e3, 228e9, 0, 0, 0, 24090, 0},
  {"Jupiter", 1.9e27, 69911e3, 778e9, 0, 0, 0, 13068, 0}
};

// Calculate distance between two planets
double distance(double x1, double y1, double z1, double x2, double y2, double z2) {
  return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2) + pow((z2 - z1), 2));
}

// Calculate gravitational force between two planets
double force(double m1, double m2, double r) {
  return G * m1 * m2 / pow(r, 2);
}

int main() {
  // Simulation parameters
  double dt = 86400; // Time step in seconds
  int steps = 0; // Simulation steps

  // Run simulation loop
  while (steps < MAX_STEPS) {
    // Calculate forces acting on each planet
    double fx[N] = {0};
    double fy[N] = {0};
    double fz[N] = {0};

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i != j) {
          double r = distance(planets[i].x, planets[i].y, planets[i].z, planets[j].x, planets[j].y, planets[j].z);
          double f = force(planets[i].mass, planets[j].mass, r);

          fx[i] += f * (planets[j].x - planets[i].x) / r;
          fy[i] += f * (planets[j].y - planets[i].y) / r;
          fz[i] += f * (planets[j].z - planets[i].z) / r;
        }
      }
    }

    // Update planet positions and velocities using forces
    for (int i = 0; i < N; i++) {
      double ax = fx[i] / planets[i].mass;
      double ay = fy[i] / planets[i].mass;
      double az = fz[i] / planets[i].mass;

      planets[i].vx += ax * dt;
      planets[i].vy += ay * dt;
      planets[i].vz += az * dt;

      planets[i].x += planets[i].vx * dt;
      planets[i].y += planets[i].vy * dt;
      planets[i].z += planets[i].vz * dt;
    }

    // Print planet positions
    printf("Step %d:\n", steps);
    for (int i = 0; i < N; i++) {
      printf("%s: (%e, %e, %e)\n", planets[i].name, planets[i].x, planets[i].y, planets[i].z);
    }

    steps++;
  }

  return 0;
}