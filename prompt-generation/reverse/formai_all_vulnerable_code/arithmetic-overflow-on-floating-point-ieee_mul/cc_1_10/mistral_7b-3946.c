//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct { double x, y; } point_t;
typedef struct { point_t p1, p2; } line_t;
typedef struct { point_t p; double angle, distance; } closest_point_t;

void print_point(point_t p) {
  printf("(%lf, %lf)", p.x, p.y);
}

void print_line(line_t l) {
  printf("Line: %s ->", "(" , &(l.p1).x > &(l.p2).x ? "(" : ")");
  print_point(l.p1);
  printf(" <- ");
  print_point(l.p2);
  printf(")");
}

void line_intersection(line_t a, line_t b, closest_point_t *res) {
  double a1 = a.p2.y - a.p1.y, b1 = b.p2.y - b.p1.y,
         c1 = a.p2.x - a.p1.x, d1 = b.p2.x - b.p1.x,
         det = a1 * d1 - b1 * c1;

  if (det == 0.0) { // parallel lines
    res->angle = NAN;
    res->distance = NAN;
  } else {
    double x = (b1 * a.p1.x - b.p1.x * a1 + c1 * a.p1.y - c1 * a.p1.y) / det;
    double y = (a1 * a.p1.x - a.p1.x * c1 + b1 * a.p1.y - b1 * a.p1.y) / det;

    res->p = (point_t){x, y};

    res->angle = atan2(fabs(a1), fabs(c1)) * (a1 > 0.0 ? 1.0 : -1.0);
    res->distance = sqrt(pow(res->p.x - (a.p1.x + a.p2.x) / 2.0, 2.0) + pow(res->p.y - (a.p1.y + a.p2.y) / 2.0, 2.0));
  }
}

void main(void) {
  point_t p1 = {1.0, 2.0}, p2 = {4.0, 6.0}, p3 = {5.0, 8.0};
  line_t l1 = {.p1 = p1, .p2 = p2}, l2 = {.p1 = p2, .p2 = p3};
  closest_point_t cp;

  printf("Line 1: "); print_line(l1); printf("\n");
  printf("Line 2: "); print_line(l2); printf("\n");

  line_intersection(l1, l2, &cp);

  printf("The closest point on line 1 to line 2 is: "); print_point(cp.p);
  printf(", with a distance of %lf and an angle of %lf degrees.", cp.distance, cp.angle * 180.0 / M_PI);
}