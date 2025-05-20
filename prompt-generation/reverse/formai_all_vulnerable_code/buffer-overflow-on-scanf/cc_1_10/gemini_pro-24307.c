//GEMINI-pro DATASET v1.0 Category: Planet Gravity Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double mass;
  double x;
  double y;
  double vx;
  double vy;
} Planet;

int main() {
  int n;
  scanf("%d", &n);

  Planet *planets = malloc(n * sizeof(Planet));
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf %lf %lf %lf", &planets[i].mass, &planets[i].x, &planets[i].y, &planets[i].vx, &planets[i].vy);
  }

  double dt = 0.01;
  for (int t = 0; t < 1000; t++) {
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        double dx = planets[i].x - planets[j].x;
        double dy = planets[i].y - planets[j].y;
        double r = sqrt(dx * dx + dy * dy);

        double F = planets[i].mass * planets[j].mass / (r * r);
        double Fx = F * dx / r;
        double Fy = F * dy / r;

        planets[i].vx += Fx * dt / planets[i].mass;
        planets[i].vy += Fy * dt / planets[i].mass;
        planets[j].vx -= Fx * dt / planets[j].mass;
        planets[j].vy -= Fy * dt / planets[j].mass;
      }
    }

    for (int i = 0; i < n; i++) {
      planets[i].x += planets[i].vx * dt;
      planets[i].y += planets[i].vy * dt;
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%lf %lf\n", planets[i].x, planets[i].y);
  }

  free(planets);
  return 0;
}