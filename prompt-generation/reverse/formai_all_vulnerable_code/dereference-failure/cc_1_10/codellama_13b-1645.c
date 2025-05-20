//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int value;
  struct node* next;
} Node;

typedef struct graph {
  int num_vertices;
  int num_edges;
  Node** adjacency_list;
} Graph;

Graph* create_graph(int num_vertices, int num_edges) {
  Graph* graph = (Graph*)malloc(sizeof(Graph));
  graph->num_vertices = num_vertices;
  graph->num_edges = num_edges;
  graph->adjacency_list = (Node**)malloc(sizeof(Node*) * num_vertices);
  for (int i = 0; i < num_vertices; i++) {
    graph->adjacency_list[i] = NULL;
  }
  return graph;
}

void add_edge(Graph* graph, int src, int dest) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->value = dest;
  node->next = graph->adjacency_list[src];
  graph->adjacency_list[src] = node;
}

void remove_edge(Graph* graph, int src, int dest) {
  Node* node = graph->adjacency_list[src];
  Node* prev = NULL;
  while (node != NULL && node->value != dest) {
    prev = node;
    node = node->next;
  }
  if (node == NULL) {
    return;
  }
  if (prev == NULL) {
    graph->adjacency_list[src] = node->next;
  } else {
    prev->next = node->next;
  }
  free(node);
}

void print_graph(Graph* graph) {
  for (int i = 0; i < graph->num_vertices; i++) {
    printf("%d: ", i);
    Node* node = graph->adjacency_list[i];
    while (node != NULL) {
      printf("%d ", node->value);
      node = node->next;
    }
    printf("\n");
  }
}

int main() {
  Graph* graph = create_graph(4, 5);
  add_edge(graph, 0, 1);
  add_edge(graph, 0, 2);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 0);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 3);
  print_graph(graph);
  remove_edge(graph, 2, 0);
  print_graph(graph);
  return 0;
}