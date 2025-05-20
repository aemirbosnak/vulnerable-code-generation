//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_NAME_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    int index;
    int visited;
} node;

typedef struct {
    int from;
    int to;
    int weight;
} edge;

node nodes[MAX_NODES];
edge edges[MAX_EDGES];
int num_nodes = 0;
int num_edges = 0;

void add_node(char *name) {
    if (num_nodes >= MAX_NODES) {
        printf("Error: maximum number of nodes reached.\n");
        exit(1);
    }
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].index = num_nodes;
    nodes[num_nodes].visited = 0;
    num_nodes++;
}

void add_edge(int from, int to, int weight) {
    if (num_edges >= MAX_EDGES) {
        printf("Error: maximum number of edges reached.\n");
        exit(1);
    }
    edges[num_edges].from = from;
    edges[num_edges].to = to;
    edges[num_edges].weight = weight;
    num_edges++;
}

void dfs(int node_index) {
    nodes[node_index].visited = 1;
    printf("%s ", nodes[node_index].name);
    int i;
    for (i = 0; i < num_edges; i++) {
        if (edges[i].from == node_index) {
            dfs(edges[i].to);
        }
    }
}

int main() {
    int i;
    char name[MAX_NAME_LENGTH];
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    printf("Enter the names of the nodes:\n");
    for (i = 0; i < num_nodes; i++) {
        scanf("%s", name);
        add_node(name);
    }
    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);
    printf("Enter the edges (from node, to node, weight):\n");
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d %d", &edges[i].from, &edges[i].to, &edges[i].weight);
        add_edge(edges[i].from, edges[i].to, edges[i].weight);
    }
    printf("Depth-first search starting at node 0:\n");
    dfs(0);
    printf("\n");
    return 0;
}