//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

int n, m;
int graph[100][100];
int dist[100];
int parent[100];

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    int sptSet[n];
    int s = 0;
    sptSet[s] = start;

    while (s < n - 1) {
        int u = minDistance(dist, sptSet, s);
        sptSet[s++] = u;

        for (v = 0; v < n; v++) {
            if ((graph[u][v]!= INF) && (dist[u]!= INF) && (dist[u] + graph[u][v] < dist[v])) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

int minDistance(int dist[], int sptSet[], int V) {
    int min = INF, min_index;

    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

int main() {
    int start, end;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the graph\n");
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }

    return 0;
}