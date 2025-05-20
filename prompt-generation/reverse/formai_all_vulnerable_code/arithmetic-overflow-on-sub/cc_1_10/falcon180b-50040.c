//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF INT_MAX

typedef struct {
    int to;
    int cost;
} Edge;

int n, m, start, end, path[MAX_NODES], parent[MAX_NODES];
Edge graph[MAX_EDGES];

void dijkstra(int start) {
    int i, j, u, v, min_dist;
    for (i = 0; i < n; i++) {
        path[i] = INF;
        parent[i] = -1;
    }
    path[start] = 0;
    for (i = 0; i < n - 1; i++) {
        min_dist = INF;
        for (j = 0; j < n; j++) {
            if (path[j] < min_dist && parent[j]!= -1) {
                u = j;
                min_dist = path[j];
            }
        }
        for (j = 0; j < n; j++) {
            if (graph[u].to == j && graph[u].cost!= INF && (graph[u].cost + path[u]) < path[j]) {
                path[j] = graph[u].cost + path[u];
                parent[j] = u;
            }
        }
    }
}

int main() {
    int i, j, k, min_cost, total_cost = 0;
    srand(time(NULL));
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &graph[i].to, &graph[i].cost, &k);
        total_cost += k;
        graph[i].cost += rand() % k;
    }
    printf("Total cost: %d\n", total_cost);
    dijkstra(0);
    printf("Shortest path from node 0 to node %d:\n", end);
    j = end;
    while (j!= -1) {
        printf("%d ", j);
        j = parent[j];
    }
    printf("\nTotal cost: %d\n", path[end]);
    return 0;
}