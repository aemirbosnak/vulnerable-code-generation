//Falcon-180B DATASET v1.0 Category: Pathfinding algorithms ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define INF INT_MAX

typedef struct Edge {
    int to;
    int weight;
} Edge;

typedef struct Node {
    int id;
    bool visited;
    int distance;
    int parent;
} Node;

void dijkstra(Edge edges[], int n, int start) {
    Node nodes[MAX_NODES];
    int i, j, k;

    for (i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].visited = false;
        nodes[i].distance = INF;
        nodes[i].parent = -1;
    }

    nodes[start].distance = 0;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < MAX_EDGES; k++) {
                if (edges[k].to == j && edges[k].weight < nodes[j].distance) {
                    nodes[j].distance = edges[k].weight;
                    nodes[j].parent = i;
                }
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (nodes[i].distance == INF) {
            printf("Node %d is unreachable\n", i);
        } else {
            printf("Shortest path to node %d: %d\n", i, nodes[i].distance);
        }
    }
}

int main() {
    int n, m, i, j, k;
    Edge edges[MAX_EDGES];
    Node nodes[MAX_NODES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the ID of node %d: ", i);
        scanf("%d", &nodes[i].id);
    }

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter the ID of the source node for edge %d: ", i);
        scanf("%d", &edges[i].to);

        printf("Enter the weight of edge %d: ", i);
        scanf("%d", &edges[i].weight);
    }

    dijkstra(edges, n, 0);

    return 0;
}