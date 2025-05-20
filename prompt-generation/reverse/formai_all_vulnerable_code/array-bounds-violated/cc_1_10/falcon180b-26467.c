//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_EDGES 10000
#define MAX_COLORS 10

typedef struct {
    int id;
    int color;
} Node;

typedef struct {
    int u;
    int v;
} Edge;

Node nodes[MAX_NODES];
Edge edges[MAX_EDGES];
int num_nodes;
int num_edges;
int num_colors;
int color_map[MAX_NODES];

void init_node(int id) {
    nodes[id].id = id;
    nodes[id].color = -1;
}

void init_edge(int u, int v) {
    edges[num_edges].u = u;
    edges[num_edges].v = v;
    num_edges++;
}

int get_node_color(int id) {
    return color_map[id];
}

void set_node_color(int id, int color) {
    color_map[id] = color;
}

void print_node_colors() {
    for (int i = 0; i < num_nodes; i++) {
        printf("%d\t%d\n", nodes[i].id, color_map[i]);
    }
}

int is_valid_color(int node_id, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (edges[i].u == node_id || edges[i].v == node_id) {
            if (color_map[i] == color) {
                return 0;
            }
        }
    }
    return 1;
}

void color_node(int node_id, int color) {
    set_node_color(node_id, color);
    for (int i = 0; i < num_nodes; i++) {
        if (edges[i].u == node_id || edges[i].v == node_id) {
            if (color_map[i] == -1) {
                color_map[i] = color;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    num_nodes = rand() % MAX_NODES + 1;
    num_edges = rand() % MAX_EDGES + 1;
    num_colors = rand() % MAX_COLORS + 1;

    printf("Number of nodes: %d\n", num_nodes);
    printf("Number of edges: %d\n", num_edges);
    printf("Number of colors: %d\n", num_colors);

    for (int i = 0; i < num_nodes; i++) {
        init_node(i);
    }

    int num_edges_added = 0;
    while (num_edges_added < num_edges) {
        int u = rand() % num_nodes;
        int v = rand() % num_nodes;
        if (u!= v) {
            if (is_valid_color(u, -1)) {
                init_edge(u, v);
                color_node(u, num_colors - 1);
                num_edges_added++;
            }
        }
    }

    printf("Node colors:\n");
    print_node_colors();

    return 0;
}