//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define V 4

int dist[V][V];
int parent[V][V];

void dijkstra(int graph[V][V], int src) {
    int i, j, u, v;
    int min_dist = INF, min_node;

    for (i = 0; i < V; i++) {
        dist[src][i] = graph[src][i];
        parent[src][i] = -1;
    }

    dist[src][src] = 0;

    for (i = 1; i < V; i++) {
        min_dist = INF;
        min_node = -1;

        for (j = 0; j < V; j++) {
            if (dist[src][j]!= INF && dist[src][j] + dist[j][i] < min_dist) {
                min_dist = dist[src][j] + dist[j][i];
                min_node = j;
            }
        }

        for (j = 0; j < V; j++) {
            if (dist[src][j]!= INF && dist[src][j] + dist[j][i] == min_dist) {
                parent[i][j] = j;
            }
        }

        dist[i][i] = 0;
    }
}

void printSolution(int parent[V][V], int n) {
    int i, j;

    for (i = 1; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (parent[i][j]!= -1) {
                printf("%d -> %d\n", i, parent[i][j]);
            }
        }
    }
}

int main() {
    int graph[V][V] = { { 0, 2, INF, 4 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };
    int src, dest;

    printf("Enter the source and destination nodes: ");
    scanf("%d %d", &src, &dest);

    dijkstra(graph, src);

    printf("\nShortest path from node %d to node %d: ", src, dest);
    printSolution(parent, V);

    return 0;
}