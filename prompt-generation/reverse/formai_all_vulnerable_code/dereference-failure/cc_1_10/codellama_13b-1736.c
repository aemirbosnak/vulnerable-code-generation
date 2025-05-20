//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: rigorous
// Graph representation example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures to represent a graph node and an edge
typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Edge {
  int source;
  int destination;
  struct Edge* next;
} Edge;

// Function to create a new node
Node* createNode(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

// Function to create a new edge
Edge* createEdge(int source, int destination) {
  Edge* edge = (Edge*)malloc(sizeof(Edge));
  edge->source = source;
  edge->destination = destination;
  edge->next = NULL;
  return edge;
}

// Function to add a node to the graph
void addNode(Node** nodes, int data) {
  Node* node = createNode(data);
  node->next = *nodes;
  *nodes = node;
}

// Function to add an edge to the graph
void addEdge(Edge** edges, int source, int destination) {
  Edge* edge = createEdge(source, destination);
  edge->next = *edges;
  *edges = edge;
}

// Function to print the graph
void printGraph(Node* nodes, Edge* edges) {
  printf("Graph nodes:\n");
  for (Node* node = nodes; node != NULL; node = node->next) {
    printf("  %d\n", node->data);
  }
  printf("\n");
  printf("Graph edges:\n");
  for (Edge* edge = edges; edge != NULL; edge = edge->next) {
    printf("  (%d, %d)\n", edge->source, edge->destination);
  }
}

int main() {
  Node* nodes = NULL;
  Edge* edges = NULL;

  // Create nodes and edges
  addNode(&nodes, 1);
  addNode(&nodes, 2);
  addNode(&nodes, 3);
  addEdge(&edges, 1, 2);
  addEdge(&edges, 2, 3);
  addEdge(&edges, 3, 1);

  // Print the graph
  printGraph(nodes, edges);

  return 0;
}