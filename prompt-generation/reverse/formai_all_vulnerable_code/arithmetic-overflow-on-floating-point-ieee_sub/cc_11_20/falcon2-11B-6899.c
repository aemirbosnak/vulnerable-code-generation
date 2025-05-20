//Falcon2-11B DATASET v1.0 Category: Physics simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265358979323846

struct object {
  double x;
  double y;
  double vx;
  double vy;
  double m;
};

int main() {
  struct object *objects[3];
  objects[0] = malloc(sizeof(struct object));
  objects[1] = malloc(sizeof(struct object));
  objects[2] = malloc(sizeof(struct object));

  objects[0]->x = 0;
  objects[0]->y = 0;
  objects[0]->vx = 1;
  objects[0]->vy = 0;
  objects[0]->m = 1;

  objects[1]->x = 10;
  objects[1]->y = 0;
  objects[1]->vx = -1;
  objects[1]->vy = 0;
  objects[1]->m = 2;

  objects[2]->x = 0;
  objects[2]->y = 10;
  objects[2]->vx = 0;
  objects[2]->vy = -1;
  objects[2]->m = 3;

  double dt = 0.01;

  while (1) {
    for (int i = 0; i < 3; i++) {
      objects[i]->x += objects[i]->vx * dt;
      objects[i]->y += objects[i]->vy * dt;
      objects[i]->vx += (objects[i]->m / objects[i]->m) * (objects[i]->vx * objects[i]->vy - objects[i]->vy * objects[i]->vy);
      objects[i]->vy += (objects[i]->m / objects[i]->m) * (objects[i]->vx * objects[i]->vy - objects[i]->vy * objects[i]->vx);
    }
    printf("x: %.3f, y: %.3f\n", objects[0]->x, objects[0]->y);
    printf("x: %.3f, y: %.3f\n", objects[1]->x, objects[1]->y);
    printf("x: %.3f, y: %.3f\n", objects[2]->x, objects[2]->y);

    if (objects[0]->x < 0 || objects[0]->x > 20 || objects[0]->y < 0 || objects[0]->y > 20) {
      printf("Object 0 collided with walls!\n");
      break;
    }
    if (objects[1]->x < 0 || objects[1]->x > 20 || objects[1]->y < 0 || objects[1]->y > 20) {
      printf("Object 1 collided with walls!\n");
      break;
    }
    if (objects[2]->x < 0 || objects[2]->x > 20 || objects[2]->y < 0 || objects[2]->y > 20) {
      printf("Object 2 collided with walls!\n");
      break;
    }
  }

  free(objects[0]);
  free(objects[1]);
  free(objects[2]);

  return 0;
}