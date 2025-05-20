//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTEX 1000
#define MAX_EDGE 2000
#define INF 9999999

typedef struct {
    int v;
    int w;
} Edge;

void addEdge(Edge e[], int v, int w) {
    e[v].v = v;
    e[v].w = w;
    e[w].v = v;
    e[w].w = w;
}

void dijkstra(int v, int dist[], Edge e[]) {
    int u, w, i;
    int minDist = INF;
    int nextNode = -1;

    for (i = 0; i < v; i++) {
        dist[i] = INF;
    }

    dist[0] = 0;

    for (i = 0; i < v - 1; i++) {
        minDist = INF;
        nextNode = -1;

        for (u = 0; u < v; u++) {
            if (dist[u] < minDist && dist[u]!= INF) {
                minDist = dist[u];
                nextNode = u;
            }
        }

        for (w = 0; w < v; w++) {
            if (e[nextNode].v == w) {
                if (dist[nextNode] + e[nextNode].w < dist[w]) {
                    dist[w] = dist[nextNode] + e[nextNode].w;
                }
            }
        }
    }
}

int main() {
    int v, e, u, w, i, j;
    scanf("%d %d", &v, &e);

    Edge e1[MAX_EDGE];

    for (i = 0; i < e; i++) {
        scanf("%d %d", &u, &w);
        addEdge(e1, u, w);
    }

    int dist[MAX_VERTEX];

    dijkstra(v, dist, e1);

    printf("Vertex\t Distance from Source\n");
    for (i = 0; i < v; i++) {
        printf("%d\t\t%d\n", i, dist[i]);
    }

    return 0;
}