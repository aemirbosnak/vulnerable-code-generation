//FormAI DATASET v1.0 Category: Graph representation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

#define MAX 20      //Maximum number of vertices possible
#define INF 9999    //Extreme value to represent infinity

int G[MAX][MAX], spanning[MAX][MAX], n;

int prim() {
   int parent[MAX], cost[MAX];
   int i, j, minDistance, u, v;
   int visited[MAX] = {0};  //Initialize visited array to 0
   
   for(i = 0; i < n; i++) {   //Initialize cost and parent arrays
      cost[i] = INF;
      parent[i] = -1;
   }

   cost[0] = 0;   //Starting vertex cost is 0
   parent[0] = -1;   //Starting vertex doesn't have any parent

   for(i = 0; i < n-1; i++) {
      minDistance = INF;
      for(j = 0; j < n; j++) {   //Find the minimum cost unvisited vertex
         if(visited[j] == 0 && cost[j] < minDistance) {
            minDistance = cost[j];
            u = j;
         }
      }

      visited[u] = 1;   //Mark current vertex as visited

      for(v = 0; v < n; v++) {   //Update the cost and parent arrays for adjacent vertices
         if(G[u][v] && visited[v] == 0 && G[u][v] < cost[v]) {
            parent[v] = u;
            cost[v] = G[u][v];
         }
      }
   }

   //Generate the spanning tree
   int e = 0;
   for(i = 0; i < n; i++) {
      if(parent[i] != -1) {
         spanning[e][0] = parent[i];
         spanning[e][1] = i;
         e++;
      }
   }

   //Print the spanning tree
   printf("\nSpanning Tree:\n");
   for(i = 0; i < e; i++) {
      printf("%d - %d\n", spanning[i][0], spanning[i][1]);
   }
   return 0;
}

int main() {
   printf("Enter the number of vertices: ");
   scanf("%d", &n);
   printf("Enter the adjacency matrix:\n");
   
   int i, j;
   for(i = 0; i < n; i++) {
      for(j = 0; j < n; j++) {
         scanf("%d", &G[i][j]);
      }
   }

   prim();
   return 0;
}