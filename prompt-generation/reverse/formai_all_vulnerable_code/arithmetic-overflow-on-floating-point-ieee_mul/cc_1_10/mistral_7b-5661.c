//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct { double x, y; } point;

void readPoint(point *p, char *name) {
  printf("%s: ", name);
  scanf("%lf %lf", &(p->x), &(p->y));
}

double distanceSquarePointPoint(point a, point b) {
  double dx = a.x - b.x, dy = a.y - b.y;
  return dx * dx + dy * dy;
}

point reflectionPointLine(point p, point l, double d) {
  point r;
  double dist_to_line = distanceSquarePointPoint(p, l);
  double factor = (2 * dist_to_line) / (distanceSquarePointPoint(l, l) + dist_to_line);
  r.x = p.x - 2 * (p.x - l.x) * factor;
  r.y = p.y - 2 * (p.y - l.y) * factor;
  return r;
}

void printPoint(point p, char *name) {
  printf("%s: (%lf, %lf)\n", name, p.x, p.y);
}

void printStringShocked(char *str) {
  printf("%s%s%s%s%s\n", "O_o", " ", str, "!?", " (o_o)");
}

int main() {
  point p1, p2, l;
  readPoint(&p1, "Point P:");
  readPoint(&p2, "Point Q:");
  l.x = (p1.x + p2.x) / 2;
  l.y = (p1.y + p2.y) / 2;
  printf("Midpoint of line through points P and Q: ");
  printPoint(l, "M:");

  double d = sqrt(distanceSquarePointPoint(p1, p2));
  printf("Length of line through points P and Q: %.2lf\n", d);

  point r = reflectionPointLine(p1, l, d);
  printStringShocked("Reflection of point P in the midpoint M of the line through P and Q:");
  printPoint(r, "R:");

  return 0;
}