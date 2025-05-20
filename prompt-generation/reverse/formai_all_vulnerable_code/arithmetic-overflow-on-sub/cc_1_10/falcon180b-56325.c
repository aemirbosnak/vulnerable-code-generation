//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int dest;
    int weight;
    int next;
} edge;

edge graph[MAX_EDGES];
int dist[MAX_NODES];
int prev[MAX_NODES];
int n;

int dijkstra(int start, int end) {
    int u, i, min_dist;
    int count = 0;
    for (u = 0; u < n; u++) {
        dist[u] = INF;
        prev[u] = -1;
    }
    dist[start] = 0;
    for (count = 0; count < n - 1; count++) {
        min_dist = INF;
        for (u = 0; u < n; u++) {
            if (dist[u] <= min_dist && prev[u]!= -1) {
                min_dist = dist[u];
                i = u;
            }
        }
        for (u = 0; u < n; u++) {
            if (graph[i].dest == u && (dist[graph[i].dest] > dist[u] + graph[i].weight)) {
                dist[u] = dist[i] + graph[i].weight;
                prev[u] = i;
            }
        }
    }
    return dist[end];
}

int main() {
    int i, j, u, v, w;
    int start, end;
    srand(time(NULL));
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &j);
    for (i = 0; i < j; i++) {
        printf("Enter edge %d details (node1 node2 weight): ", i + 1);
        scanf("%d %d %d", &u, &v, &w);
        graph[i].dest = v;
        graph[i].weight = w;
        graph[i].next = -1;
    }
    printf("Enter start node: ");
    scanf("%d", &start);
    printf("Enter end node: ");
    scanf("%d", &end);
    printf("Shortest path: %d\n", dijkstra(start, end));
    return 0;
}