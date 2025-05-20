//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int u, v, w;
} Edge;

Edge graph[MAX_EDGES];
int n, m, start, end;
int dist[MAX_NODES];
int parent[MAX_NODES];
int visited[MAX_NODES];

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            u = graph[j].u;
            v = graph[j].v;
            if (dist[u]!= INF && dist[u] + graph[j].w < dist[v]) {
                dist[v] = dist[u] + graph[j].w;
                parent[v] = u;
            }
        }
    }
}

void printPath(int end) {
    if (parent[end] == -1) {
        printf("No path found.\n");
        return;
    }
    printf("Path: ");
    int u = end;
    while (u!= -1) {
        printf("%d ", u);
        u = parent[u];
    }
    printf("\n");
}

int main() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (u v w):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &graph[i].u, &graph[i].v, &graph[i].w);
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("Enter the ending node: ");
    scanf("%d", &end);

    printPath(end);

    return 0;
}