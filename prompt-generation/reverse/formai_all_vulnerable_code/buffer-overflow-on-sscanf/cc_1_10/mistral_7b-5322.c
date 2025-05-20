//MISTRAL-7B DATASET v1.0 Category: Geometric algorithms ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

typedef struct { double x, y; } point_t;
typedef struct { double a, b, c; } equation_t;

void read_point(point_t* p) {
  char str[32];
  scanf("%s", str);
  sscanf(str, "(%lf, %lf)", &p->x, &p->y);
}

void read_equation(equation_t* e) {
  char str[128];
  fgets(str, sizeof(str), stdin);
  str[strcspn(str, "\n")] = '\0';
  sscanf(str, "y = %lfx + %lf", &e->a, &e->b);
}

int solve_equation(equation_t e, point_t p) {
  double root = (-e.b) / (2 * e.a);
  return fabs(p.x - root) < 0.001;
}

point_t rand_point() {
  point_t p;
  p.x = rand() / (double)RAND_MAX * 10.0;
  p.y = rand() / (double)RAND_MAX * 10.0;
  return p;
}

void print_point(point_t p) {
  printf("(%lf, %lf)\n", p.x, p.y);
}

void print_equation(equation_t e) {
  printf("y = %.2fx + %.2f\n", e.a, e.b);
}

int main() {
  srand(time(NULL));
  point_t p, q;
  equation_t e;

  read_point(&p);
  read_equation(&e);

  q = rand_point();

  printf("Point: ");
  print_point(p);
  printf("Equation: ");
  print_equation(e);

  int sol = solve_equation(e, p);
  int sol_q = solve_equation(e, q);

  printf("Point %s solution of the equation.\n", sol ? "is" : "is not");
  printf("Random point %s solution of the equation.\n", sol_q ? "is" : "is not");

  return 0;
}