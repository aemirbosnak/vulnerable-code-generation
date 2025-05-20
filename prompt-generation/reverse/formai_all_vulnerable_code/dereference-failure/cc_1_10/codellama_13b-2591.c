//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: creative
// Graph representation in a creative style
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a graph node
struct Node {
  int value;
  struct Node* next;
};

// Define a structure for a graph
struct Graph {
  struct Node* nodes;
  int numNodes;
};

// Function to create a new graph
struct Graph* createGraph(int numNodes) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->nodes = malloc(numNodes * sizeof(struct Node));
  graph->numNodes = numNodes;
  return graph;
}

// Function to add a node to a graph
void addNode(struct Graph* graph, int value) {
  struct Node* node = malloc(sizeof(struct Node));
  node->value = value;
  node->next = graph->nodes;
  graph->nodes = node;
}

// Function to add an edge between two nodes
void addEdge(struct Graph* graph, int node1, int node2) {
  struct Node* node = graph->nodes;
  while (node != NULL) {
    if (node->value == node1) {
      struct Node* newNode = malloc(sizeof(struct Node));
      newNode->value = node2;
      newNode->next = node->next;
      node->next = newNode;
      break;
    }
    node = node->next;
  }
}

// Function to print the graph
void printGraph(struct Graph* graph) {
  struct Node* node = graph->nodes;
  while (node != NULL) {
    printf("%d ", node->value);
    node = node->next;
  }
  printf("\n");
}

// Function to free the graph
void freeGraph(struct Graph* graph) {
  struct Node* node = graph->nodes;
  while (node != NULL) {
    struct Node* next = node->next;
    free(node);
    node = next;
  }
  free(graph);
}

int main() {
  // Create a graph with 3 nodes
  struct Graph* graph = createGraph(3);

  // Add nodes and edges
  addNode(graph, 1);
  addNode(graph, 2);
  addNode(graph, 3);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 3);

  // Print the graph
  printGraph(graph);

  // Free the graph
  freeGraph(graph);

  return 0;
}