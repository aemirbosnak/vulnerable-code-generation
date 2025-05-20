//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: active
#include <stdio.h>
#include <math.h>

#define G 6.674e-11 // gravitational constant
#define DT 0.01 // time step

typedef struct Vector { // 2D vector struct
  double x;
  double y;
} Vector;

typedef struct Planet {
  char *name;
  double mass;
  double radius;
  Vector pos;
  Vector vel;
  Vector acc;
} Planet;

void init_planet(Planet *planet, char *name, double mass, double radius, double x, double y, double vx, double vy) {
  planet->name = name;
  planet->mass = mass;
  planet->radius = radius;
  planet->pos.x = x;
  planet->pos.y = y;
  planet->vel.x = vx;
  planet->vel.y = vy;
}

void update_acc(Planet *planet, double fx, double fy) {
  planet->acc.x = fx / planet->mass;
  planet->acc.y = fy / planet->mass;
}

void update_vel(Planet *planet) {
  planet->vel.x += planet->acc.x * DT;
  planet->vel.y += planet->acc.y * DT;
}

void update_pos(Planet *planet) {
  planet->pos.x += planet->vel.x * DT;
  planet->pos.y += planet->vel.y * DT;
}

double calc_distance(Planet *p1, Planet *p2) {
  double dx = p1->pos.x - p2->pos.x;
  double dy = p1->pos.y - p2->pos.y;
  return sqrt(dx * dx + dy * dy);
}

void calc_force(Planet *p1, Planet *p2, double *fx, double *fy) {
  double dist = calc_distance(p1, p2);
  double force = G * p1->mass * p2->mass / (dist * dist);
  double dx = p2->pos.x - p1->pos.x;
  double dy = p2->pos.y - p1->pos.y;
  *fx = force * dx / dist;
  *fy = force * dy / dist;
}

void update_system(Planet *planets, int num_planets) {
  int i, j;
  double fx, fy;

  for (i = 0; i < num_planets; i++) {
    fx = fy = 0;
    for (j = 0; j < num_planets; j++) {
      if (i != j) {
        double temp_fx, temp_fy;
        calc_force(&planets[i], &planets[j], &temp_fx, &temp_fy);
        fx += temp_fx;
        fy += temp_fy;
      }
    }
    update_acc(&planets[i], fx, fy);
  }

  for (i = 0; i < num_planets; i++) {
    update_vel(&planets[i]);
    update_pos(&planets[i]);
  }
}

int main() {
  Planet planets[3];

  init_planet(&planets[0], "Earth", 5.97e24, 6.37e6, 0, 0, 0, 0);
  init_planet(&planets[1], "Moon", 7.35e22, 1.74e6, 3.84e8, 0, 0, 1022);
  init_planet(&planets[2], "Sun", 1.99e30, 6.96e8, 0, 0, 0, 0);

  int i;
  for (i = 0; i < 10000; i++) {
    update_system(planets, 3);
    printf("%f, %f, %f\n", planets[0].pos.x, planets[0].pos.y, planets[0].vel.y);
  }

  return 0;
}