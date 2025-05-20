//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  double x, y;
} Point;

typedef struct {
  double a, b, c, d;
} Equation;

Point* read_points(int n, char* filename) {
  FILE* fp = fopen(filename, "r");
  Point* points = (Point*)malloc(n * sizeof(Point));
  for (int i = 0; i < n; i++) {
    fscanf(fp, "%lf %lf", &points[i].x, &points[i].y);
  }
  fclose(fp);
  return points;
}

Equation* solve_equation(Point* points, int n) {
  Equation* equation = (Equation*)malloc(sizeof(Equation));
  double A[n][n];
  double b[n];
  for (int i = 0; i < n; i++) {
    A[i][0] = 1;
    b[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      A[i][j] = A[i][j+1] * (points[i].x - points[j].x) + A[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    b[i] = A[i][n];
  }
  equation->a = -1;
  equation->b = -b[0];
  equation->c = 0;
  equation->d = 0;
  for (int i = 0; i < n; i++) {
    equation->b += b[i] * (points[i].x - points[0].x);
    equation->c += (points[i].y - points[0].y) * (points[i].x - points[0].x);
    equation->d += (points[i].y - points[0].y);
  }
  equation->b /= equation->c;
  equation->c /= equation->d;
  equation->d = -equation->a + equation->b * points[0].x;
  free(A);
  free(b);
  return equation;
}

void print_equation(Equation* equation) {
  printf("y = %lfx + %lfy + %lf\n", equation->a, equation->b, equation->c);
}

int main() {
  Point* points = read_points(5, "points.txt");
  Equation* equation = solve_equation(points, 5);
  print_equation(equation);
  free(points);
  free(equation);
  return 0;
}