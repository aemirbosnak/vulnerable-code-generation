//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE 1000
#define MAX_COLOR 10

typedef struct node {
    int num; // number of the node
    int color; // color assigned to the node
    int adj[MAX_NODE]; // adjacency list of the node
    int adj_size; // size of the adjacency list
} node_t;

node_t nodes[MAX_NODE];
int n, m; // n = number of nodes, m = number of edges

int is_valid(node_t* node, int color) {
    for (int i = 0; i < node->adj_size; i++) {
        node_t* adj_node = &nodes[node->adj[i]];
        if (adj_node->color == color) {
            return 0; // conflict with adjacent node
        }
    }
    return 1; // no conflict with adjacent nodes
}

void color_graph() {
    int colors[MAX_COLOR];
    memset(colors, 0, sizeof(colors)); // initialize colors to 0
    for (int i = 0; i < n; i++) {
        node_t* node = &nodes[i];
        for (int j = 0; j < MAX_COLOR; j++) {
            if (is_valid(node, j)) {
                node->color = j;
                colors[j]++;
                break;
            }
        }
    }
    printf("Colors used: ");
    for (int i = 0; i < MAX_COLOR; i++) {
        if (colors[i] > 0) {
            printf("%d ", i);
        }
    }
    printf("\n");
}

int main() {
    scanf("%d %d", &n, &m); // read number of nodes and edges
    for (int i = 0; i < n; i++) {
        nodes[i].num = i;
        nodes[i].color = -1; // no color assigned yet
        nodes[i].adj_size = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v; // edge between u and v
        scanf("%d %d", &u, &v);
        nodes[u].adj[nodes[u].adj_size++] = v;
        nodes[v].adj[nodes[v].adj_size++] = u;
    }
    color_graph(); // solve graph coloring problem
    return 0;
}