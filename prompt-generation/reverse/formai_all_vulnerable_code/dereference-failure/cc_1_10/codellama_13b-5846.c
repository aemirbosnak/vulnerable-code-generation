//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: Donald Knuth
#include <stdio.h>
  #include <stdlib.h>
  #include <stdbool.h>

  typedef struct node {
    int data;
    struct node *next;
  } Node;

  typedef struct graph {
    int num_nodes;
    int num_edges;
    Node *nodes[];
  } Graph;

  void add_node(Graph *graph, int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    graph->nodes[graph->num_nodes++] = node;
  }

  void add_edge(Graph *graph, int source, int destination) {
    Node *source_node = graph->nodes[source];
    Node *destination_node = graph->nodes[destination];
    source_node->next = destination_node;
    graph->num_edges++;
  }

  void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_nodes; i++) {
      Node *node = graph->nodes[i];
      printf("%d: ", i);
      while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
      }
      printf("\n");
    }
  }

  int main() {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_nodes = 0;
    graph->num_edges = 0;
    add_node(graph, 1);
    add_node(graph, 2);
    add_node(graph, 3);
    add_edge(graph, 0, 1);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 0);
    print_graph(graph);
    return 0;
  }