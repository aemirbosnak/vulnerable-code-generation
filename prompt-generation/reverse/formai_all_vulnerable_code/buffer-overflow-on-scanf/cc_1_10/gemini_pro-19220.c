//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_vertices;
int num_colors;
int num_edges;

void generate_graph() {
  int i, j;
  for (i = 0; i < num_vertices; i++) {
    for (j = i; j < num_vertices; j++) {
      if (i == j) {
        graph[i][j] = 0;
      } else {
        graph[i][j] = rand() % 2;
        graph[j][i] = graph[i][j];
      }
    }
  }
}

void print_graph() {
  int i, j;
  printf("Graph:\n");
  for (i = 0; i < num_vertices; i++) {
    for (j = 0; j < num_vertices; j++) {
      printf("%d ", graph[i][j]);
    }
    printf("\n");
  }
}

void generate_colors() {
  int i;
  for (i = 0; i < num_vertices; i++) {
    colors[i] = rand() % num_colors;
  }
}

void print_colors() {
  int i;
  printf("Colors:\n");
  for (i = 0; i < num_vertices; i++) {
    printf("%d ", colors[i]);
  }
  printf("\n");
}

int is_valid_coloring() {
  int i, j;
  for (i = 0; i < num_vertices; i++) {
    for (j = 0; j < num_vertices; j++) {
      if (graph[i][j] == 1 && colors[i] == colors[j]) {
        return 0;
      }
    }
  }
  return 1;
}

int main() {
  srand(time(NULL));

  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);

  printf("Enter the number of colors: ");
  scanf("%d", &num_colors);

  printf("Enter the number of edges: ");
  scanf("%d", &num_edges);

  generate_graph();
  print_graph();
  generate_colors();
  print_colors();

  if (is_valid_coloring()) {
    printf("The coloring is valid.\n");
  } else {
    printf("The coloring is not valid.\n");
  }

  return 0;
}