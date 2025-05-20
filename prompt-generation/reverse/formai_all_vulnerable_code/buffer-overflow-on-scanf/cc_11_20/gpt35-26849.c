//FormAI DATASET v1.0 Category: Graph representation ; Style: curious
#include <stdio.h>

int main() {
   int graph[5][5];

   // This block of code prompts the user to input values for the graph
   printf("Please enter values for the graph:\n");
   for(int i=0; i<5; i++) {
      for(int j=0; j<5; j++) {
         printf("Graph[%d][%d]: ", i, j);
         scanf("%d", &graph[i][j]);
      }
   }

   // This block of code prints out the graph in a unique way
   printf("\nHere is your graph:\n");
   printf("     0  1  2  3  4\n");
   printf("   ----------------\n");
   for(int i=0; i<5; i++) {
      printf("%d | ", i);
      for(int j=0; j<5; j++) {
         if(graph[i][j] == 1)
            printf("*  ");
         else
            printf("   ");
      }
      printf("\n");
   }
   printf("\n");

   // This block of code finds all the nodes that have a degree of 3 or greater
   printf("Nodes with a degree of 3 or greater:\n");
   for(int i=0; i<5; i++) {
      int degree = 0;
      for(int j=0; j<5; j++) {
         if(graph[i][j] == 1)
            degree++;
      }
      if(degree >= 3)
         printf("%d\n", i);
   }

   // This block of code finds all the triangles in the graph
   printf("\nTriangles in the graph:\n");
   for(int i=0; i<5; i++) {
      for(int j=0; j<5; j++) {
         if(graph[i][j] == 1) {
            for(int k=0; k<5; k++) {
               if(graph[j][k] == 1 && graph[i][k] == 1)
                  printf("(%d,%d,%d)\n", i, j, k);
            }
         }
      }
   }

   return 0;
}