//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.674e-11

typedef struct {
  double mass;
  double x;
  double y;
  double vx;
  double vy;
} Planet;

int main() {
  int num_planets;
  printf("Welcome to the most thrilling planet gravity simulation ever! How many planets are we playing with today? ");
  scanf("%d", &num_planets);

  Planet *planets = malloc(num_planets * sizeof(Planet));

  for (int i = 0; i < num_planets; i++) {
    printf("Planet %d:\n", i + 1);
    printf("Mass (kg): ");
    scanf("%lf", &planets[i].mass);
    printf("Initial x-position (m): ");
    scanf("%lf", &planets[i].x);
    printf("Initial y-position (m): ");
    scanf("%lf", &planets[i].y);
    printf("Initial x-velocity (m/s): ");
    scanf("%lf", &planets[i].vx);
    printf("Initial y-velocity (m/s): ");
    scanf("%lf", &planets[i].vy);
  }

  double t = 0.0;
  double dt = 0.001;

  while (1) {
    // Calculate the gravitational force between each pair of planets.
    for (int i = 0; i < num_planets; i++) {
      for (int j = i + 1; j < num_planets; j++) {
        double dx = planets[j].x - planets[i].x;
        double dy = planets[j].y - planets[i].y;
        double r = sqrt(dx * dx + dy * dy);
        double f = G * planets[i].mass * planets[j].mass / (r * r);
        double ax = f * dx / r;
        double ay = f * dy / r;
        planets[i].vx -= ax * dt;
        planets[i].vy -= ay * dt;
        planets[j].vx += ax * dt;
        planets[j].vy += ay * dt;
      }
    }

    // Update the positions and velocities of each planet.
    for (int i = 0; i < num_planets; i++) {
      planets[i].x += planets[i].vx * dt;
      planets[i].y += planets[i].vy * dt;
    }

    // Check if any planets have collided.
    for (int i = 0; i < num_planets; i++) {
      for (int j = i + 1; j < num_planets; j++) {
        double dx = planets[j].x - planets[i].x;
        double dy = planets[j].y - planets[i].y;
        double r = sqrt(dx * dx + dy * dy);
        if (r < planets[i].mass / 2 + planets[j].mass / 2) {
          printf("Collision detected between planets %d and %d!\n", i + 1, j + 1);
          return 0;
        }
      }
    }

    // Print the positions and velocities of each planet.
    printf("\nTime: %f\n", t);
    for (int i = 0; i < num_planets; i++) {
      printf("Planet %d: (x, y) = (%f, %f), (vx, vy) = (%f, %f)\n", i + 1, planets[i].x, planets[i].y, planets[i].vx, planets[i].vy);
    }

    t += dt;
  }

  return 0;
}