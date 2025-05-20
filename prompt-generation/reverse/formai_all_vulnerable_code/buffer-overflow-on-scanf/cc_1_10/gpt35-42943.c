//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: real-life
#include<stdio.h>

#define MAX 100

int adj[MAX][MAX];

int n, m, colors[MAX];

void get_input() {
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    int u, v;
    printf("Enter the edges:\n");
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
}

int is_valid(int node, int color) {
    for(int i = 1; i <= n; i++) {
        if(adj[node][i] && colors[i] == color) {
            return 0;
        }
    }
    return 1;
}

void graph_coloring(int node) {
    if(node == n+1) { // Base case
        printf("The colors of the graph nodes: ");
        for(int i = 1; i <= n; i++) {
            printf("%d ", colors[i]);
        }
        printf("\n");
    }
    else {
        for(int i = 1; i <= n; i++) { // Try all colors
            if(is_valid(node, i)) {
                colors[node] = i;
                graph_coloring(node+1);
                colors[node] = 0;
            }
        }
    }
}

int main() {
    get_input();
    graph_coloring(1);
    return 0;
}