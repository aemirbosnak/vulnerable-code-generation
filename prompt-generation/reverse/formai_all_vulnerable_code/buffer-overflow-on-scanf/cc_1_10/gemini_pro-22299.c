//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

typedef struct graph {
  int numVertices;
  node **adjLists;
} graph;

graph *createGraph(int numVertices) {
  graph *g = malloc(sizeof(graph));
  g->numVertices = numVertices;
  g->adjLists = malloc(numVertices * sizeof(node *));
  for (int i = 0; i < numVertices; i++) {
    g->adjLists[i] = NULL;
  }
  return g;
}

void addEdge(graph *g, int src, int dest) {
  node *newNode = malloc(sizeof(node));
  newNode->data = dest;
  newNode->next = g->adjLists[src];
  g->adjLists[src] = newNode;
}

void printGraph(graph *g) {
  for (int i = 0; i < g->numVertices; i++) {
    node *temp = g->adjLists[i];
    printf("\nAdjacency list of vertex %d\n", i);
    while (temp) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}

int main() {
  int numVertices;
  printf("Enter the number of vertices: ");
  scanf("%d", &numVertices);
  graph *g = createGraph(numVertices);
  int numEdges;
  printf("Enter the number of edges: ");
  scanf("%d", &numEdges);
  for (int i = 0; i < numEdges; i++) {
    int src, dest;
    printf("Enter the source and destination vertices of edge %d: ", i + 1);
    scanf("%d %d", &src, &dest);
    addEdge(g, src, dest);
  }
  printGraph(g);
  return 0;
}