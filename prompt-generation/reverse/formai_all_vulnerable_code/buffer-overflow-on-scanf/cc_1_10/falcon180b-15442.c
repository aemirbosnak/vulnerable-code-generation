//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_COLORS 100

typedef struct {
    int node;
    int color;
} GraphNode;

GraphNode graph[MAX_NODES];
int num_nodes;
int num_colors;

void init_graph() {
    num_nodes = 0;
    num_colors = 0;
}

void add_node(int node) {
    num_nodes++;
}

void add_color(int color) {
    num_colors++;
}

void set_node_color(int node, int color) {
    graph[node].node = node;
    graph[node].color = color;
}

int is_valid_color(int node, int color) {
    for (int i = 0; i < num_nodes; i++) {
        if (graph[i].node == node && graph[i].color == color) {
            return 0;
        }
    }
    return 1;
}

int color_graph() {
    int i = 0;
    int j = 0;
    int k = 0;
    int count = 0;
    int colors[MAX_COLORS];
    int color = 0;
    init_graph();
    srand(time(NULL));
    for (i = 0; i < num_nodes; i++) {
        while (1) {
            color = rand() % num_colors;
            if (is_valid_color(i, color)) {
                set_node_color(i, color);
                break;
            }
        }
        j++;
        if (j == num_colors) {
            j = 0;
            k++;
        }
    }
    return k;
}

int main() {
    int num_nodes = 0;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);
    init_graph();
    add_color(0);
    for (int i = 0; i < num_nodes; i++) {
        add_node(i);
    }
    int num_colors = color_graph();
    printf("The minimum number of colors needed is: %d\n", num_colors);
    return 0;
}