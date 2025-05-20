//FormAI DATASET v1.0 Category: Clustering Algorithm Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 1000  // number of data points
#define D 2     // number of dimensions
#define K 3     // number of clusters
#define MAX_ITER 1000  // maximum number of iterations

struct Point {
  double x[D];
  int cluster_id;  // assigned cluster ID
};

struct Centroid {
  double x[D];
  int count;       // number of points assigned to this centroid
};

double distance(const struct Point* p, const struct Centroid* c) {
  double sum = 0;
  for (int i = 0; i < D; ++i) {
    sum += pow(p->x[i] - c->x[i], 2);
  }
  return sqrt(sum);
}

void assign_clusters(struct Point* points, struct Centroid* centroids) {
  for (int i = 0; i < N; ++i) {
    double min_dist = INFINITY;
    for (int j = 0; j < K; ++j) {
      double dist = distance(&points[i], &centroids[j]);
      if (dist < min_dist) {
        min_dist = dist;
        points[i].cluster_id = j;
      }
    }
    centroids[points[i].cluster_id].count++;
    for (int j = 0; j < D; ++j) {
      centroids[points[i].cluster_id].x[j] += points[i].x[j];
    }
  }
}

void update_centroids(struct Point* points, struct Centroid* centroids) {
  for (int i = 0; i < K; ++i) {
    if (centroids[i].count > 0) {
      for (int j = 0; j < D; ++j) {
        centroids[i].x[j] /= centroids[i].count;
      }
    }
  }
}

int main() {
  struct Point points[N];
  struct Centroid centroids[K] = {{0}, 0};

  // read dataset
  FILE* fp = fopen("data.txt", "r");
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < D; ++j) {
      fscanf(fp, "%lf", &points[i].x[j]);
    }
  }
  fclose(fp);

  // initialize centroids randomly
  for (int i = 0; i < K; ++i) {
    int idx = rand() % N;
    for (int j = 0; j < D; ++j) {
      centroids[i].x[j] = points[idx].x[j];
    }
  }

  // perform clustering
  int iter = 0;
  while (iter < MAX_ITER) {
    assign_clusters(points, centroids);
    update_centroids(points, centroids);
    iter++;
  }

  // print results
  for (int i = 0; i < K; ++i) {
    printf("Centroid %d: (", i);
    for (int j = 0; j < D; ++j) {
      printf("%.2f ", centroids[i].x[j]);
    }
    printf(") %d points\n", centroids[i].count);
  }

  return 0;
}