//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef struct graph_node {
    int node_id;
    struct graph_node *next;
} graph_node;

typedef struct graph {
    int num_nodes;
    graph_node *head;
} graph;

bool graph_add_edge(graph *g, int from, int to) {
    graph_node *new_node = (graph_node*)malloc(sizeof(graph_node));
    new_node->node_id = to;
    new_node->next = g->head;
    g->head = new_node;
    return true;
}

bool graph_add_node(graph *g, int node_id) {
    graph_node *new_node = (graph_node*)malloc(sizeof(graph_node));
    new_node->node_id = node_id;
    new_node->next = g->head;
    g->head = new_node;
    g->num_nodes++;
    return true;
}

void print_graph(graph g) {
    graph_node *curr = g.head;
    while (curr!= NULL) {
        printf("%d ", curr->node_id);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    graph g;
    graph_add_node(&g, 0);
    graph_add_node(&g, 1);
    graph_add_node(&g, 2);
    graph_add_node(&g, 3);
    graph_add_edge(&g, 0, 1);
    graph_add_edge(&g, 0, 2);
    graph_add_edge(&g, 0, 3);
    graph_add_edge(&g, 1, 2);
    graph_add_edge(&g, 1, 3);
    graph_add_edge(&g, 2, 3);

    printf("Graph:\n");
    print_graph(g);

    int start = 0;
    int goal = 3;
    bool visited[g.num_nodes];
    int distance[g.num_nodes];
    for (int i = 0; i < g.num_nodes; i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    int current = start;
    distance[start] = 0;
    visited[start] = true;

    while (current!= goal && visited[current]) {
        for (graph_node *node = g.head; node!= NULL; node = node->next) {
            if (distance[node->node_id] > distance[current] + node->node_id) {
                distance[node->node_id] = distance[current] + node->node_id;
                current = node->node_id;
            }
        }
    }

    printf("Shortest path from node %d to node %d is:\n", start, goal);
    print_graph(g);

    for (int i = start; i!= goal; i = distance[i]) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}