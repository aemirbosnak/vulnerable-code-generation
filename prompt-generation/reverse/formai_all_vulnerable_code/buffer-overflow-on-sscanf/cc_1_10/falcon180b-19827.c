//Falcon-180B DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_VERTEX 1000
#define MAX_EDGE 10000

typedef struct {
  int id;
  double x, y;
} vertex_t;

typedef struct {
  int id;
  int start;
  int end;
} edge_t;

int num_vertices, num_edges;
vertex_t *vertices;
edge_t *edges;

void init() {
  num_vertices = 0;
  num_edges = 0;
  vertices = (vertex_t*)malloc(MAX_VERTEX * sizeof(vertex_t));
  edges = (edge_t*)malloc(MAX_EDGE * sizeof(edge_t));
}

void read_vertices() {
  FILE *fp;
  char line[100];
  int i = 0;
  vertex_t vertex;

  fp = fopen("vertices.txt", "r");
  if (fp == NULL) {
    printf("Error: Could not open file.\n");
    exit(1);
  }

  while (fgets(line, sizeof(line), fp)!= NULL) {
    sscanf(line, "%d %lf %lf", &vertex.id, &vertex.x, &vertex.y);
    vertices[i] = vertex;
    i++;
  }

  fclose(fp);
  num_vertices = i;
}

void read_edges() {
  FILE *fp;
  char line[100];
  int i = 0;
  edge_t edge;

  fp = fopen("edges.txt", "r");
  if (fp == NULL) {
    printf("Error: Could not open file.\n");
    exit(1);
  }

  while (fgets(line, sizeof(line), fp)!= NULL) {
    sscanf(line, "%d %d %d", &edge.id, &edge.start, &edge.end);
    edges[i] = edge;
    i++;
  }

  fclose(fp);
  num_edges = i;
}

void print_vertices() {
  int i;

  for (i = 0; i < num_vertices; i++) {
    printf("%d (%lf, %lf)\n", vertices[i].id, vertices[i].x, vertices[i].y);
  }
}

void print_edges() {
  int i;

  for (i = 0; i < num_edges; i++) {
    printf("%d - (%d, %d)\n", edges[i].id, edges[i].start, edges[i].end);
  }
}

int main() {
  init();
  read_vertices();
  read_edges();

  print_vertices();
  print_edges();

  return 0;
}