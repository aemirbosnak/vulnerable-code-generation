//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define inf 1000000000
#define max_nodes 100

int adj_matrix[max_nodes][max_nodes]; // adjacency matrix to represent the graph
int n, m, i, j, k, u, v, w, min_color, color[max_nodes]; // variables for graph representation and coloring

void init() {
    for (i = 0; i < max_nodes; i++)
        for (j = 0; j < max_nodes; j++)
            adj_matrix[i][j] = inf;
}

void add_edge(int u, int v, int w) {
    adj_matrix[u][v] = w;
    adj_matrix[v][u] = w; // assuming an undirected graph
}

void print_graph(int n) {
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", adj_matrix[i][j]);
        printf("\n");
    }
}

void color_graph(int n) {
    int i;
    for (i = 0; i < n; i++)
        color[i] = -1; // initializing all nodes to be uncolored

    for (i = 0; i < n; i++) {
        int min_color = inf;
        int u = -1;
        for (j = 0; j < n; j++) {
            if (color[j]!= -1 && adj_matrix[i][j]!= inf && adj_matrix[i][j] < min_color) {
                min_color = adj_matrix[i][j];
                u = j;
            }
        }
        if (min_color == inf) {
            printf("No solution exists!\n");
            exit(0);
        }
        color[i] = u;
    }
}

int main() {
    int n, m, i, j, k;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    init();

    printf("Enter the edges:\n");
    for (i = 0; i < m; i++) {
        printf("Enter the two nodes connected by an edge: ");
        scanf("%d %d", &u, &v);
        printf("Enter the weight of the edge: ");
        scanf("%d", &w);
        add_edge(u, v, w);
    }

    printf("Adjacency matrix:\n");
    print_graph(n);

    printf("Minimum number of colors required: ");
    color_graph(n);

    for (i = 0; i < n; i++)
        printf("%d ", color[i]);

    return 0;
}