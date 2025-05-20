//Code Llama-13B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CLUSTERS 10
#define MAX_POINTS 100

typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  Point points[MAX_POINTS];
  int num_points;
} Cluster;

Cluster clusters[MAX_CLUSTERS];

void print_cluster(Cluster cluster) {
  printf("Cluster: ");
  for (int i = 0; i < cluster.num_points; i++) {
    printf("(%lf, %lf) ", cluster.points[i].x, cluster.points[i].y);
  }
  printf("\n");
}

void print_clusters(Cluster clusters[], int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    print_cluster(clusters[i]);
  }
}

void add_point(Cluster cluster, double x, double y) {
  cluster.points[cluster.num_points].x = x;
  cluster.points[cluster.num_points].y = y;
  cluster.num_points++;
}

void initialize_clusters(Cluster clusters[], int num_clusters) {
  for (int i = 0; i < num_clusters; i++) {
    clusters[i].num_points = 0;
  }
}

double euclidean_distance(Point p1, Point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void update_clusters(Cluster clusters[], int num_clusters, Point point) {
  double min_distance = INFINITY;
  int min_cluster = -1;
  for (int i = 0; i < num_clusters; i++) {
    double distance = euclidean_distance(clusters[i].points[0], point);
    if (distance < min_distance) {
      min_distance = distance;
      min_cluster = i;
    }
  }
  if (min_cluster == -1) {
    printf("Error: could not find nearest cluster\n");
    return;
  }
  add_point(clusters[min_cluster], point.x, point.y);
}

int main() {
  Cluster clusters[MAX_CLUSTERS];
  initialize_clusters(clusters, MAX_CLUSTERS);

  Point points[MAX_POINTS];
  int num_points = 0;

  // Read input points
  while (scanf("%lf %lf", &points[num_points].x, &points[num_points].y) != EOF) {
    num_points++;
  }

  // Update clusters
  for (int i = 0; i < num_points; i++) {
    update_clusters(clusters, MAX_CLUSTERS, points[i]);
  }

  // Print clusters
  print_clusters(clusters, MAX_CLUSTERS);

  return 0;
}