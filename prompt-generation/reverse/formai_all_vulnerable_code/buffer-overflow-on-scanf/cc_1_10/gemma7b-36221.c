//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k) {
  int i, j, d, c = 0, **centroids = (int **)malloc(k * sizeof(int *));
  for (i = 0; i < k; i++) {
    centroids[i] = (int *)malloc(n * sizeof(int));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      d = 0;
      for (c = 0; c < k; c++) {
        if (c != j) {
          d += abs(arr[i] - centroids[j][c]) * abs(arr[i] - centroids[j][c]);
        }
      }
      centroids[j][i] = d;
    }
  }

  for (i = 0; i < n; i++) {
    int min_dist = MAX;
    for (j = 0; j < k; j++) {
      if (centroids[j][i] < min_dist) {
        min_dist = centroids[j][i];
      }
    }
    printf("Cluster %d: ", j + 1);
    printf("Element %d: ", i + 1);
    printf("Distance: %.2f\n", min_dist);
  }
  free(centroids);
}

int main() {
  int n, k;
  scanf("Enter the number of elements: ", &n);
  scanf("Enter the number of clusters: ", &k);

  int **arr = (int *)malloc(n * sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("Enter element %d: ", &arr[i]);
  }

  cluster(arr, n, k);

  free(arr);
  return 0;
}