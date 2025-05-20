//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: scalable
#include <stdio.h>
#include <math.h>

#define GRAVITY_CONST 6.674E-11 

struct Planet {
  char* name;
  double mass;
  double radius;
  double position_x;
  double position_y;
  double velocity_x;
  double velocity_y;
  double acceleration_x;
  double acceleration_y;
};

struct Planet planets[] = {
  {"Earth", 5.972E24, 6.371E6, 0, 0, 0, 0, 0, 0},
  {"Mars", 6.39E23, 3.38E6, 2.279E11, 0, 0, 24082, 0, 0},
  {"Saturn", 5.683E26, 6.0268E7, 1.4294E12, 0, 0, 9650, 0, 0},
  {"Jupiter", 1.898E27, 6.9911E7, 7.785472E11, 0, 0, 13720, 0, 0},
};

int num_planets = sizeof(planets) / sizeof(struct Planet);

void update_acceleration(struct Planet *p1, struct Planet *p2) {
  double distance_squared = pow(p1->position_x - p2->position_x, 2) + pow(p1->position_y - p2->position_y, 2);
  double force = GRAVITY_CONST * p1->mass * p2->mass / distance_squared;
  double angle = atan2(p2->position_y - p1->position_y, p2->position_x - p1->position_x);
  p1->acceleration_x += force * cos(angle) / p1->mass;
  p1->acceleration_y += force * sin(angle) / p1->mass;
}

void update_velocity_and_position(struct Planet *p, double dt) {
  p->velocity_x += p->acceleration_x * dt;
  p->velocity_y += p->acceleration_y * dt;
  p->position_x += p->velocity_x * dt;
  p->position_y += p->velocity_y * dt;
}

int main() {
  
  double dt = 86400;  // 1 day in seconds
  
  int num_years = 10;
  int num_steps = num_years * 365;
  
  for (int step = 0; step < num_steps; step++) {
    // reset accelerations
    for (int i = 0; i < num_planets; i++) {
      planets[i].acceleration_x = 0;
      planets[i].acceleration_y = 0;
    }
    // calculate accelerations
    for (int i = 0; i < num_planets; i++) {
      for (int j = i + 1; j < num_planets; j++) {
        update_acceleration(&planets[i], &planets[j]);
        update_acceleration(&planets[j], &planets[i]);
      }
    }
    // update velocities and positions
    for (int i = 0; i < num_planets; i++) {
      update_velocity_and_position(&planets[i], dt);
    }
    // output planet positions
    printf("Step %d:\n", step);
    for (int i = 0; i < num_planets; i++) {
      printf("%s position (x, y): %e, %e\n", planets[i].name, planets[i].position_x, planets[i].position_y);
    }
  }
  
  return 0;
}