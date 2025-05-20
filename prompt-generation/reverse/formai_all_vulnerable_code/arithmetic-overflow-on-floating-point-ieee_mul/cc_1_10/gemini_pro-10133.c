//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 0.00000001

typedef struct point {
  double x, y;
} point;

typedef struct line {
  point p1, p2;
} line;

typedef struct circle {
  point c;
  double r;
} circle;

int equal(double a, double b) {
  return fabs(a - b) < EPSILON;
}

int point_inside_circle(circle *c, point *p) {
  return equal(pow(p->x - c->c.x, 2) + pow(p->y - c->c.y, 2), pow(c->r, 2));
}

point line_intersection(line *l1, line *l2) {
  double x1 = l1->p1.x, y1 = l1->p1.y, x2 = l1->p2.x, y2 = l1->p2.y;
  double x3 = l2->p1.x, y3 = l2->p1.y, x4 = l2->p2.x, y4 = l2->p2.y;
  double d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
  if (equal(d, 0))
    return (point){-1, -1};
  double xi = ((x3 - x4) * (x1 * y2 - y1 * x2) - (x1 - x2) * (x3 * y4 - y3 * x4)) / d;
  double yi = ((y3 - y4) * (x1 * y2 - y1 * x2) - (y1 - y2) * (x3 * y4 - y3 * x4)) / d;
  return (point){xi, yi};
}

int main() {
  circle c = {{0, 0}, 5};
  line l1 = {{0, -5}, {0, 5}};
  line l2 = {{-5, 0}, {5, 0}};
  point ip = line_intersection(&l1, &l2);
  if (ip.x == -1 && ip.y == -1)
    printf("No point of intersection\n");
  else if (point_inside_circle(&c, &ip))
    printf("Point of intersection is inside the circle\n");
  else
    printf("Point of intersection is outside the circle\n");
  return 0;
}