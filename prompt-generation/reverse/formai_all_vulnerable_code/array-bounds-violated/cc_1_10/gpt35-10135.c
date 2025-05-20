//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define MAX_DEGREE 100

typedef struct {
   int degree;
   int color;
   int adj[MAX_DEGREE];
} Vertex;

Vertex graph[MAX_VERTICES];
int current_color = 1;

void colorVertex(int v) {
   bool used[MAX_DEGREE];
   int i, j, k, c;

   while (true) {
      for (i = 0; i < graph[v].degree; i++)
         used[i] = false;

      for (i = 0; i < graph[v].degree; i++) {
         c = graph[graph[v].adj[i]].color;
         if (c != 0)
            used[c-1] = true;
      }

      j = 0;
      while (used[j] == true)
         j++;

      if (j == current_color) {
         printf("All %d colors have been used.\n", j);
         exit(1);
      }

      graph[v].color = j+1;
      if (v == MAX_VERTICES-1) {
         printf("Coloring complete!\n");
         exit(0);
      }

      colorVertex(v+1);
   }
}

int main() {
   int i, j;
   int num_vertices, num_edges;
   int v1, v2;

   printf("Enter the number of vertices in the graph: ");
   scanf("%d", &num_vertices);
   printf("Enter the number of edges in the graph: ");
   scanf("%d", &num_edges);

   for (i = 0; i < num_vertices; i++) {
      graph[i].degree = 0;
      graph[i].color = 0;
   }

   printf("Enter the edges (v1 v2):\n");
   for (i = 0; i < num_edges; i++) {
      scanf("%d %d", &v1, &v2);
      graph[v1].adj[graph[v1].degree++] = v2;
      graph[v2].adj[graph[v2].degree++] = v1;
   }

   colorVertex(0);

   printf("Vertex colors:\n");
   for (i = 0; i < num_vertices; i++)
      printf("  Vertex %d: Color %d\n", i, graph[i].color);

   return 0;
}