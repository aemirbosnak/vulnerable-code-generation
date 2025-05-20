//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999999

struct Edge {
    int u, v, w;
};

struct Node {
    int id, dist, parent;
};

void dijkstra(int start, int end, struct Edge edges[], struct Node nodes[]) {
    int i, j, k, u, v, w;
    int n = end + 1;

    for (i = 0; i <= n; i++) {
        nodes[i].dist = INF;
        nodes[i].parent = -1;
    }

    nodes[start].dist = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1; j++) {
            if (nodes[j].dist > nodes[k].dist + edges[k].w) {
                nodes[j].dist = nodes[k].dist + edges[k].w;
                nodes[j].parent = k;
            }
        }
    }

    printf("Vertex\tDistance from Source\n");
    for (i = 0; i <= n; i++) {
        printf("%d\t\t%d\n", i, nodes[i].dist);
    }
}

int main() {
    int i, j, n, m, start, end, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    struct Edge edges[m];

    printf("Enter the edges (u, v, w):\n");
    for (i = 0; i < m; i++) {
        scanf("%d%d%d", &u, &v, &w);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].w = w;
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("Enter the ending node: ");
    scanf("%d", &end);

    struct Node nodes[n];

    dijkstra(start, end, edges, nodes);

    return 0;
}