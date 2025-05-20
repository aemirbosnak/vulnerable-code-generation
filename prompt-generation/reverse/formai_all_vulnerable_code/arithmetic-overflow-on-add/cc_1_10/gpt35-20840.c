//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_NODE 100
#define MAX_LEVEL 10

int circuit[MAX_LEVEL][MAX_NODE];

int main()
{
   int num_nodes, num_levels;
   int i, j;

   printf("Enter the number of nodes in the circuit: ");
   scanf("%d", &num_nodes);

   num_levels = ceil(log2(num_nodes + 1));

   // Initialize the circuit array to all zeros
   for (i = 0; i < MAX_LEVEL; i++) {
      for (j = 0; j < MAX_NODE; j++) {
         circuit[i][j] = 0;
      }
   }

   // Build the circuit
   for (i = 0; i < num_levels; i++) {
      int num_nodes_this_level = pow(2, i);
      int start_node = pow(2, i) - 1;

      for (j = start_node; j < start_node + num_nodes_this_level; j++) {
         if (j == start_node) {
            // First node on a level
            circuit[i][j] = j + num_nodes_this_level;
         } else if (j == start_node + num_nodes_this_level - 1) {
            // Last node on a level
            circuit[i][j] = j - num_nodes_this_level + 1;
         } else {
            // Middle nodes on a level
            if (j % 2 == 0) {
               circuit[i][j] = j + num_nodes_this_level;
            } else {
               circuit[i][j] = j - num_nodes_this_level + 1;
            }
         }
      }
   }

   // Print the circuit
   printf("Circuit:\n");
   for (i = 0; i < num_levels; i++) {
      for (j = 0; j < pow(2, i); j++) {
         printf("%d ", circuit[i][j]);
      }
      printf("\n");
   }

   return 0;
}