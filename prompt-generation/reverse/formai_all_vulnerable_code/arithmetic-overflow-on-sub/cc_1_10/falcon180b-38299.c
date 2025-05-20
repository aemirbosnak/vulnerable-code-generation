//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_V 100

struct edge {
    int u, v;
    int weight;
};

int n, m, s, t;
int dist[MAX_V];
int pred[MAX_V];
int visited[MAX_V];

void dijkstra(int graph[MAX_V][MAX_V], int start) {
    int u, v, i, min_dist;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        pred[i] = -1;
        visited[i] = 0;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        min_dist = INF;
        u = -1;

        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] <= min_dist) {
                min_dist = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u]!= INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pred[v] = u;
            }
        }
    }
}

void print_path(int path[], int start, int end) {
    if (pred[end] == -1) {
        printf("No path found.\n");
        return;
    }

    int v = end;

    while (v!= start) {
        printf("%d ", v);
        v = pred[v];
    }

    printf("%d\n", start);
}

int main() {
    int graph[MAX_V][MAX_V];
    int path[MAX_V];
    int u, v, w;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the start vertex: ");
    scanf("%d", &s);

    printf("Enter the end vertex: ");
    scanf("%d", &t);

    printf("Enter the edges (u, v, w):\n");

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
    }

    dijkstra(graph, s);

    printf("The shortest path from %d to %d is:\n", s, t);
    print_path(path, s, t);

    return 0;
}