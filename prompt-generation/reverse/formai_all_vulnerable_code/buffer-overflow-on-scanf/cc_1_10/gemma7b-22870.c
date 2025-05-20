//Gemma-7B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

void cluster(int **arr, int n, int k) {
  int i, j, d, min_dist, cluster_id = 0;
  float **distance_matrix = (float **)malloc(n * sizeof(float *));
  distance_matrix = (float **)malloc(n * sizeof(float *));
  for (i = 0; i < n; i++) {
    distance_matrix[i] = (float *)malloc(n * sizeof(float));
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      d = abs(arr[i] - arr[j]);
      distance_matrix[i][j] = (float)d;
    }
  }

  for (i = 0; i < k; i++) {
    min_dist = MAX;
    for (j = 0; j < n; j++) {
      for (d = 0; d < n; d++) {
        if (distance_matrix[j][d] < min_dist) {
          min_dist = distance_matrix[j][d];
          cluster_id = d;
        }
      }
    }

    printf("Cluster %d: ", i + 1);
    for (j = 0; j < n; j++) {
      if (distance_matrix[j][cluster_id] == min_dist) {
        printf("%d ", arr[j]);
      }
    }

    printf("\n");
  }

  free(distance_matrix);
}

int main() {
  int n, k;
  printf("Enter the number of data points: ");
  scanf("%d", &n);

  printf("Enter the number of clusters: ");
  scanf("%d", &k);

  int **arr = (int *)malloc(n * sizeof(int));
  printf("Enter the data points: ");
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  cluster(arr, n, k);

  free(arr);

  return 0;
}