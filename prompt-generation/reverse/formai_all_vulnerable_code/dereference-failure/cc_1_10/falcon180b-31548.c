//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 10

typedef struct node {
    int id;
    int color;
    struct node *next;
} Node;

typedef struct graph {
    int num_nodes;
    Node *nodes;
} Graph;

void create_graph(Graph *graph) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        graph->nodes[i].id = i;
        graph->nodes[i].color = -1;
        graph->nodes[i].next = NULL;
    }
}

void add_edge(Graph *graph, int node1, int node2) {
    Node *node1_ptr = &graph->nodes[node1];
    Node *node2_ptr = &graph->nodes[node2];

    node1_ptr->next = node2_ptr;
    node2_ptr->next = node1_ptr;
}

void print_graph(Graph *graph) {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        Node *node_ptr = &graph->nodes[i];
        printf("%d -> ", i);
        while (node_ptr->next!= NULL) {
            printf("%d -> ", node_ptr->next->id);
            node_ptr = node_ptr->next;
        }
        printf("NULL\n");
    }
}

int is_valid_color(Graph *graph, int node_id, int color) {
    Node *node_ptr = &graph->nodes[node_id];
    while (node_ptr!= NULL) {
        if (node_ptr->color == color) {
            return 0;
        }
        node_ptr = node_ptr->next;
    }
    return 1;
}

void color_graph(Graph *graph) {
    int i, num_colors = 0;
    int colors[MAX_COLORS];
    int num_nodes = graph->num_nodes;
    int *node_ids = malloc(num_nodes * sizeof(int));
    int j = 0;

    srand(time(NULL));
    for (i = 0; i < num_nodes; i++) {
        while (1) {
            int color = rand() % MAX_COLORS;
            if (is_valid_color(graph, i, color)) {
                graph->nodes[i].color = color;
                break;
            }
        }
        if (num_colors < MAX_COLORS &&!is_valid_color(graph, i, num_colors)) {
            colors[num_colors++] = num_colors;
        }
    }

    for (i = 0; i < num_nodes; i++) {
        if (graph->nodes[i].color == -1) {
            int color = colors[j++ % num_colors];
            graph->nodes[i].color = color;
        }
    }

    free(node_ids);
}

int main() {
    Graph graph;
    create_graph(&graph);

    int i, j;
    for (i = 0; i < MAX_NODES; i++) {
        for (j = i + 1; j < MAX_NODES; j++) {
            add_edge(&graph, i, j);
        }
    }

    color_graph(&graph);

    printf("Graph:\n");
    print_graph(&graph);

    return 0;
}