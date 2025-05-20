//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 1000

typedef struct {
    int id;
    char name[20];
    int degree;
} Node;

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

void addEdge(Edge edges[], int src, int dest, int weight) {
    int i;
    for (i = 0; i < MAX_EDGES; i++) {
        if (edges[i].src == -1 && edges[i].dest == -1) {
            edges[i].src = src;
            edges[i].dest = dest;
            edges[i].weight = weight;
            return;
        }
    }
}

void addNode(Node nodes[], int id, char name[]) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        if (nodes[i].id == -1) {
            nodes[i].id = id;
            strcpy(nodes[i].name, name);
            nodes[i].degree = 0;
            return;
        }
    }
}

int main() {
    int i, j, n, m, src, dest, weight, start, end;
    char name[20];
    Node nodes[MAX_NODES];
    Edge edges[MAX_EDGES];

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the ID and name of node %d: ", i+1);
        scanf("%d %s", &nodes[i].id, nodes[i].name);
    }

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (i = 0; i < m; i++) {
        printf("Enter the source and destination nodes for edge %d: ", i+1);
        scanf("%d %d", &src, &dest);
        printf("Enter the weight of edge %d: ", i+1);
        scanf("%d", &weight);

        addEdge(edges, src, dest, weight);
        nodes[src-1].degree++;
        nodes[dest-1].degree++;
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("Enter the ending node: ");
    scanf("%d", &end);

    printf("The shortest path from node %d to node %d is:\n", start, end);

    for (i = 0; i < n; i++) {
        if (i == start) {
            printf("%d ", i);
        } else {
            printf("-1 ");
        }
    }

    printf("\n");

    return 0;
}