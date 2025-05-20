//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100 // maximum number of vertices in the graph
#define MAX_NEIGHBORS 100 // maximum number of neighbors for each vertex
#define MAX_COLORS 10 // maximum number of colors that can be used to color vertices

struct vertex {
  int id;
  int num_neighbors;
  int neighbors[MAX_NEIGHBORS];
  int color;
};

int num_vertices;
struct vertex graph[MAX_VERTICES];

// initialize the graph with vertices and their neighbors
void init_graph() {
  int i, j;
  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);
  printf("Enter the neighbor list for each vertex (separated by spaces):\n");
  for (i = 0; i < num_vertices; i++) {
    graph[i].id = i;
    printf("Neighbors of vertex %d: ", i);
    scanf("%d", &graph[i].num_neighbors);
    for (j = 0; j < graph[i].num_neighbors; j++) {
      scanf("%d", &graph[i].neighbors[j]);
    }
  }
}

// choose an uncolored vertex with the highest degree
int choose_vertex() {
  int i, max_degree = -1, max_degree_vertex = -1;
  for (i = 0; i < num_vertices; i++) {
    if (graph[i].color == -1 && graph[i].num_neighbors > max_degree) {
      max_degree_vertex = i;
      max_degree = graph[i].num_neighbors;
    }
  }
  return max_degree_vertex;
}

// color a vertex with the lowest available color
void color_vertex(int vertex) {
  int i, j, available_colors[MAX_COLORS] = { 0 };
  for (i = 0; i < graph[vertex].num_neighbors; i++) {
    int neighbor = graph[vertex].neighbors[i];
    if (graph[neighbor].color != -1) {
      available_colors[graph[neighbor].color] = 1;
    }
  }
  for (j = 0; j < MAX_COLORS; j++) {
    if (!available_colors[j]) {
      graph[vertex].color = j;
      break;
    }
  }
}

// color all vertices using a greedy algorithm
void color_graph() {
  int i;
  for (i = 0; i < num_vertices; i++) {
    graph[i].color = -1;
  }
  while (1) {
    int vertex = choose_vertex();
    if (vertex == -1) {
      break;
    }
    color_vertex(vertex);
  }
}

// print the coloring of the graph
void print_coloring() {
  int i;
  printf("Vertex\tColor\n");
  for (i = 0; i < num_vertices; i++) {
    printf("%d\t%d\n", graph[i].id, graph[i].color);
  }
}

// main function
int main() {
  init_graph();
  color_graph();
  print_coloring();
  return 0;
}