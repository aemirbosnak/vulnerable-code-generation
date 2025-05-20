//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define G 6.673e-11 // Gravitational Constant

typedef struct {
   double x, y; // position
   double vx, vy; // velocity
   double ax, ay; // acceleration
   double mass; // mass
} Object;

double distance(double x1, double y1, double x2, double y2) {
   return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void calculate_acceleration(Object *obj1, Object *obj2) {
   double r = distance(obj1->x, obj1->y, obj2->x, obj2->y);
   double f = (G * obj1->mass * obj2->mass) / pow(r, 2);
   double theta = atan2(obj2->y - obj1->y, obj2->x - obj1->x);
   obj1->ax += (f / obj1->mass) * cos(theta);
   obj1->ay += (f / obj1->mass) * sin(theta);
}

void update_velocity(Object *obj, double dt) {
   obj->vx += obj->ax * dt;
   obj->vy += obj->ay * dt;
   obj->ax = obj->ay = 0;
}

void update_position(Object *obj, double dt) {
   obj->x += obj->vx * dt;
   obj->y += obj->vy * dt;
}

int main() {
   Object objects[] = {
      {0, 0, 0, 0, 0, 0, 1e5}, // Large Star
      {100, 0, 0, 100, 0, 0, 1}, // Planet
   };
   int n = sizeof(objects) / sizeof(Object);

   double t = 0; // current time
   double dt = 1e3; // time step

   while (1) {
      for (int i = 0; i < n; i++) {
         for (int j = 0; j < n; j++) {
            if (i != j) {
               calculate_acceleration(&objects[i], &objects[j]);
            }
         }
      }

      for (int i = 0; i < n; i++) {
         update_velocity(&objects[i], dt);
         update_position(&objects[i], dt);
      }

      printf("t = %f\n", t);
      for (int i = 0; i < n; i++) {
         printf("Object %d: x = %f, y = %f\n", i+1, objects[i].x, objects[i].y);
      }
      printf("\n");

      t += dt;
   }

   return EXIT_SUCCESS;
}