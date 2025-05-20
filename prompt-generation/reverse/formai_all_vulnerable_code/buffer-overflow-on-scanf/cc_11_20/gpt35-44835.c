//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
  int n, i, j;
  printf("Enter the number of points: ");
  scanf("%d", &n);

  float points[n][2], distance[n];
  int cluster[n];

  // Take input for points
  for (i = 0; i < n; i++) {
    printf("Enter the coordinates of point %d: ", i+1);
    scanf("%f %f", &points[i][0], &points[i][1]);
    cluster[i] = -1; // Set cluster of each point to -1 initially
  }

  int num_clusters;
  printf("Enter the number of clusters: ");
  scanf("%d", &num_clusters);

  // Initialize centroids
  float centroid[num_clusters][2];
  for (i = 0; i < num_clusters; i++) {
    int rand_point_index = rand() % n;
    centroid[i][0] = points[rand_point_index][0];
    centroid[i][1] = points[rand_point_index][1];
  }

  // Perform clustering
  int iter = 0, changes = 1;
  while (changes > 0) {
    printf("Iteration %d:\n", iter+1);
    changes = 0;

    // Assign points to nearest centroids
    for (i = 0; i < n; i++) {
      for (j = 0; j < num_clusters; j++) {
        distance[j] = sqrt(pow(points[i][0]-centroid[j][0], 2) + pow(points[i][1]-centroid[j][1], 2));
        printf("Distance between point %d and centroid %d: %f\n", i+1, j+1, distance[j]);
      }
      // Find index of closest centroid
      int min_index = 0;
      for (j = 1; j < num_clusters; j++) {
        if (distance[j] < distance[min_index])
          min_index = j;
      }
      printf("Point %d assigned to cluster %d\n", i+1, min_index+1);
      if (cluster[i] != min_index) {
        cluster[i] = min_index;
        changes++;
      }
    }

    // Recompute centroids
    for (i = 0; i < num_clusters; i++) {
      float sum_x = 0, sum_y = 0;
      int count = 0;
      for (j = 0; j < n; j++) {
        if (cluster[j] == i) {
          sum_x += points[j][0];
          sum_y += points[j][1];
          count++;
        }
      }
      centroid[i][0] = sum_x / count;
      centroid[i][1] = sum_y / count;
      printf("New centroid %d: (%f, %f)\n", i+1, centroid[i][0], centroid[i][1]);
    }
    iter++;
  }

  printf("Final clusters:\n");
  for (i = 0; i < num_clusters; i++) {
    printf("Cluster %d: ", i+1);
    for (j = 0; j < n; j++) {
      if (cluster[j] == i)
        printf("%d ", j+1);
    }
    printf("\n");
  }

  return 0;
}