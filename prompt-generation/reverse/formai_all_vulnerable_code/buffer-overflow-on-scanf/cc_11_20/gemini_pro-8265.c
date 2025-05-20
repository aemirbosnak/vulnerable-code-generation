//GEMINI-pro DATASET v1.0 Category: Physics simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 3
#define G 6.674e-11
#define DT 0.001

typedef struct {
  double m;
  double r[DIM];
  double v[DIM];
  double f[DIM];
} body_t;

int main() {
  int n;
  scanf("%d", &n);
  body_t *bodies = malloc(n * sizeof(body_t));
  for (int i = 0; i < n; i++) {
    scanf("%lf", &bodies[i].m);
    for (int j = 0; j < DIM; j++) {
      scanf("%lf", &bodies[i].r[j]);
    }
    for (int j = 0; j < DIM; j++) {
      scanf("%lf", &bodies[i].v[j]);
    }
  }

  for (int t = 0; t < 10000; t++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < DIM; j++) {
        bodies[i].f[j] = 0;
        for (int k = 0; k < n; k++) {
          if (k == i) continue;
          double dx = bodies[i].r[j] - bodies[k].r[j];
          double dy = bodies[i].r[(j + 1) % DIM] - bodies[k].r[(j + 1) % DIM];
          double dz = bodies[i].r[(j + 2) % DIM] - bodies[k].r[(j + 2) % DIM];
          double r = sqrt(dx * dx + dy * dy + dz * dz);
          double f = G * bodies[i].m * bodies[k].m / (r * r);
          bodies[i].f[j] += f * dx / r;
          bodies[i].f[(j + 1) % DIM] += f * dy / r;
          bodies[i].f[(j + 2) % DIM] += f * dz / r;
        }
      }
      for (int j = 0; j < DIM; j++) {
        bodies[i].v[j] += DT * bodies[i].f[j] / bodies[i].m;
        bodies[i].r[j] += DT * bodies[i].v[j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    printf("body %d:\n", i);
    for (int j = 0; j < DIM; j++) {
      printf("  r[%d] = %f\n", j, bodies[i].r[j]);
      printf("  v[%d] = %f\n", j, bodies[i].v[j]);
    }
    printf("\n");
  }

  free(bodies);
  return 0;
}