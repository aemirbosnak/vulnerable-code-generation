//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    char name[30];
    int degree;
    int *neighbors;
} Node;

void add_edge(Node *nodes, int n, int u, int v) {
    nodes[u].neighbors[nodes[u].degree++] = v;
    nodes[v].neighbors[nodes[v].degree++] = u;
}

void print_graph(Node *nodes, int n) {
    for(int i = 0; i < n; i++) {
        printf("%s: ", nodes[i].name);
        for(int j = 0; j < nodes[i].degree; j++) {
            printf("%d ", nodes[i].neighbors[j]);
        }
        printf("\n");
    }
}

int main() {
    Node nodes[MAX_NODES];
    int n = 0;
    char name[30];
    int u, v;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("Enter the name of node %d: ", i+1);
        scanf("%s", nodes[i].name);
        nodes[i].degree = 0;
        nodes[i].neighbors = (int*) malloc(MAX_EDGES * sizeof(int));
    }

    printf("Enter the edges (u v): ");
    while(scanf("%d %d", &u, &v) == 2) {
        add_edge(nodes, n, u-1, v-1);
    }

    printf("The graph:\n");
    print_graph(nodes, n);

    return 0;
}