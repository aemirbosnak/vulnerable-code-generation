//Falcon-180B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX
#define MAX_V 100
#define MAX_E 10000

typedef struct {
    int v;
    int w;
    int next;
} Edge;

int dist[MAX_V];
int parent[MAX_V];
Edge edge[MAX_E];
int adj[MAX_V][MAX_V];
int V, E;

void dijkstra(int s) {
    int u, min_dist, i;
    for (u = 0; u < V; u++) {
        dist[u] = INF;
        parent[u] = -1;
    }
    dist[s] = 0;
    for (i = 0; i < V - 1; i++) {
        min_dist = INF;
        u = -1;
        for (int v = 0; v < V; v++) {
            if (dist[v] < min_dist && dist[v]!= INF) {
                min_dist = dist[v];
                u = v;
            }
        }
        dist[u] = INF;
        for (int v = 0; v < V; v++) {
            if (adj[u][v]!= INF && (dist[u] + adj[u][v]) < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
                parent[v] = u;
            }
        }
    }
}

void add_edge(int u, int v, int w) {
    edge[E].v = v;
    edge[E].w = w;
    edge[E].next = adj[u][v];
    adj[u][v] = E;
    E++;
}

int main() {
    int i, j, k, u, v, w;
    scanf("%d %d", &V, &E);
    for (i = 0; i < E; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(u, v, w);
        add_edge(v, u, w);
    }
    dijkstra(0);
    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < V; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
    return 0;
}