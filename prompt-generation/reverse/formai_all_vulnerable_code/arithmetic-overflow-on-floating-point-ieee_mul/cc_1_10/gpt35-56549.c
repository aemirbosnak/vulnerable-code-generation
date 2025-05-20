//FormAI DATASET v1.0 Category: Simulation of the Solar System ; Style: mind-bending
#include <stdio.h>
#include <stdint.h>

#define G 6.674 * pow(10, -11)

typedef struct {
  double x;
  double y;
} Vector;

typedef struct {
  char name[20];
  double mass;
  Vector position;
  Vector velocity;
} Body;

void calculate_forces(Body bodies[], int n) {
  for (int i = 0; i < n; i++) {
    Vector net_force = {0, 0};
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      double delta_x = bodies[j].position.x - bodies[i].position.x;
      double delta_y = bodies[j].position.y - bodies[i].position.y;
      double r_squared = (delta_x * delta_x) + (delta_y * delta_y);
      double force_magnitude = (G * bodies[i].mass * bodies[j].mass) / r_squared;
      double force_x = (force_magnitude * delta_x) / sqrt(r_squared);
      double force_y = (force_magnitude * delta_y) / sqrt(r_squared);
      Vector force = {force_x, force_y};
      net_force.x += force.x;
      net_force.y += force.y;
    }
    printf("Net force on %s: (%f, %f)\n", bodies[i].name, net_force.x, net_force.y);
  }
}

int main() {
  Body sun = {"Sun", 1.989 * pow(10, 20), {0, 0}, {0, 0}};
  Body earth = {"Earth", 5.972 * pow(10, 14), {147093162.4 * 1000, 0}, {0, 30330}};
  Body moon = {"Moon", 7.342 * pow(10, 12), {147093162.4 * 1000 + 384400 * 1000, 0}, {0, 30330 + 1023}};

  Body bodies[] = {sun, earth, moon};
  int n = 3;

  printf("Initial positions:\n");
  for (int i = 0; i < n; i++) {
    printf("%s: (%f, %f)\n", bodies[i].name, bodies[i].position.x, bodies[i].position.y);
  }

  for (int i = 0; i < 1000000; i++) {
    calculate_forces(bodies, n);
    for (int j = 0; j < n; j++) {
      Vector acceleration = {bodies[j].velocity.x / i, bodies[j].velocity.y / i};
      bodies[j].position.x += bodies[j].velocity.x + 0.5 * acceleration.x * i * i;
      bodies[j].position.y += bodies[j].velocity.y + 0.5 * acceleration.y * i * i;
    }
  }

  printf("Final positions:\n");
  for (int i = 0; i < n; i++) {
    printf("%s: (%f, %f)\n", bodies[i].name, bodies[i].position.x, bodies[i].position.y);
  }

  return 0;
}