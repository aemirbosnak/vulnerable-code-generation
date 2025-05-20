//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node {
    int data;
    int *edges;
    int edge_count;
} Node;

void create_graph(int n) {
    Node *graph = malloc(n * sizeof(Node));

    for (int i = 0; i < n; i++) {
        graph[i].data = i;
        graph[i].edges = NULL;
        graph[i].edge_count = 0;
    }
}

void add_edge(Node *graph, int u, int v) {
    graph[u].edges = realloc(graph[u].edges, (graph[u].edge_count + 1) * sizeof(int));
    graph[u].edges[graph[u].edge_count++] = v;
}

void print_graph(Node *graph, int n) {
    for (int i = 0; i < n; i++) {
        printf("Node %d: ", i);
        for (int j = 0; j < graph[i].edge_count; j++) {
            printf("%d ", graph[i].edges[j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int n = rand() % MAX_NODES + 1;
    int m = rand() % MAX_EDGES + 1;

    Node *graph = malloc(n * sizeof(Node));
    create_graph(n);

    for (int i = 0; i < m; i++) {
        int u = rand() % n;
        int v = rand() % n;
        add_edge(graph, u, v);
        add_edge(graph, v, u);
    }

    printf("Generated graph:\n");
    print_graph(graph, n);

    return 0;
}