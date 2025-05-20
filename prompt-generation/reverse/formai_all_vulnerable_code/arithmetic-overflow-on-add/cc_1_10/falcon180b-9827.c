//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_V 500
#define MAX_E 1000
#define INF 99999999
#define EPS 1e-8

typedef struct {
    int v;
    int w;
    int next;
} Edge;

Edge edge[MAX_E];
int adj[MAX_V];
int dist[MAX_V];
int n, m;

void addEdge(int u, int v, int w) {
    edge[n].v = v;
    edge[n].w = w;
    edge[n].next = adj[u];
    adj[u] = n++;
}

void dijkstra(int start) {
    int i, u, v;
    int minDist = INF, minIndex;

    for (i = 0; i < n; i++) {
        dist[i] = INF;
        adj[i] = -1;
    }

    dist[start] = 0;

    for (i = 0; i < n - 1; i++) {
        minDist = INF;
        minIndex = -1;

        for (u = 0; u < n; u++) {
            if (dist[u] < minDist && adj[u]!= -1) {
                minDist = dist[u];
                minIndex = u;
            }
        }

        u = minIndex;

        for (v = 0; v < n; v++) {
            if ((dist[u] + edge[minIndex].w) < dist[v]) {
                dist[v] = dist[u] + edge[minIndex].w;
                adj[v] = minIndex;
            }
        }
    }
}

int main() {
    int i, u, v, w;

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    dijkstra(0);

    printf("Vertex\t Distance from Source\n");

    for (i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }

    return 0;
}