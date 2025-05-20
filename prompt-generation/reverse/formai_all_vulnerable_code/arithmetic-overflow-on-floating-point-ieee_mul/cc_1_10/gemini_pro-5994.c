//GEMINI-pro DATASET v1.0 Category: Procedural Space Adventure ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  double x, y;
} point;

typedef struct {
  point pos;
  double radius;
} circle;

typedef struct {
  point pos;
  double width, height;
} rect;

typedef union {
  circle c;
  rect r;
} shape;

void draw_shape(shape s) {
  if (s.c.radius > 0) {
    printf("Drawing circle at (%.2f, %.2f) with radius %.2f\n", s.c.pos.x, s.c.pos.y, s.c.radius);
  } else {
    printf("Drawing rectangle at (%.2f, %.2f) with width %.2f and height %.2f\n", s.r.pos.x, s.r.pos.y, s.r.width, s.r.height);
  }
}

void shift_shape(shape *s, double dx, double dy) {
  s->c.pos.x += dx;
  s->c.pos.y += dy;
  s->r.pos.x += dx;
  s->r.pos.y += dy;
}

void scale_shape(shape *s, double factor) {
  s->c.radius *= factor;
  s->r.width *= factor;
  s->r.height *= factor;
}

int main() {
  srand(time(NULL));

  shape s;

  s.c.pos.x = rand() % 100;
  s.c.pos.y = rand() % 100;
  s.c.radius = rand() % 50;

  draw_shape(s);

  shift_shape(&s, 10, 10);

  draw_shape(s);

  scale_shape(&s, 1.5);

  draw_shape(s);

  return 0;
}