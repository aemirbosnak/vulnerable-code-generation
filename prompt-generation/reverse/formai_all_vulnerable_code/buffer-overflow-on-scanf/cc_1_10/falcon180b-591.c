//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 999999
#define MAX 100
#define MAX_VERTEX 101

int n, m;
int graph[MAX][MAX];
int dist[MAX_VERTEX];
int parent[MAX_VERTEX];

void dijkstra(int start) {
    int u, v, i, min_dist, k;
    int visited[MAX_VERTEX];

    for (u = 0; u < n; u++) {
        dist[u] = INF;
        parent[u] = -1;
        visited[u] = false;
    }

    dist[start] = 0;

    for (k = 0; k < n - 1; k++) {
        min_dist = INF;
        u = -1;

        for (i = 0; i < n; i++) {
            if (!visited[i] && dist[i] <= min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }

        visited[u] = true;

        for (v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u]!= INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }
}

int main() {
    int i, j, start;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges and their weights:\n");

    for (i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &start);

    dijkstra(start);

    printf("Vertex\t Distance from Source\tPath\n");
    for (i = 0; i < n; i++) {
        if (i!= start) {
            printf("%d\t\t%d\t\t", i, dist[i]);
            j = i;
            while (parent[j]!= -1) {
                printf("%d ", parent[j]);
                j = parent[j];
            }
            printf("\n");
        }
    }

    return 0;
}