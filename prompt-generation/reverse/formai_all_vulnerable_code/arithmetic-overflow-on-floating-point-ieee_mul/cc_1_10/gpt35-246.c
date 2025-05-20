//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.6743e-11 // gravitational constant
#define DELTA_T 86400 // one day timestep for simulation
#define NUM_PLANETS 4 // number of planets in system

struct planet {
   char name[20];
   double mass;
   double x_pos;
   double y_pos;
   double x_vel;
   double y_vel;
};

void update_position(struct planet *p, double force_x, double force_y) {
   double accel_x = force_x / p->mass;
   double accel_y = force_y / p->mass;
   p->x_vel += accel_x * DELTA_T;
   p->y_vel += accel_y * DELTA_T;
   p->x_pos += p->x_vel * DELTA_T;
   p->y_pos += p->y_vel * DELTA_T;
}

int main() {
   struct planet planets[NUM_PLANETS] = {
                             {"Earth", 5.97e24, 0.0, 0.0, 0.0, 0.0},
                             {"Mars", 6.39e23, 2.27e11, 0.0, 0.0, 24080.0},
                             {"Venus", 4.87e24, 1.08e11, 0.0, 0.0, 35020.0},
                             {"Jupiter", 1.90e27, 0.0, 7.78e11, 13070.0, 0.0}
                            };
   double force_x, force_y, distance;
   int i, j, t;

   printf("Simulating gravity in a solar system...\n");
   for (t = 0; t < 365; t++) {
      for (i = 0; i < NUM_PLANETS; i++) {
         force_x = 0.0;
         force_y = 0.0;
         for (j = 0; j < NUM_PLANETS; j++) {
            if (i == j) continue;
            distance = sqrt(pow(planets[i].x_pos - planets[j].x_pos, 2) +
                            pow(planets[i].y_pos - planets[j].y_pos, 2));
            double force = G * planets[i].mass * planets[j].mass / pow(distance, 2);
            force_x += force * (planets[j].x_pos - planets[i].x_pos) / distance;
            force_y += force * (planets[j].y_pos - planets[i].y_pos) / distance;
         }
         update_position(&planets[i], force_x, force_y);
      }
   }

   printf("Final positions:\n");
   for (i = 0; i < NUM_PLANETS; i++) {
      printf("%s: x = %f km, y = %f km\n", planets[i].name,
             planets[i].x_pos / 1e9, planets[i].y_pos / 1e9);
   }
   return 0;
}