//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adj_mat[MAX_NODES][MAX_NODES];
int n;

void prim(int start) {
  int i, j, min_dist, min_vertex, dist[MAX_NODES], visited[MAX_NODES], previous[MAX_NODES];

  for (i = 0; i < n; i++) {
    dist[i] = 999; // set all initial distances to infinity
    visited[i] = 0; // set all initial visited flags to false
    previous[i] = -1; // set all initial previous vertices to -1
  }

  dist[start] = 0; // set the distance of the start node to 0

  for (i = 0; i < n-1; i++) { // loop through n-1 times
    min_dist = 999;

    for (j = 0; j < n; j++) { // find the unvisited node with the smallest distance
      if (visited[j] == 0 && dist[j] < min_dist) {
        min_dist = dist[j];
        min_vertex = j;
      }
    }

    visited[min_vertex] = 1; // mark the node as visited

    for (j = 0; j < n; j++) { // update the distances of the neighboring nodes
      if (adj_mat[min_vertex][j] != 0 && visited[j] == 0 && adj_mat[min_vertex][j] < dist[j]) {
        dist[j] = adj_mat[min_vertex][j];
        previous[j] = min_vertex;
      }
    }
  }

  // print the resulting minimum spanning tree
  printf("Minimum Spanning Tree:\n");
  printf("Edge    Weight\n");
  for (i = 1; i < n; i++) {
    printf("%d - %d   %d\n", previous[i]+1, i+1, adj_mat[i][previous[i]]);
  }
}

int main() {
  int i, j, start;

  printf("Enter the number of nodes: ");
  scanf("%d", &n);

  printf("Enter the adjacency matrix:\n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &adj_mat[i][j]);
    }
  }

  printf("Enter the starting vertex: ");
  scanf("%d", &start);

  prim(start-1);

  return 0;
}