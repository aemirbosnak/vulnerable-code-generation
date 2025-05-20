//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100
#define MAX_LINKS 100

typedef struct {
    int id;
    char name[100];
    int node_count;
    int link_count;
    int nodes[MAX_NODES];
    int links[MAX_LINKS][2];
} Graph;

void print_graph(Graph* g) {
    printf("Graph: %s\n", g->name);
    printf("Node Count: %d\n", g->node_count);
    printf("Link Count: %d\n", g->link_count);
    for (int i = 0; i < g->node_count; i++) {
        printf("Node %d: %s\n", i, g->nodes[i]);
    }
    for (int i = 0; i < g->link_count; i++) {
        printf("Link %d: %d %d\n", i, g->links[i][0], g->links[i][1]);
    }
}

int main() {
    Graph* g = malloc(sizeof(Graph));
    strcpy(g->name, "Network Topology Mapper");
    g->node_count = 5;
    g->link_count = 5;
    g->nodes[0] = "Node 1";
    g->nodes[1] = "Node 2";
    g->nodes[2] = "Node 3";
    g->nodes[3] = "Node 4";
    g->nodes[4] = "Node 5";
    g->links[0][0] = 0;
    g->links[0][1] = 1;
    g->links[1][0] = 1;
    g->links[1][1] = 2;
    g->links[2][0] = 2;
    g->links[2][1] = 3;
    g->links[3][0] = 3;
    g->links[3][1] = 4;
    g->links[4][0] = 4;
    g->links[4][1] = 0;
    print_graph(g);
    return 0;
}