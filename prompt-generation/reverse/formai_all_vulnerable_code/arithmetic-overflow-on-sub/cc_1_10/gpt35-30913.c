//FormAI DATASET v1.0 Category: Graph representation ; Style: portable
#include <stdio.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
int num_nodes;

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void remove_edge(int u, int v) {
    graph[u][v] = 0;
    graph[v][u] = 0;
}

void print_graph() {
    printf("   ");
    for (int i = 0; i < num_nodes; i++) {
        printf("%d ", i+1);
    }
    printf("\n");

    for (int i = 0; i < num_nodes; i++) {
        printf("%2d ", i+1);
        for (int j = 0; j < num_nodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter number of edges: ");
    int num_edges;
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        printf("Enter edge %d: ", i+1);
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(u-1, v-1);
    }

    printf("\nGraph:\n");
    print_graph();

    printf("\nRemoving edge 1-2\n");
    remove_edge(0, 1);
    print_graph();

    return 0;
}