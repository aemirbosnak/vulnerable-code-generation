//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999999

typedef struct {
    int id;
    int visited;
    int distance;
    int parent;
} Node;

typedef struct {
    int start;
    int end;
    int weight;
} Edge;

void dijkstra(Edge edges[], int n, int start) {
    Node nodes[MAX_NODES];
    memset(nodes, 0, sizeof(nodes));
    int i, j;
    for (i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].distance = INF;
    }
    nodes[start].distance = 0;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n; j++) {
            if (nodes[j].distance > nodes[i].distance + edges[i].weight) {
                nodes[j].distance = nodes[i].distance + edges[i].weight;
                nodes[j].parent = i;
            }
        }
    }
    printf("Node\t Distance\tPath\n");
    printf("Start\t0\t-1\n");
    for (i = 0; i < n; i++) {
        if (i!= start) {
            printf("%d\t%d\t", i, nodes[i].distance);
            j = nodes[i].parent;
            while (j!= -1) {
                printf("%d ", j);
                j = nodes[j].parent;
            }
            printf("\n");
        }
    }
}

int main() {
    Edge edges[MAX_EDGES];
    int i, j, start;
    printf("Enter number of nodes: ");
    scanf("%d", &j);
    printf("Enter number of edges: ");
    scanf("%d", &i);
    printf("Enter edges in the form of start end weight:\n");
    for (int k = 0; k < i; k++) {
        scanf("%d %d %d", &edges[k].start, &edges[k].end, &edges[k].weight);
    }
    printf("Enter start node: ");
    scanf("%d", &start);
    dijkstra(edges, j, start);
    return 0;
}