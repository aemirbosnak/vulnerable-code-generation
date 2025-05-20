//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_ITERATIONS 1000
#define THRESHOLD 1e-6

int main() {
  int num_points = 0, num_clusters = 0, i = 0, j = 0, k = 0;
  float points[MAX_POINTS][2];
  int cluster_assignments[MAX_POINTS];
  int cluster_sizes[MAX_POINTS];
  float cluster_centers[MAX_POINTS][2];
  float old_cluster_centers[MAX_POINTS][2];
  int iterations = 0;
  float difference = 0.0f;

  // Read in the data points
  printf("Enter the number of data points: ");
  scanf("%d", &num_points);

  printf("Enter the data points (x,y):\n");
  for (i = 0; i < num_points; i++) {
    scanf("%f,%f", &points[i][0], &points[i][1]);
    cluster_assignments[i] = -1;
  }

  // Read in the number of clusters
  printf("Enter the number of clusters: ");
  scanf("%d", &num_clusters);

  // Initialize the cluster centers
  for (i = 0; i < num_clusters; i++) {
    cluster_sizes[i] = 0;
    cluster_centers[i][0] = points[rand() % num_points][0];
    cluster_centers[i][1] = points[rand() % num_points][1];
  }

  // Iterate until convergence or maximum number of iterations is reached
  while (iterations < MAX_ITERATIONS) {
    // Save the old cluster centers for comparison
    for (i = 0; i < num_clusters; i++) {
      old_cluster_centers[i][0] = cluster_centers[i][0];
      old_cluster_centers[i][1] = cluster_centers[i][1];
    }

    // Assign the points to clusters
    for (i = 0; i < num_points; i++) {
      float min_distance = INFINITY;

      for (j = 0; j < num_clusters; j++) {
        float distance = sqrt(pow(cluster_centers[j][0] - points[i][0], 2) + pow(cluster_centers[j][1] - points[i][1], 2));

        if (distance < min_distance) {
          min_distance = distance;
          cluster_assignments[i] = j;
        }
      }

      cluster_sizes[cluster_assignments[i]]++;
    }

    // Recalculate the cluster centers
    for (i = 0; i < num_clusters; i++) {
      float sum_x = 0.0f, sum_y = 0.0f;

      for (j = 0; j < num_points; j++) {
        if (cluster_assignments[j] == i) {
          sum_x += points[j][0];
          sum_y += points[j][1];
        }
      }

      cluster_centers[i][0] = sum_x / cluster_sizes[i];
      cluster_centers[i][1] = sum_y / cluster_sizes[i];
    }

    // Check for convergence
    difference = 0.0f;

    for (i = 0; i < num_clusters; i++) {
      if (fabs(old_cluster_centers[i][0] - cluster_centers[i][0]) > difference) {
        difference = fabs(old_cluster_centers[i][0] - cluster_centers[i][0]);
      }

      if (fabs(old_cluster_centers[i][1] - cluster_centers[i][1]) > difference) {
        difference = fabs(old_cluster_centers[i][1] - cluster_centers[i][1]);
      }
    }

    if (difference < THRESHOLD) {
      break;
    }

    iterations++;
  }

  printf("Cluster centers:\n");
  for (i = 0; i < num_clusters; i++) {
    printf("(%f, %f)\n", cluster_centers[i][0], cluster_centers[i][1]);
  }

  return 0;
}