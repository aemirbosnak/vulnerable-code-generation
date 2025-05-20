//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct {
    int node;
    struct node *next;
} Node;

typedef struct {
    int color;
    Node *adj_list;
} Graph;

Graph *create_graph(int n) {
    Graph *graph = (Graph *) malloc(sizeof(Graph));
    graph->color = 0;
    graph->adj_list = NULL;
    return graph;
}

void add_edge(Graph *graph, int u, int v) {
    Node *node = (Node *) malloc(sizeof(Node));
    node->node = v;
    node->next = graph->adj_list;
    graph->adj_list = node;
}

int color_graph(Graph *graph) {
    int colors[MAX_NODES];
    for (int i = 0; i < MAX_NODES; i++) {
        colors[i] = -1;
    }
    int count = 0;
    colors[0] = count++;
    for (Node *node = graph->adj_list; node!= NULL; node = node->next) {
        int v = node->node;
        int color = -1;
        for (int i = 0; i < MAX_NODES; i++) {
            if (colors[i] == -1) {
                colors[i] = count++;
                color = i;
                break;
            }
        }
        if (color == -1) {
            printf("Not enough colors!\n");
            exit(1);
        }
        colors[v] = color;
    }
    return count;
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    int n, m;
    scanf("%d %d", &n, &m);
    Graph *graph = create_graph(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(graph, u, v);
    }
    int colors = color_graph(graph);
    printf("Graph colored with %d colors.\n", colors);
    return 0;
}