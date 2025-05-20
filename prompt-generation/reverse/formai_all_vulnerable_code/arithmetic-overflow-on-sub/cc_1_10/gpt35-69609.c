//FormAI DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
   int V; // Number of vertices
   int E; // Number of edges
   int **adjMatrix; // Adjacency Matrix
} graph;

typedef struct edge {
   int src, dest, weight;
} edge;

// Function to create a new graph
graph* createGraph(int V, int E) {
   graph *g = (graph*) malloc(sizeof(graph));
   g->V = V;
   g->E = E;
   g->adjMatrix = (int**) malloc(V * sizeof(int*));
   for (int i = 0; i < V; i++) {
      g->adjMatrix[i] = (int*) malloc(V * sizeof(int));
      for (int j = 0; j < V; j++) {
         g->adjMatrix[i][j] = 0;
      }
   }
   return g;
}

// Function to add a new edge to the graph
void addEdge(graph *g, int src, int dest, int weight) {
   g->adjMatrix[src][dest] = weight;
   g->adjMatrix[dest][src] = weight;
}

// Function to print the adjacency matrix of the graph
void printGraph(graph *g) {
   printf("\nAdjacency Matrix:\n");
   for (int i = 0; i < g->V; i++) {
      for (int j = 0; j < g->V; j++) {
         printf("%d ", g->adjMatrix[i][j]);
      }
      printf("\n");
   }
}

// Main Function
int main() {
   int V, E;
   printf("Enter the number of vertices in the graph: ");
   scanf("%d", &V);
   printf("Enter the number of edges in the graph: ");
   scanf("%d", &E);
   graph *g = createGraph(V, E);
   for (int i = 0; i < E; i++) {
      int src, dest, weight;
      printf("\nEnter details of edge %d:\n", i + 1);
      printf("Source node: ");
      scanf("%d", &src);
      printf("Destination node: ");
      scanf("%d", &dest);
      printf("Weight of the edge: ");
      scanf("%d", &weight);
      addEdge(g, src - 1, dest - 1, weight);
      printf("\nEdge %d added successfully!\n", i + 1);
   }
   printGraph(g);
   return 0;
}