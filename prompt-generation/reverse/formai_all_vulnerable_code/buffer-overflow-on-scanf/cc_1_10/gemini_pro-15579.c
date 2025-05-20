//GEMINI-pro DATASET v1.0 Category: Graph Coloring Problem ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define MAXIMUM_SIZE 100
#define MAX 99999

int main_graph[MAXIMUM_SIZE][MAXIMUM_SIZE];
int chromatic_number;
int number_of_vertices;
int colored_vertices;
int color_assignment[MAXIMUM_SIZE];
int graph_degree[MAXIMUM_SIZE];

bool is_safe(int vertex, int color) {
  for (int i = 0; i < number_of_vertices; i++) {
    if (main_graph[vertex][i] && color_assignment[i] == color) {
      return false;
    }
  }
  return true;
}

bool graph_color(int vertex) {
  if (vertex == number_of_vertices) {
    return true;
  }

  for (int color = 1; color <= chromatic_number; color++) {
    if (is_safe(vertex, color)) {
      color_assignment[vertex] = color;
      if (graph_color(vertex + 1)) {
        return true;
      }
      color_assignment[vertex] = 0;
    }
  }
  return false;
}

int find_chromatic_number() {
  int result = 0;
  for (int i = 0; i < number_of_vertices; i++) {
    for (int j = 0; j < number_of_vertices; j++) {
      if (main_graph[i][j]) {
        result = fmax(result, graph_degree[i]);
      }
    }
  }
  return result + 1;
}

void print_solution() {
  printf("Chromatic Number of the graph is %d\n", chromatic_number);
  printf("Coloring of the graph is: \n");
  for (int i = 0; i < number_of_vertices; i++) {
    printf("Vertex %d -> Color %d\n", i + 1, color_assignment[i]);
  }
}

int main() {
  printf("Enter the number of vertices: ");
  scanf("%d", &number_of_vertices);
  printf("Enter the adjacency matrix: \n");

  for (int i = 0; i < number_of_vertices; i++) {
    for (int j = 0; j < number_of_vertices; j++) {
      scanf("%d", &main_graph[i][j]);
      if (main_graph[i][j]) {
        graph_degree[i]++;
      }
    }
  }

  chromatic_number = find_chromatic_number();
  if (!graph_color(0)) {
    printf("Graph cannot be colored with %d colors", chromatic_number);
  } else {
    print_solution();
  }

  return 0;
}