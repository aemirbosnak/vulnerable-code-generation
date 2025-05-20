//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIM 2 // number of dimensions

typedef struct Point Point;
struct Point {
  float x[DIM]; // coordinates
  int cluster; // cluster index
};

// squared euclidean distance between two points
float dist(Point a, Point b) {
  float d = 0.0;
  for (int i = 0; i < DIM; i++)
    d += pow(a.x[i] - b.x[i], 2);
  return d;
}

int main(int argc, char *argv[]) {
  if (argc < 3) {
    printf("%s <data_file> <k>\n", argv[0]);
    return 1;
  }

  char *filename = argv[1];
  int k = atoi(argv[2]);

  // read dataset from file
  FILE *file = fopen(filename, "r");
  if (file == NULL) {
    printf("Cannot open file %s\n", filename);
    return 1;
  }

  int n = 0; // number of points
  Point *points = NULL;

  while (!feof(file)) {
    n++;
    points = (Point*) realloc(points, n * sizeof(Point));

    for (int i = 0; i < DIM; i++)
      fscanf(file, "%f", &points[n-1].x[i]);

    points[n-1].cluster = -1; // not assigned yet
  }

  fclose(file);

  // initialize centroids randomly
  Point *centroids = (Point*) malloc(k * sizeof(Point));

  for (int i = 0; i < k; i++) {
    int j = rand() % n;
    for (int d = 0; d < DIM; d++)
      centroids[i].x[d] = points[j].x[d];
    centroids[i].cluster = i;
  }

  // clustering algorithm
  int changed;
  do {
    changed = 0;

    // assign each point to the nearest centroid
    for (int i = 0; i < n; i++) {
      float min_dist = dist(points[i], centroids[0]);
      int min_index = 0;

      for (int j = 1; j < k; j++) {
        float d = dist(points[i], centroids[j]);
        if (d < min_dist) {
          min_dist = d;
          min_index = j;
        }
      }

      if (points[i].cluster != min_index) {
        points[i].cluster = min_index;
        changed = 1;
      }
    }

    // compute new centroids
    for (int i = 0; i < k; i++) {
      int count = 0;

      for (int d = 0; d < DIM; d++)
        centroids[i].x[d] = 0.0;

      for (int j = 0; j < n; j++) {
        if (points[j].cluster == i) {
          count++;
          for (int d = 0; d < DIM; d++)
            centroids[i].x[d] += points[j].x[d];
        }
      }

      if (count > 0) {
        for (int d = 0; d < DIM; d++)
          centroids[i].x[d] /= count;
      }
    }

  } while (changed);

  // print results
  for (int i = 0; i < n; i++) {
    printf("%.2f", points[i].x[0]);
    for (int d = 1; d < DIM; d++)
      printf(", %.2f", points[i].x[d]);
    printf(", %d\n", points[i].cluster);
  }

  // free memory
  free(points);
  free(centroids);

  return 0;
}