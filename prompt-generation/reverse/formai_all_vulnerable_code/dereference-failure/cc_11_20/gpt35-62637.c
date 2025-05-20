//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAX_K 10
#define MAX_ITERS 100

typedef struct data_point {
  double x;
  double y;
} data_point;

typedef struct k_cluster {
  int num_points;
  double sum_x;
  double sum_y;
  data_point centroid;
  data_point* points;
} k_cluster;

int main() {
  // Randomly generate data points
  const int num_points = 1000;
  data_point* points = malloc(num_points * sizeof(data_point));
  for (int i = 0; i < num_points; i++) {
    points[i].x = (double) rand() / RAND_MAX;
    points[i].y = (double) rand() / RAND_MAX;
  }

  // Initialize k clusters with random centroids
  const int k = 3;
  k_cluster clusters[MAX_K];
  for (int i = 0; i < k; i++) {
    clusters[i].centroid.x = (double) rand() / RAND_MAX;
    clusters[i].centroid.y = (double) rand() / RAND_MAX;
  }

  // Assign points to clusters and update centroids until convergence
  bool done = false;
  int iter = 0;
  while (!done && iter++ < MAX_ITERS) {
    // Reset cluster data
    for (int i = 0; i < k; i++) {
      clusters[i].num_points = 0;
      clusters[i].sum_x = 0.0;
      clusters[i].sum_y = 0.0;
    }

    // Assign each point to nearest cluster
    for (int i = 0; i < num_points; i++) {
      double min_dist = INFINITY;
      int min_cluster_index = -1;
      for (int j = 0; j < k; j++) {
        double dist = sqrt(pow(points[i].x - clusters[j].centroid.x, 2)
                           + pow(points[i].y - clusters[j].centroid.y, 2));
        if (dist < min_dist) {
          min_dist = dist;
          min_cluster_index = j;
        }
      }
      k_cluster* min_cluster = &clusters[min_cluster_index];
      min_cluster->num_points++;
      min_cluster->sum_x += points[i].x;
      min_cluster->sum_y += points[i].y;
      min_cluster->points = realloc(min_cluster->points, min_cluster->num_points * sizeof(data_point));
      min_cluster->points[min_cluster->num_points - 1] = points[i];
    }

    // Update centroids of clusters
    done = true;
    for (int i = 0; i < k; i++) {
      if (clusters[i].num_points > 0) {
        double new_x = clusters[i].sum_x / clusters[i].num_points;
        double new_y = clusters[i].sum_y / clusters[i].num_points;
        if (new_x != clusters[i].centroid.x || new_y != clusters[i].centroid.y) {
          clusters[i].centroid.x = new_x;
          clusters[i].centroid.y = new_y;
          done = false;
        }
      }
    }
  }

  // Print out results
  printf("Final cluster centroids:\n");
  for (int i = 0; i < k; i++) {
    k_cluster cluster = clusters[i];
    printf("Cluster %d (%d points): (%f, %f)\n", i, cluster.num_points, cluster.centroid.x, cluster.centroid.y);
    printf("Points:\n");
    for (int j = 0; j < cluster.num_points; j++) {
      printf("(%f, %f)\n", cluster.points[j].x, cluster.points[j].y);
    }
  }

  // Free memory
  for (int i = 0; i < k; i++) {
    free(clusters[i].points);
  }
  free(points);

  return 0;
}