//Code Llama-13B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_DIM 3

typedef struct {
  double x, y, z;
} Point;

typedef struct {
  Point center;
  int num_points;
  double radius;
} Cluster;

int main() {
  Point points[MAX_POINTS];
  int num_points = 0;
  double max_distance = 0.0;
  int i, j;

  // Read points from input
  while (scanf("%lf %lf %lf", &points[num_points].x, &points[num_points].y, &points[num_points].z) == 3) {
    num_points++;
  }

  // Compute maximum distance between points
  for (i = 0; i < num_points - 1; i++) {
    for (j = i + 1; j < num_points; j++) {
      double distance = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2) + pow(points[i].z - points[j].z, 2));
      if (distance > max_distance) {
        max_distance = distance;
      }
    }
  }

  // Initialize clusters
  Cluster clusters[num_points];
  for (i = 0; i < num_points; i++) {
    clusters[i].num_points = 1;
    clusters[i].center = points[i];
    clusters[i].radius = 0.0;
  }

  // Assign points to clusters
  for (i = 0; i < num_points - 1; i++) {
    for (j = i + 1; j < num_points; j++) {
      double distance = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2) + pow(points[i].z - points[j].z, 2));
      if (distance <= max_distance) {
        clusters[i].num_points++;
        clusters[j].num_points++;
      }
    }
  }

  // Compute cluster centers and radii
  for (i = 0; i < num_points; i++) {
    clusters[i].center.x /= clusters[i].num_points;
    clusters[i].center.y /= clusters[i].num_points;
    clusters[i].center.z /= clusters[i].num_points;
    clusters[i].radius = sqrt(pow(clusters[i].center.x - points[i].x, 2) + pow(clusters[i].center.y - points[i].y, 2) + pow(clusters[i].center.z - points[i].z, 2));
  }

  // Print clusters
  for (i = 0; i < num_points; i++) {
    printf("Cluster %d: (%lf, %lf, %lf) with radius %lf and %d points\n", i, clusters[i].center.x, clusters[i].center.y, clusters[i].center.z, clusters[i].radius, clusters[i].num_points);
  }

  return 0;
}