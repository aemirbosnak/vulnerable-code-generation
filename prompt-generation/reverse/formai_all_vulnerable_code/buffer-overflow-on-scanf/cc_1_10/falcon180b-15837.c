//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define V 9
#define INF INT_MAX

int n, m;
int graph[V][V];
int dist[V];
int parent[V];
int sptSet[V];

void dijkstra(int src) {
    int u, minDist, i;
    for (i = 0; i < V; i++) {
        dist[i] = INF;
        sptSet[i] = 0;
    }
    dist[src] = 0;
    for (i = 0; i < V; i++) {
        minDist = INF;
        for (u = 0; u < V; u++) {
            if (graph[u][i] && dist[u]!= INF && dist[u] + graph[u][i] < minDist) {
                minDist = dist[u] + graph[u][i];
                parent[i] = u;
            }
        }
        dist[i] = minDist;
    }
}

void printSolution(int v) {
    int i;
    printf("\nVertex\t Distance from Source\tPath");
    for (i = 0; i < V; i++) {
        printf("\n%d\t\t%d\t\t", i, dist[i]);
        if (dist[i]!= INF) {
            printf("->");
            int j = i;
            while (j!= -1) {
                printf("%d", j);
                j = parent[j];
            }
        }
    }
}

int main() {
    int i, j, k, count = 0;
    printf("\nEnter number of vertices: ");
    scanf("%d", &n);
    printf("\nEnter number of edges: ");
    scanf("%d", &m);
    printf("\nEnter edges with their weights:\n");
    for (i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u][v] = w;
        graph[v][u] = w;
    }
    printf("\nEnter source vertex: ");
    scanf("%d", &k);
    dijkstra(k);
    printf("\nVertex\t Distance from Source\tPath");
    for (i = 0; i < V; i++) {
        printf("\n%d\t\t%d\t\t", i, dist[i]);
        if (dist[i]!= INF) {
            printf("->");
            int j = i;
            while (j!= -1) {
                printf("%d", j);
                j = parent[j];
            }
        }
    }
    return 0;
}