//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: asynchronous
/// Example Graph Representation in C

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a graph node
struct GraphNode {
  int data;
  struct GraphNode* next;
};

// Define a structure to represent a graph
struct Graph {
  int numNodes;
  struct GraphNode* nodes;
};

// Function to add a new node to the graph
void addNode(struct Graph* graph, int data) {
  // Allocate memory for the new node
  struct GraphNode* node = malloc(sizeof(struct GraphNode));

  // Initialize the node's data and next pointer
  node->data = data;
  node->next = NULL;

  // Add the node to the graph
  graph->nodes = node;
  graph->numNodes++;
}

// Function to add a new edge between two nodes
void addEdge(struct Graph* graph, int src, int dest) {
  // Find the source and destination nodes
  struct GraphNode* srcNode = NULL;
  struct GraphNode* destNode = NULL;

  for (int i = 0; i < graph->numNodes; i++) {
    if (graph->nodes[i].data == src) {
      srcNode = &graph->nodes[i];
    } else if (graph->nodes[i].data == dest) {
      destNode = &graph->nodes[i];
    }
  }

  // Add the edge to the graph
  srcNode->next = destNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
  for (int i = 0; i < graph->numNodes; i++) {
    struct GraphNode* node = &graph->nodes[i];
    printf("%d -> ", node->data);
    while (node->next != NULL) {
      node = node->next;
      printf("%d -> ", node->data);
    }
    printf("\n");
  }
}

int main() {
  // Create a new graph
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numNodes = 0;
  graph->nodes = NULL;

  // Add nodes and edges to the graph
  addNode(graph, 1);
  addNode(graph, 2);
  addNode(graph, 3);
  addNode(graph, 4);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 3);
  addEdge(graph, 2, 4);
  addEdge(graph, 3, 4);

  // Print the graph
  printGraph(graph);

  return 0;
}