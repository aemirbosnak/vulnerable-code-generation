//FormAI DATASET v1.0 Category: Planet Gravity Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_OBJECTS 10
#define TIME_STEP 1
#define G_CONSTANT 6.6743e-11

typedef struct Object {
  double mass;
  double x;
  double y;
  double vx;
  double vy;
} Object;

void calculate_gravity(Object *o1, Object *o2, double *fx, double *fy) {
  double distance = sqrt(pow(o1->x - o2->x, 2) + pow(o1->y - o2->y, 2));
  double force = G_CONSTANT * o1->mass * o2->mass / pow(distance, 2);
  *fx = force * (o1->x - o2->x) / distance;
  *fy = force * (o1->y - o2->y) / distance;
}

void update_objects(Object *objects, int n) {
  double forces_x[MAX_OBJECTS] = {0}, forces_y[MAX_OBJECTS] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      double fx, fy;
      calculate_gravity(&objects[i], &objects[j], &fx, &fy);
      forces_x[i] -= fx;
      forces_y[i] -= fy;
    }
  }
  for (int i = 0; i < n; i++) {
    double ax = forces_x[i] / objects[i].mass;
    double ay = forces_y[i] / objects[i].mass;
    objects[i].vx += ax * TIME_STEP;
    objects[i].vy += ay * TIME_STEP;
    objects[i].x += objects[i].vx * TIME_STEP;
    objects[i].y += objects[i].vy * TIME_STEP;
  }
}

int main() {
  Object objects[MAX_OBJECTS];
  int n;
  printf("Enter number of objects: ");
  scanf("%d", &n);
  if (n > MAX_OBJECTS) {
    printf("Error: Too many objects");
    exit(1);
  }
  for (int i = 0; i < n; i++) {
    printf("Enter mass, x, y, vx, vy of object %d: ", i + 1);
    scanf("%lf %lf %lf %lf %lf", &objects[i].mass, &objects[i].x, &objects[i].y, &objects[i].vx, &objects[i].vy);
  }
  printf("\nSimulation started...\n\n");
  for (int i = 0; i < 10000; i++) {
    update_objects(objects, n);
    printf("Step %d:\n", i + 1);
    for (int j = 0; j < n; j++) {
      printf("Object %d: (%f, %f)\n", j + 1, objects[j].x, objects[j].y);
    }
    printf("\n");
  }
  printf("Simulation ended");
  return 0;
}