//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
/*
 * Donald Knuth style example program for Minimum Spanning Tree Pathfinding Algorithm
 * 
 * This algorithm uses the Prim's algorithm to find the minimum spanning tree path.
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define V 10 // number of vertices in the graph

// function to find the minimum key value from the set of vertices not yet included in MST
int minKey(int key[], bool mstSet[])
{
   int min = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
      if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}

// function to print the final minimum spanning tree
void printMST(int parent[], int graph[V][V])
{
   printf("Edge \tWeight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
}

// function to calculate the minimum spanning tree path
void primMST(int graph[V][V])
{
   int parent[V]; // stores the constructed MST
   int key[V];    // values used to pick minimum weight edge in cut
   bool mstSet[V]; // marks the vertices included in MST

   // initialize all keys as infinite and mstSet[] as false
   for (int i = 0; i < V; i++)
      key[i] = INT_MAX, mstSet[i] = false;

   // always include first vertex in MST
   key[0] = 0; // make key 0 so that this vertex is picked first
   parent[0] = -1; // first node is always root of MST

   // the MST will have V vertices
   for (int count = 0; count < V - 1; count++)
   {
      // pick the minimum key vertex from the set of vertices not yet included in MST
      int u = minKey(key, mstSet);

      // add the picked vertex to the MST set
      mstSet[u] = true;

      // update the key values and parent index of the adjacent vertices of the picked vertex
      for (int v = 0; v < V; v++)

         // graph[u][v] is non-zero only for adjacent vertices of m
         // mstSet[v] is false for vertices not yet included in MST
         // key[v] updates only when graph[u][v] is smaller than key[v]
         if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            parent[v] = u, key[v] = graph[u][v];
   }

   // print the final minimum spanning tree
   printMST(parent, graph);
}

// driver function
int main()
{
   int graph[V][V] = {{0, 2, 0, 6, 0},
                      {2, 0, 3, 8, 5},
                      {0, 3, 0, 0, 7},
                      {6, 8, 0, 0, 9},
                      {0, 5, 7, 9, 0}};

   // call the primMST function to calculate the minimum spanning tree path
   primMST(graph);

   return 0;
}