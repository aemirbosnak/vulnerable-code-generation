//Falcon-180B DATASET v1.0 Category: Network Topology Mapper ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define INF 9999

typedef struct {
    char name[20];
    int id;
} Node;

typedef struct {
    int u, v, w;
} Edge;

Node nodes[MAX_NODES];
int num_nodes = 0;

Edge edges[MAX_EDGES];
int num_edges = 0;

void add_node(char* name) {
    strcpy(nodes[num_nodes].name, name);
    nodes[num_nodes].id = num_nodes;
    num_nodes++;
}

int find_node(char* name) {
    for (int i = 0; i < num_nodes; i++) {
        if (strcmp(nodes[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_edge(int u, int v, int w) {
    edges[num_edges].u = u;
    edges[num_edges].v = v;
    edges[num_edges].w = w;
    num_edges++;
}

void print_nodes() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d: %s\n", nodes[i].id, nodes[i].name);
    }
}

void print_edges() {
    for (int i = 0; i < num_edges; i++) {
        printf("%d -> %d (%d)\n", edges[i].u, edges[i].v, edges[i].w);
    }
}

void kruskal() {
    int parent[MAX_NODES];
    for (int i = 0; i < num_nodes; i++) {
        parent[i] = i;
    }

    int num_components = num_nodes;
    int e = 0;

    for (int i = 0; i < num_edges; i++) {
        int u = find_node(edges[i].u);
        int v = find_node(edges[i].v);

        if (parent[u]!= parent[v]) {
            parent[parent[v]] = parent[u];
            e++;
        }
    }

    printf("Minimum spanning tree has %d edges:\n", e);
    print_edges();
}

int main() {
    add_node("A");
    add_node("B");
    add_node("C");
    add_node("D");
    add_node("E");

    add_edge(0, 1, 5);
    add_edge(0, 2, 7);
    add_edge(1, 2, 3);
    add_edge(1, 3, 8);
    add_edge(2, 3, 2);
    add_edge(2, 4, 4);
    add_edge(3, 4, 6);

    print_nodes();
    print_edges();

    kruskal();

    return 0;
}