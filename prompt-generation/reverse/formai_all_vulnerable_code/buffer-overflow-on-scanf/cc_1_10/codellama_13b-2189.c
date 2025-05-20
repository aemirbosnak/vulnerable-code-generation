//Code Llama-13B DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_DIM 100
#define MAX_CLUSTERS 10

typedef struct {
  double x;
  double y;
} Point;

typedef struct {
  Point center;
  int size;
} Cluster;

int compare(const void *a, const void *b) {
  return *(double *)a - *(double *)b;
}

double distance(Point p1, Point p2) {
  return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

void kmeans(int n, int k, Point *points, Cluster *clusters) {
  int i, j, cluster_index;
  double min_dist;

  // initialize clusters randomly
  for (i = 0; i < k; i++) {
    clusters[i].center.x = points[i].x;
    clusters[i].center.y = points[i].y;
    clusters[i].size = 1;
  }

  // assign points to clusters
  for (i = 0; i < n; i++) {
    min_dist = distance(points[i], clusters[0].center);
    cluster_index = 0;
    for (j = 1; j < k; j++) {
      if (distance(points[i], clusters[j].center) < min_dist) {
        min_dist = distance(points[i], clusters[j].center);
        cluster_index = j;
      }
    }
    clusters[cluster_index].size++;
  }

  // update cluster centers
  for (i = 0; i < k; i++) {
    clusters[i].center.x = clusters[i].center.x / clusters[i].size;
    clusters[i].center.y = clusters[i].center.y / clusters[i].size;
  }
}

int main() {
  int i, n, k;
  Point points[MAX_DIM];
  Cluster clusters[MAX_CLUSTERS];

  // read input
  scanf("%d %d", &n, &k);
  for (i = 0; i < n; i++) {
    scanf("%lf %lf", &points[i].x, &points[i].y);
  }

  // perform k-means clustering
  kmeans(n, k, points, clusters);

  // print output
  for (i = 0; i < k; i++) {
    printf("Cluster %d: (%lf, %lf) with %d points\n", i, clusters[i].center.x, clusters[i].center.y, clusters[i].size);
  }

  return 0;
}