//Code Llama-13B DATASET v1.0 Category: Planet Gravity Simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.67408e-11
#define PI 3.14159

struct Planet {
  double mass;
  double radius;
  double x;
  double y;
  double vx;
  double vy;
};

void simulate_gravity(struct Planet *planets, int num_planets) {
  for (int i = 0; i < num_planets; i++) {
    for (int j = i + 1; j < num_planets; j++) {
      double dx = planets[j].x - planets[i].x;
      double dy = planets[j].y - planets[i].y;
      double dist = sqrt(dx * dx + dy * dy);
      double force = G * planets[i].mass * planets[j].mass / (dist * dist);
      double ax = force * dx / dist;
      double ay = force * dy / dist;
      planets[i].vx += ax;
      planets[i].vy += ay;
      planets[j].vx -= ax;
      planets[j].vy -= ay;
    }
  }
}

int main() {
  struct Planet planets[3] = {
    { 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 },
    { 0.5, 1.5, 0.0, 0.0, 0.0, 0.0 },
    { 0.1, 2.0, 0.0, 0.0, 0.0, 0.0 }
  };

  int num_planets = 3;

  for (int i = 0; i < 1000; i++) {
    simulate_gravity(planets, num_planets);
    for (int j = 0; j < num_planets; j++) {
      planets[j].x += planets[j].vx;
      planets[j].y += planets[j].vy;
    }
  }

  for (int i = 0; i < num_planets; i++) {
    printf("%f %f\n", planets[i].x, planets[i].y);
  }

  return 0;
}