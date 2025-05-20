//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>

#define MAX_NODES 1000
#define MAX_EDGES 2000
#define INF INT_MAX

typedef struct Edge {
    int from;
    int to;
    int weight;
} Edge;

typedef struct Node {
    int id;
    int distance;
    int visited;
} Node;

Edge edges[MAX_EDGES];
Node nodes[MAX_NODES];

void dijkstra(int start) {
    int i, j, k, u, v, w;
    for (i = 0; i < MAX_NODES; i++) {
        nodes[i].distance = INF;
        nodes[i].visited = 0;
    }
    nodes[start].distance = 0;
    for (i = 0; i < MAX_EDGES; i++) {
        u = edges[i].from;
        v = edges[i].to;
        w = edges[i].weight;
        if (nodes[u].distance!= INF && nodes[u].distance + w < nodes[v].distance) {
            nodes[v].distance = nodes[u].distance + w;
        }
    }
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i].distance == INF) {
            printf("Node %d is unreachable\n", i);
        }
    }
}

int main() {
    int i, j, k, n, m;
    char ch;
    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &edges[i].from, &edges[i].to, &edges[i].weight);
    }
    dijkstra(0);
    return 0;
}