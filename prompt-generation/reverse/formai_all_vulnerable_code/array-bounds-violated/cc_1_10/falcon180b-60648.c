//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_VERTEX 1000
#define MAX_EDGE 100000
#define INF 999999

typedef struct {
    int u;
    int v;
    int w;
} Edge;

int n, m, start, end;
Edge edges[MAX_EDGE];
int dist[MAX_VERTEX];
int parent[MAX_VERTEX];

void dijkstra(int start) {
    int i, u, v;
    for(i = 0; i < n; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }
    dist[start] = 0;
    for(i = 0; i < n - 1; i++) {
        for(u = 0; u < n; u++) {
            for(v = 0; v < n; v++) {
                if(dist[u]!= INF && dist[u] + edges[i].w < dist[v]) {
                    dist[v] = dist[u] + edges[i].w;
                    parent[v] = u;
                }
            }
        }
    }
}

int main() {
    int i, u, v, w;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge) {u, v, w};
    }
    scanf("%d %d", &start, &end);
    dijkstra(start);
    printf("The shortest path from %d to %d is: ", start, end);
    if(dist[end] == INF) {
        printf("No path found\n");
    } else {
        printf("%d", end);
        while(parent[end]!= -1) {
            printf(" -> %d", parent[end]);
            end = parent[end];
        }
        printf("\n");
    }
    return 0;
}