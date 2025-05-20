//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_V 1000
#define MAX_E 5000
#define INF 0x3f3f3f3f

int V, E;
int adj[MAX_V][MAX_V];
int dist[MAX_V];
int visited[MAX_V];

void init() {
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = INF;
        }
    }
}

void addEdge(int u, int v, int w) {
    adj[u][v] = w;
}

void dijkstra(int s) {
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[s] = 0;

    int u, v, w;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j]!= INF) {
                u = i;
                v = j;
                w = adj[i][j];

                if (dist[u]!= INF && dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
    }
}

int main() {
    int u, v, w;

    scanf("%d", &V);
    init();

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &w);
            addEdge(i, j, w);
        }
    }

    scanf("%d", &E);

    for (int i = 0; i < E; i++) {
        scanf("%d%d", &u, &v);
        addEdge(u, v, 0);
    }

    int s, t;
    scanf("%d%d", &s, &t);

    dijkstra(s);

    printf("%d\n", dist[t]);

    return 0;
}