//GEMINI-pro DATASET v1.0 Category: Geometric algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <math.h>
#include <float.h>
#include <time.h>
#include <assert.h>
#include <limits.h>

#define MAX_DIM 100
#define MAX_POINTS 100000

typedef struct point {
  int dim;
  double coords[MAX_DIM];
} point;

double dist(point p1, point p2) {
  double sum = 0;
  for (int i = 0; i < p1.dim; i++) {
    sum += (p1.coords[i] - p2.coords[i]) * (p1.coords[i] - p2.coords[i]);
  }
  return sqrt(sum);
}

int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  point points[MAX_POINTS];
  for (int i = 0; i < n; i++) {
    points[i].dim = d;
    for (int j = 0; j < d; j++) {
      scanf("%lf", &points[i].coords[j]);
    }
  }

  double min_dist = DBL_MAX;
  int min_i = -1, min_j = -1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double dist_ij = dist(points[i], points[j]);
      if (dist_ij < min_dist) {
        min_dist = dist_ij;
        min_i = i;
        min_j = j;
      }
    }
  }

  printf("Minimum distance: %.6lf\n", min_dist);
  printf("Points: (%d, %d)\n", min_i + 1, min_j + 1);

  return 0;
}