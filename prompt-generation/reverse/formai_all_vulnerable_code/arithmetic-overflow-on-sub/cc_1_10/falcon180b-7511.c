//Falcon-180B DATASET v1.0 Category: Educational ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 1000
#define MAX_EDGES 2000
#define INF 1e9

int n, m;
int adj[MAX_SIZE][MAX_EDGES];
int dist[MAX_SIZE];
int visited[MAX_SIZE];
int parent[MAX_SIZE];

void dijkstra(int start) {
    int i, j, u, v;
    for (i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
        parent[i] = -1;
    }
    dist[start] = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            if (dist[j] > dist[u] + adj[j][v]) {
                dist[j] = dist[u] + adj[j][v];
                parent[j] = u;
            }
        }
    }
}

int main() {
    int i, j, u, v, w;
    srand(time(NULL));
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    printf("Enter the edges (u, v, w):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        adj[u][i] = v;
        adj[v][i] = u;
        adj[u][i] = w;
    }
    int source;
    printf("Enter the source node: ");
    scanf("%d", &source);
    dijkstra(source);
    printf("Shortest distances from node %d:\n", source);
    for (i = 0; i < n; i++) {
        if (dist[i]!= INF) {
            printf("%d - %d\n", i, dist[i]);
        }
    }
    return 0;
}