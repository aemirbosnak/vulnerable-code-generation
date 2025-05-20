//FormAI DATASET v1.0 Category: Geometric algorithms ; Style: decentralized
/* 
  Example program for decentralized geometric algorithms using the concept of "ghost cells".
  This program implements a Voronoi diagram for a set of randomly generated points.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 1000 // maximum number of points
#define MAX_GHOST_CELLS 20 // maximum number of ghost cells

// structure for a 2D point
typedef struct {
  double x;
  double y;
} point_t;

// structure for a Voronoi cell
typedef struct {
  int num_points; // number of points in the cell
  int points[MAX_POINTS]; // indices of the points
  int num_ghosts; // number of ghost cells
  int ghosts[MAX_GHOST_CELLS]; // indices of the ghost cells
} cell_t;

// function to generate a random point in the unit square
point_t random_point() {
  point_t p;
  p.x = (double)rand() / RAND_MAX;
  p.y = (double)rand() / RAND_MAX;
  return p;
}

// function to compute the squared Euclidean distance between two points
double dist2(point_t p1, point_t p2) {
  double dx = p1.x - p2.x;
  double dy = p1.y - p2.y;
  return dx*dx + dy*dy;
}

// function to compute the Voronoi diagram for a set of points
void compute_voronoi(point_t points[], int n, cell_t cells[]) {
  int i, j, k;
  for (i = 0; i < n; i++) {
    cells[i].num_points = 0;
    cells[i].num_ghosts = 0;
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      if (i == j) continue;
      double d = dist2(points[i], points[j]);
      int ghost = -1;
      for (k = 0; k < n; k++) {
        if (k == i || k == j) continue;
        double d1 = dist2(points[i], points[k]);
        double d2 = dist2(points[j], points[k]);
        if (d1 < d && d2 < d) {
          ghost = k;
          break;
        }
      }
      if (ghost == -1) {
        cells[i].points[cells[i].num_points] = j;
        cells[i].num_points++;
      } else {
        cells[i].ghosts[cells[i].num_ghosts] = ghost;
        cells[i].num_ghosts++;
      }
    }
  }
}

int main() {
  int n, i, j;
  point_t points[MAX_POINTS];
  cell_t cells[MAX_POINTS];
  printf("Enter the number of points: ");
  scanf("%d", &n);
  printf("Generating %d random points...\n", n);
  srand(12345);
  for (i = 0; i < n; i++) {
    points[i] = random_point();
  }
  printf("Computing the Voronoi diagram...\n");
  compute_voronoi(points, n, cells);
  printf("Writing the output file...\n");
  FILE *fp = fopen("output.txt", "w");
  fprintf(fp, "# Voronoi diagram for %d points\n", n);
  for (i = 0; i < n; i++) {
    fprintf(fp, "cell %d: ", i);
    for (j = 0; j < cells[i].num_points; j++) {
      fprintf(fp, "%d ", cells[i].points[j]);
    }
    fprintf(fp, "| ");
    for (j = 0; j < cells[i].num_ghosts; j++) {
      fprintf(fp, "%d ", cells[i].ghosts[j]);
    }
    fprintf(fp, "\n");
  }
  fclose(fp);
  printf("Done.\n");
  return 0;
}