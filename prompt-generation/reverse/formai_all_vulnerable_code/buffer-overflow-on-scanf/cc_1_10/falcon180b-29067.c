//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

#define MAX_V 100
#define MAX_E 1000

int V, E;
int graph[MAX_V][MAX_V];
int color[MAX_V];

void initialize() {
    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    printf("Enter the edges:\n");
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

int is_safe(int v, int c, int color[]) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph(int v, int c) {
    color[v] = c;

    for (int i = 0; i < V; i++) {
        if (graph[v][i] == 1 && color[i] == -1) {
            color_graph(i, c);
        }
    }
}

int main() {
    initialize();

    for (int i = 0; i < V; i++) {
        color[i] = -1;
    }

    int count = 0;

    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            color_graph(i, count);
            count++;
        }
    }

    printf("The minimum number of colors required to color the graph is %d\n", count);

    return 0;
}