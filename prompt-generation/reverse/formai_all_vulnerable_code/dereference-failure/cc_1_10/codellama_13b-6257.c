//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: random
// Graph representation example program

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
} Node;

typedef struct Graph {
  Node** adjacencyList;
  int numVertices;
  int numEdges;
} Graph;

// function to create a new graph
Graph* createGraph(int numVertices) {
  Graph* graph = malloc(sizeof(Graph));
  graph->adjacencyList = malloc(numVertices * sizeof(Node*));
  graph->numVertices = numVertices;
  graph->numEdges = 0;
  for (int i = 0; i < numVertices; i++) {
    graph->adjacencyList[i] = NULL;
  }
  return graph;
}

// function to add an edge to a graph
void addEdge(Graph* graph, int src, int dest) {
  Node* newNode = malloc(sizeof(Node));
  newNode->data = dest;
  newNode->next = graph->adjacencyList[src];
  graph->adjacencyList[src] = newNode;
  graph->numEdges++;
}

// function to print the graph
void printGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* node = graph->adjacencyList[i];
    printf("Vertex %d: ", i);
    while (node != NULL) {
      printf("%d ", node->data);
      node = node->next;
    }
    printf("\n");
  }
}

// function to delete a graph
void deleteGraph(Graph* graph) {
  for (int i = 0; i < graph->numVertices; i++) {
    Node* node = graph->adjacencyList[i];
    while (node != NULL) {
      Node* temp = node;
      node = node->next;
      free(temp);
    }
  }
  free(graph->adjacencyList);
  free(graph);
}

// main function
int main() {
  Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 0);
  addEdge(graph, 2, 3);
  addEdge(graph, 3, 3);
  printGraph(graph);
  deleteGraph(graph);
  return 0;
}