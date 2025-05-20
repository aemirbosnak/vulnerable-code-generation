//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    int start;
    int end;
    int weight;
} Edge;

Edge edges[MAX_EDGES];
int n;
int m;
int dist[MAX_NODES];
int parent[MAX_NODES];

void dijkstra(int start) {
    memset(dist, 0x7f, sizeof(dist));
    memset(parent, -1, sizeof(parent));
    dist[start] = 0;
    for (int i = 0; i < n; i++) {
        int u = -1, min = INF;
        for (int j = 0; j < m; j++) {
            if (edges[j].start == i && dist[edges[j].end] > dist[i] + edges[j].weight) {
                dist[edges[j].end] = dist[i] + edges[j].weight;
                parent[edges[j].end] = i;
            }
            if (edges[j].end == i && dist[edges[j].start] > dist[i] + edges[j].weight) {
                dist[edges[j].start] = dist[i] + edges[j].weight;
                parent[edges[j].start] = i;
            }
        }
    }
}

void print_path(int end) {
    if (parent[end] == -1) {
        printf("No path found.\n");
        return;
    }
    printf("Path: ");
    int v = end;
    while (v!= -1) {
        printf("%d ", v);
        v = parent[v];
    }
    printf("\n");
}

int main() {
    int i, j, u, v, w;
    scanf("%d %d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i].start = u;
        edges[i].end = v;
        edges[i].weight = w;
    }
    dijkstra(0);
    int q;
    printf("Enter the destination node: ");
    scanf("%d", &q);
    print_path(q);
    return 0;
}