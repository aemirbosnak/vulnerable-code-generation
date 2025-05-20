//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: detailed
#include <stdio.h>
#define MAX 1000

/* Function to find minimum of two numbers */
int min(int a, int b) {
   return (a < b) ? a : b;
}

/* Function for Kruskal's algorithm */
void kruskalMST(int edges[MAX][3], int vertices, int edgesNum) {

   int parent[MAX], rank[MAX];
   int i, j;

   /* Initialize sets as single element sets */
   for (i = 0; i < vertices; i++) {
      parent[i] = i;
      rank[i] = 0;
   }

   int edgeCount = 0;
   int mstWeight = 0;

   /* Loop until all edges are included in MST */
   while (edgeCount < vertices - 1 && edgesNum > 0) {

      /* Find edge with minimum weight */
      int minIndex = 0;
      for (i = 0; i < edgesNum; i++) {
         if (edges[i][2] < edges[minIndex][2])
            minIndex = i;
      }

      /* Remove edge from edges list */
      int u = edges[minIndex][0];
      int v = edges[minIndex][1];
      int w = edges[minIndex][2];

      edges[minIndex][2] = MAX;

      /* Find the parents of the edge's vertices */
      while (parent[u] != u) {
         u = parent[u];
      }

      while (parent[v] != v) {
         v = parent[v];
      }

      /* Check for cycle */
      if (u != v) {
         /* Add edge to MST */
         printf("(%d, %d) weight = %d\n", edges[minIndex][0], edges[minIndex][1], edges[minIndex][2]);
         edgeCount++;
         mstWeight += w;

         /* Union the sets */
         if (rank[u] < rank[v]) {
            parent[u] = v;
         }
         else if (rank[u] > rank[v]) {
            parent[v] = u;
         }
         else {
            parent[v] = u;
            rank[u]++;
         }
      }
   }

   /* Print the total weight of the MST */
   printf("Total weight of MST = %d\n", mstWeight);
}

int main() {

   int edges[MAX][3];
   int vertices, edgesNum;

   /* Read vertices and edges number from user */
   printf("Enter number of vertices: ");
   scanf("%d", &vertices);

   printf("Enter number of edges: ");
   scanf("%d", &edgesNum);

   /* Read edges from user */
   printf("Enter edges (src dest weight):\n");
   for (int i = 0; i < edgesNum; i++) {
      scanf("%d%d%d", &edges[i][0], &edges[i][1], &edges[i][2]);
   }

   /* Find minimum spanning tree using Kruskal's algorithm */
   kruskalMST(edges, vertices, edgesNum);

   return 0;
}