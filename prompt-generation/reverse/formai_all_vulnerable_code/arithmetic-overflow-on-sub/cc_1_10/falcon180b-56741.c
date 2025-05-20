//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999999

typedef struct {
    int start;
    int end;
    int weight;
} Edge;

typedef struct {
    int id;
    int distance;
    int parent;
} Node;

Edge edges[MAX_EDGES];
Node nodes[MAX_NODES];
int n, m;

void dijkstra(int start) {
    int i, j, k;
    for (i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].distance = INF;
        nodes[i].parent = -1;
    }
    nodes[start].distance = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < m; j++) {
            for (k = 0; k < m; k++) {
                if (edges[j].start == nodes[i].id && edges[j].end == nodes[k].id && edges[j].weight + nodes[i].distance < nodes[k].distance) {
                    nodes[k].distance = edges[j].weight + nodes[i].distance;
                    nodes[k].parent = i;
                }
            }
        }
    }
}

void print_path(int end) {
    int i = end;
    while (i!= -1) {
        printf("%d ", i);
        i = nodes[i].parent;
    }
}

int main() {
    int i, j, k;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        printf("Enter edge %d start and end nodes: ", i);
        scanf("%d %d", &edges[i].start, &edges[i].end);
        printf("Enter edge %d weight: ", i);
        scanf("%d", &edges[i].weight);
    }
    dijkstra(0);
    printf("Shortest path from node 0 to node %d:\n", n - 1);
    print_path(n - 1);
    printf("\n");
    return 0;
}