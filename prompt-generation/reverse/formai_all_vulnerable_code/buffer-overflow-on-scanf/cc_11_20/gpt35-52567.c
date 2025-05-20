//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 50

int graph[MAX_NODES][MAX_NODES]; // adjacency matrix
int colors[MAX_NODES]; // color assignments for each node

int num_nodes; // number of nodes in the graph

int main() {
   printf("Enter the number of nodes (up to %d): ", MAX_NODES);
   scanf("%d", &num_nodes);

   // read in the adjacency matrix
   printf("Enter the adjacency matrix (0 if no edge, 1 if edge):\n");
   for (int i = 0; i < num_nodes; i++) {
      for (int j = 0; j < num_nodes; j++) {
         scanf("%d", &graph[i][j]);
      }
   }

   // initialize all colors to -1 (unassigned)
   for (int i = 0; i < num_nodes; i++) {
      colors[i] = -1;
   }

   // assign colors to each node
   for (int i = 0; i < num_nodes; i++) {
      // check neighboring nodes for their colors
      int available_colors[MAX_NODES]; // list of colors that are available for this node
      for (int j = 0; j < num_nodes; j++) {
         available_colors[j] = 1; // set all colors to available
      }
      for (int j = 0; j < num_nodes; j++) {
         if (graph[i][j] && colors[j] != -1) {
            // if there is an edge to a colored node, mark that color as unavailable
            available_colors[colors[j]] = 0;
         }
      }

      // assign the smallest available color to this node
      for (int j = 0; j < num_nodes; j++) {
         if (available_colors[j]) {
            colors[i] = j;
            break;
         }
      }
   }

   // print out the color assignments
   printf("\nNode colors:\n");
   for (int i = 0; i < num_nodes; i++) {
      printf("Node %d: color %d\n", i, colors[i]);
   }

   return 0;
}