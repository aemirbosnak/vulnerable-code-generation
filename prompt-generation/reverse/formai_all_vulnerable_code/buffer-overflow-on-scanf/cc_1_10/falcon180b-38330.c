//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200
#define MAX_COLORS 6
#define DEBUG 0

typedef struct {
    int node;
    int color;
} Node;

typedef struct {
    int from;
    int to;
} Edge;

int num_nodes, num_edges, max_color;
int *color_map;
Edge *edge_list;
Node *node_list;

void init_graph(int num_nodes) {
    int i;
    edge_list = (Edge *)malloc(MAX_EDGES * sizeof(Edge));
    node_list = (Node *)malloc(MAX_NODES * sizeof(Node));
    for (i = 0; i < num_nodes; i++) {
        node_list[i].node = i;
        node_list[i].color = -1;
    }
}

void add_edge(int from, int to) {
    int i;
    Edge *e = edge_list;
    for (i = 0; i < num_edges; i++) {
        if (e->from == from && e->to == to) {
            return;
        }
        e++;
    }
    e->from = from;
    e->to = to;
    num_edges++;
}

int dfs(int node, int color) {
    Node *n = node_list + node;
    if (n->color!= -1) {
        return n->color == color? 0 : -1;
    }
    n->color = color;
    int ret = 0;
    Edge *e = edge_list;
    for (int i = 0; i < num_edges; i++) {
        if (e->from == node) {
            ret |= dfs(e->to, color);
        } else if (e->to == node) {
            ret |= dfs(e->from, color);
        }
        e++;
    }
    return ret;
}

int graph_coloring(int num_nodes) {
    max_color = 0;
    color_map = (int *)malloc(num_nodes * sizeof(int));
    memset(color_map, -1, num_nodes * sizeof(int));
    int i;
    for (i = 0; i < num_nodes; i++) {
        if (color_map[i] == -1) {
            if (dfs(i, max_color + 1) == 0) {
                max_color++;
            }
        }
    }
    return max_color;
}

void print_solution(int num_nodes) {
    int i;
    for (i = 0; i < num_nodes; i++) {
        printf("%d ", color_map[i] + 1);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int num_nodes;
    scanf("%d", &num_nodes);
    init_graph(num_nodes);
    int num_edges = (num_nodes * (num_nodes - 1)) / 2;
    for (int i = 0; i < num_edges; i++) {
        int from, to;
        scanf("%d%d", &from, &to);
        add_edge(from, to);
    }
    int max_color = graph_coloring(num_nodes);
    printf("Maximal number of colors: %d\n", max_color);
    print_solution(num_nodes);
    return 0;
}