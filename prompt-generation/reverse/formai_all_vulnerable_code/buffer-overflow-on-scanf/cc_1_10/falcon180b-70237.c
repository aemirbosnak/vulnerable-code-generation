//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
#define MAX_COLOR 6

typedef struct {
    int id;
    bool visited;
    int color;
} Node;

int get_next_color(int colors[]) {
    int i = 0;
    while (i < MAX_COLOR) {
        if (colors[i] == 0) {
            return i;
        }
        i++;
    }
    return -1;
}

bool is_valid_color(int colors[], int node_color, int current_color) {
    if (node_color == current_color) {
        return false;
    }
    if (node_color == current_color - 1 || node_color == (current_color + 5) % 6) {
        return false;
    }
    return true;
}

void color_graph(Node nodes[], int num_nodes, int colors[]) {
    int i = 0;
    while (i < num_nodes) {
        int node_color = get_next_color(colors);
        if (node_color == -1) {
            printf("Graph cannot be colored with %d colors\n", num_nodes);
            exit(1);
        }
        nodes[i].color = node_color;
        i++;
    }
}

int main() {
    int num_nodes;
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    Node nodes[num_nodes];
    for (int i = 0; i < num_nodes; i++) {
        nodes[i].id = i;
        nodes[i].visited = false;
    }

    color_graph(nodes, num_nodes, (int *)malloc(MAX_COLOR * sizeof(int)));

    printf("Colored Graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        printf("Node %d: Color %d\n", nodes[i].id, nodes[i].color);
    }

    return 0;
}