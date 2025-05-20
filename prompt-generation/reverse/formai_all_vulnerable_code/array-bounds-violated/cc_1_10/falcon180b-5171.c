//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAXV 100

int n, m;
int graph[MAXV][MAXV];
int dist[MAXV];
int parent[MAXV];

void dijkstra(int src) {
    int u, v;
    int i, j;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            if (graph[j][i] && dist[j]!= INF && dist[j] + graph[j][i] < dist[i]) {
                dist[i] = dist[j] + graph[j][i];
                parent[i] = j;
            }
        }
    }
}

void printPath(int v) {
    if (parent[v] == -1) {
        printf("There is no path from %d to %d\n", v, 0);
        return;
    }

    printf("Path from %d to %d: ", v, 0);

    int u = v;
    while (u!= -1) {
        printf("%d ", u);
        u = parent[u];
    }
    printf("\n");
}

int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (u, v, w):\n");

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int start, end;
    printf("Enter the start vertex: ");
    scanf("%d", &start);

    printf("Enter the end vertex: ");
    scanf("%d", &end);

    dijkstra(start);

    printf("The shortest path from %d to %d is:\n", start, end);
    printPath(end);

    return 0;
}