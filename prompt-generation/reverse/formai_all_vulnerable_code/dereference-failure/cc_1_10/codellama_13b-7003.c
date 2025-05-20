//Code Llama-13B DATASET v1.0 Category: Graph representation ; Style: light-weight
#include <stdio.h>
    #include <stdlib.h>

    struct Node {
        int data;
        struct Node *next;
    };

    struct Graph {
        int num_nodes;
        int num_edges;
        struct Node *nodes;
    };

    void init_graph(struct Graph *graph, int num_nodes, int num_edges) {
        graph->num_nodes = num_nodes;
        graph->num_edges = num_edges;
        graph->nodes = (struct Node *)malloc(num_nodes * sizeof(struct Node));
        for (int i = 0; i < num_nodes; i++) {
            graph->nodes[i].data = i;
            graph->nodes[i].next = NULL;
        }
    }

    void add_edge(struct Graph *graph, int from, int to) {
        struct Node *node = &graph->nodes[from];
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = &graph->nodes[to];
    }

    void print_graph(struct Graph *graph) {
        for (int i = 0; i < graph->num_nodes; i++) {
            struct Node *node = &graph->nodes[i];
            printf("%d: ", i);
            while (node->next != NULL) {
                printf("%d ", node->next->data);
                node = node->next;
            }
            printf("\n");
        }
    }

    int main() {
        struct Graph graph;
        init_graph(&graph, 5, 4);
        add_edge(&graph, 0, 1);
        add_edge(&graph, 0, 2);
        add_edge(&graph, 1, 3);
        add_edge(&graph, 2, 4);
        print_graph(&graph);
        return 0;
    }