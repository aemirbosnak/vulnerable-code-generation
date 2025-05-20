//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct node {
  int vertex;
  struct node *next;
} Node;

typedef struct graph {
  int num_vertices;
  Node *adj_list[MAX_VERTICES];
} Graph;

Graph *create_graph(int num_vertices) {
  Graph *graph = (Graph *)malloc(sizeof(Graph));
  graph->num_vertices = num_vertices;
  for (int i = 0; i < num_vertices; i++) {
    graph->adj_list[i] = NULL;
  }
  return graph;
}

void add_edge(Graph *graph, int src, int dest) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->vertex = dest;
  new_node->next = graph->adj_list[src];
  graph->adj_list[src] = new_node;
}

void print_graph(Graph *graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    printf("Vertex %d: ", i);
    Node *curr = graph->adj_list[i];
    while (curr != NULL) {
      printf("%d -> ", curr->vertex);
      curr = curr->next;
    }
    printf("\n");
  }
}

int main() {
  int num_vertices, num_edges;
  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);
  printf("Enter the number of edges: ");
  scanf("%d", &num_edges);

  Graph *graph = create_graph(num_vertices);

  for (int i = 0; i < num_edges; i++) {
    int src, dest;
    printf("Enter the source and destination vertices for edge %d: ", i + 1);
    scanf("%d %d", &src, &dest);
    add_edge(graph, src, dest);
  }

  print_graph(graph);

  return 0;
}