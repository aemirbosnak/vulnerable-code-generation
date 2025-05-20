//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

int main() {
  int n, i, j, k, d, **a, **c, **b, ctr = 0, **p, **q;
  float **m, e, dist;

  // Allocate memory
  a = (int *)malloc(MAX * sizeof(int));
  c = (int *)malloc(MAX * sizeof(int));
  b = (int *)malloc(MAX * sizeof(int));
  m = (float *)malloc(MAX * MAX * sizeof(float));

  // Get number of clusters
  printf("Enter the number of clusters:");
  scanf("%d", &n);

  // Get data
  printf("Enter the data:");
  for (i = 0; i < MAX; i++) {
    scanf("%d", &a[i]);
  }

  // Calculate distances
  for (i = 0; i < MAX; i++) {
    for (j = 0; j < MAX; j++) {
      dist = abs(a[i] - a[j]) / 2.0f;
      m[i][j] = dist;
    }
  }

  // Initialize cluster centers
  for (i = 0; i < n; i++) {
    c[i] = a[0];
  }

  // Iterate until convergence
  while (ctr < n) {
    for (i = 0; i < MAX; i++) {
      e = 0.0f;
      for (j = 0; j < n; j++) {
        dist = m[i][j];
        e += dist;
      }
      b[i] = c[j] = (int)round(e / n);
    }
    ctr++;
  }

  // Print cluster memberships
  printf("Cluster memberships:");
  for (i = 0; i < MAX; i++) {
    printf("%d ", b[i]);
  }

  // Free memory
  free(a);
  free(c);
  free(b);
  free(m);

  return 0;
}