//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: retro
// Retro-style C Graph Representation Program
  #include <stdio.h>
  #include <stdlib.h>

  typedef struct Node {
    int data;
    struct Node* next;
  } Node;

  typedef struct Graph {
    int num_vertices;
    int num_edges;
    Node** adjacency_list;
  } Graph;

  // Initialize the graph
  void init_graph(Graph* graph, int num_vertices, int num_edges) {
    graph->num_vertices = num_vertices;
    graph->num_edges = num_edges;
    graph->adjacency_list = malloc(num_vertices * sizeof(Node*));
    for (int i = 0; i < num_vertices; i++) {
      graph->adjacency_list[i] = NULL;
    }
  }

  // Add an edge to the graph
  void add_edge(Graph* graph, int src, int dest) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = dest;
    new_node->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = new_node;
  }

  // Print the graph
  void print_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
      printf("%d: ", i);
      Node* node = graph->adjacency_list[i];
      while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
      }
      printf("\n");
    }
  }

  // Free the graph
  void free_graph(Graph* graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
      Node* node = graph->adjacency_list[i];
      while (node != NULL) {
        Node* temp = node->next;
        free(node);
        node = temp;
      }
    }
    free(graph->adjacency_list);
    free(graph);
  }

  int main() {
    Graph* graph = malloc(sizeof(Graph));
    init_graph(graph, 5, 5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 3, 4);
    print_graph(graph);
    free_graph(graph);
    return 0;
  }