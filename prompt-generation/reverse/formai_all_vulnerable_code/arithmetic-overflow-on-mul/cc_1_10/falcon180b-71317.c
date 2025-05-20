//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int node;
    int weight;
} Edge;

Edge graph[MAX_EDGES];
int n, m;
int dist[MAX_NODES];
int prev[MAX_NODES];

void dijkstra(int start) {
    int i, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        prev[i] = -1;
    }
    dist[start] = 0;
    int unvisited = n - 1;

    while (unvisited > 0) {
        int min_dist = INF;
        int u = -1;
        for (i = 0; i < n; i++) {
            if (dist[i] < min_dist && dist[i]!= INF && unvisited > 0) {
                min_dist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        unvisited--;

        for (v = 0; v < n; v++) {
            if (graph[u * n + v].weight!= INF) {
                int new_dist = dist[u] + graph[u * n + v].weight;
                if (new_dist < dist[v]) {
                    dist[v] = new_dist;
                    prev[v] = u;
                }
            }
        }
    }
}

int main() {
    srand(time(0));
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u * n + v].node = v;
        graph[u * n + v].weight = w;
        graph[(v + n - 1) * n + u].node = u;
        graph[(v + n - 1) * n + u].weight = w;
    }

    int start, end;
    scanf("%d %d", &start, &end);

    dijkstra(start);

    printf("Shortest path from %d to %d: ", start, end);
    if (dist[end] == INF) {
        printf("No path\n");
    } else {
        int v = end;
        while (v!= -1) {
            printf("%d ", v);
            v = prev[v];
        }
        printf("\n");
    }

    return 0;
}