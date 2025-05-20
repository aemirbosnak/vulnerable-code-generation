//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 1000
#define MAX_COLORS 10

typedef struct {
    int id;
    bool is_colored;
    int color;
} Node;

int num_nodes;
int num_colors;
Node *nodes;
int *colors;
int *color_count;

void init(int n, int c) {
    num_nodes = n;
    num_colors = c;
    nodes = malloc(sizeof(Node) * num_nodes);
    colors = malloc(sizeof(int) * num_colors);
    color_count = malloc(sizeof(int) * num_colors);
    for (int i = 0; i < num_colors; i++) {
        colors[i] = i;
        color_count[i] = 0;
    }
}

void add_node(int id) {
    nodes[num_nodes - 1].id = id;
    nodes[num_nodes - 1].is_colored = false;
    nodes[num_nodes - 1].color = -1;
    num_nodes++;
}

bool is_valid_color(int node_id, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (nodes[i].is_colored && nodes[i].color == color) {
            if (nodes[i].id == node_id) {
                return false;
            }
        }
    }
    return true;
}

void color_node(int node_id, int color) {
    nodes[node_id].is_colored = true;
    nodes[node_id].color = color;
    color_count[color]++;
}

int get_color_count(int color) {
    return color_count[color];
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    init(n, m);
    for (int i = 0; i < n; i++) {
        add_node(i);
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        if (is_valid_color(u, v)) {
            color_node(u, v);
        }
    }
    int max_color_count = 0;
    for (int i = 0; i < num_colors; i++) {
        if (get_color_count(i) > max_color_count) {
            max_color_count = get_color_count(i);
        }
    }
    printf("%d\n", max_color_count);
    return 0;
}