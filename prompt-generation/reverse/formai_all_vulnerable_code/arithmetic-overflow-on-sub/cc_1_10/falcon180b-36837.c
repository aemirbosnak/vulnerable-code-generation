//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_EDGES 500
#define INF INT_MAX

struct Edge {
    int to;
    int cost;
};

struct Node {
    int id;
    int dist;
    int prev;
};

void dijkstra(int start, int end, struct Edge edges[], int n) {
    struct Node nodes[MAX_NODES];
    int i, j, k, u, v;

    for (i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].dist = INF;
        nodes[i].prev = -1;
    }

    nodes[start].dist = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                if (nodes[j].dist!= INF && nodes[j].dist + edges[k].cost < nodes[k].dist) {
                    nodes[k].dist = nodes[j].dist + edges[k].cost;
                    nodes[k].prev = j;
                }
            }
        }
    }

    printf("Shortest path from node %d to node %d:\n", start, end);
    u = end;
    while (u!= -1) {
        printf("%d ", u);
        v = nodes[u].prev;
        u = v;
    }
    printf("\n");
}

int main() {
    int n, m, i, j, u, v, w;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    struct Edge edges[MAX_EDGES];

    printf("Enter the edges (node1 node2 cost):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (struct Edge) {v, w};
    }

    int start, end;

    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("Enter the ending node: ");
    scanf("%d", &end);

    dijkstra(start, end, edges, n);

    return 0;
}