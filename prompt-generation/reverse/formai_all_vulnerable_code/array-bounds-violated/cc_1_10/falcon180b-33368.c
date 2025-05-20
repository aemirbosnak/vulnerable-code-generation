//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_NEIGHBORS 4

typedef struct {
    int node;
    int weight;
} neighbor;

neighbor graph[MAX_NODES][MAX_NEIGHBORS];
int nnodes;

void add_neighbor(int node1, int node2, int weight) {
    int i = 0;
    while (i < nnodes && graph[node1][i].node!= node2) {
        i++;
    }
    if (i == nnodes) {
        nnodes++;
        graph[node1][i].node = node2;
        graph[node1][i].weight = weight;
    } else {
        graph[node1][i].weight = weight;
    }
}

void dijkstra(int start, int end) {
    int i, j, u, v;
    int dist[MAX_NODES];
    int visited[MAX_NODES];
    int prev[MAX_NODES];

    for (i = 0; i < nnodes; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
        prev[i] = -1;
    }

    dist[start] = 0;
    visited[start] = 1;

    for (i = 0; i < nnodes - 1; i++) {
        int min_dist = INT_MAX;
        int u = -1;

        for (j = 0; j < nnodes; j++) {
            if (!visited[j] && dist[j] < min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (j = 0; j < nnodes; j++) {
            if (graph[u][j].node!= -1) {
                int new_dist = dist[u] + graph[u][j].weight;

                if (new_dist < dist[graph[u][j].node]) {
                    dist[graph[u][j].node] = new_dist;
                    prev[graph[u][j].node] = u;
                }
            }
        }
    }

    printf("Shortest path from %d to %d:\n", start, end);
    i = end;
    while (i!= -1) {
        printf("%d ", i);
        i = prev[i];
    }
    printf("\n");
}

int main() {
    int i, j;

    nnodes = 6;

    add_neighbor(0, 1, 4);
    add_neighbor(0, 2, 2);
    add_neighbor(1, 2, 1);
    add_neighbor(1, 3, 6);
    add_neighbor(2, 3, 3);
    add_neighbor(2, 4, 5);
    add_neighbor(3, 4, 1);
    add_neighbor(3, 5, 2);
    add_neighbor(4, 5, 3);

    dijkstra(0, 5);

    return 0;
}