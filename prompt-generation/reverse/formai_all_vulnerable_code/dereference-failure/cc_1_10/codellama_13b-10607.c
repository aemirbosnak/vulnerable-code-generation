//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: unmistakable
// Unmistakable Graph Representation in C
#include <stdio.h>
#include <stdlib.h>

// Structure for a Graph Node
struct Node {
  int data;
  struct Node* next;
};

// Structure for a Graph
struct Graph {
  int numNodes;
  struct Node** nodes;
};

// Function to add a node to a graph
void addNode(struct Graph* graph, int data) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->data = data;
  node->next = NULL;
  graph->nodes[graph->numNodes++] = node;
}

// Function to add an edge between two nodes
void addEdge(struct Graph* graph, int src, int dest) {
  struct Node* srcNode = graph->nodes[src];
  struct Node* destNode = graph->nodes[dest];
  srcNode->next = destNode;
}

// Function to print a graph
void printGraph(struct Graph* graph) {
  for (int i = 0; i < graph->numNodes; i++) {
    struct Node* node = graph->nodes[i];
    printf("%d -> ", node->data);
    struct Node* next = node->next;
    while (next != NULL) {
      printf("%d -> ", next->data);
      next = next->next;
    }
    printf("\n");
  }
}

// Function to free a graph
void freeGraph(struct Graph* graph) {
  for (int i = 0; i < graph->numNodes; i++) {
    struct Node* node = graph->nodes[i];
    free(node);
  }
  free(graph->nodes);
  free(graph);
}

int main() {
  struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
  graph->numNodes = 0;
  graph->nodes = (struct Node**) malloc(sizeof(struct Node*) * 10);

  // Add nodes and edges to the graph
  addNode(graph, 1);
  addNode(graph, 2);
  addNode(graph, 3);
  addNode(graph, 4);
  addNode(graph, 5);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

  // Print the graph
  printGraph(graph);

  // Free the graph
  freeGraph(graph);

  return 0;
}