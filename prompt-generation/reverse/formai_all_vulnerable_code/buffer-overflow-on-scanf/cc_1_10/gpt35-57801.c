//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NSIZE 20
#define MAX_LSIZE 20

#define MAX_NODES 100

int G[MAX_NODES][MAX_NODES];
int node_count = 0;
char nodes[MAX_NODES][MAX_NSIZE];

int getIndex(char node_name[]) {
   for(int i = 0; i < node_count; i++){
      if(strcmp(node_name, nodes[i]) == 0){
         return i;
      }
   }
   return -1;
}

void addNode(char node_name[]) {
   int index = getIndex(node_name);
   if(index == -1){
      strcpy(nodes[node_count++], node_name);
   }
}

void addEdge(char node_from[], char node_to[], int weight) {
   int index_from = getIndex(node_from);
   int index_to = getIndex(node_to);
   G[index_from][index_to] = weight;
}

void printTopology() {
   printf("\n Node \t\t Connections\n");
   for(int i = 0; i < node_count; i++){
      printf("%s \t\t ", nodes[i]);
      for(int j = 0; j< node_count; j++){
         if(G[i][j] != 0){
            printf("(%s - %d) ", nodes[j], G[i][j]);
         }
      }
      printf("\n");
   }
}

int main() {
   char node_from[MAX_NSIZE], node_to[MAX_NSIZE];
   int weight, num_edges;

   printf("Enter number of edges: ");
   scanf("%d", &num_edges);

   for (int i = 1; i <= num_edges; i++) {
      printf("\nEnter source, destination and weight of edge %d: ", i);
      scanf("%s %s %d", node_from, node_to, &weight);

      addNode(node_from);
      addNode(node_to);
      addEdge(node_from, node_to, weight);
   }

   printTopology();

   return 0;
}