//FormAI DATASET v1.0 Category: Graph representation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct node {
  int vertex;
  struct node* next;
} node;

typedef struct graph {
  int num_vertices;
  node* adj_list[MAX_VERTICES];
} graph;

node* create_node(int v) {
  node* new_node = (node*) malloc(sizeof(node));
  new_node->next = NULL;
  new_node->vertex = v;
  return new_node;
}

graph* create_graph(int n) {
  graph* new_graph = (graph*)malloc(sizeof(graph));
  new_graph->num_vertices = n;
  for (int i = 0; i < n; i++) {
    new_graph->adj_list[i] = NULL;
  }
  return new_graph;
}

void add_edge(graph* g, int start, int end) {
  node* new_node = create_node(end);
  new_node->next = g->adj_list[start];
  g->adj_list[start] = new_node;

  new_node = create_node(start);
  new_node->next = g->adj_list[end];
  g->adj_list[end] = new_node;
}

void print_graph(graph* g) {
  printf("Adjacency List: \n");
  for (int i = 0; i < g->num_vertices; i++) {
    node* temp = g->adj_list[i];
    printf("Vertex %d: ", i);
    while (temp) {
      printf("%d -> ", temp->vertex);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main() {
  int n, e;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the number of edges: ");
  scanf("%d", &e);

  graph* g = create_graph(n);
  for (int i = 0; i < e; i++) {
    int start, end;
    printf("Enter edge %d start and end vertices: ", i + 1);
    scanf("%d %d", &start, &end);
    add_edge(g, start, end);
  }

  print_graph(g);

  return 0;
}