//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_V 10
#define MAX_E 20

int V, E;
int graph[MAX_V][MAX_V];
int color[MAX_V];

void init_graph() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
}

void read_graph() {
    int i, j;
    printf("Enter the number of vertices and edges:\n");
    scanf("%d %d", &V, &E);
    printf("Enter the edges:\n");
    for (i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void print_graph() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j]) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void backtrack(int v, int c) {
    int i;
    color[v] = c;
    for (i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == 0) {
            int nc = 1;
            while (color[nc]!= 0) {
                nc++;
            }
            backtrack(i, nc);
        }
    }
}

void color_graph() {
    int i;
    srand(time(NULL));
    for (i = 0; i < V; i++) {
        color[i] = 0;
    }
    backtrack(0, 1);
}

int main() {
    init_graph();
    read_graph();
    color_graph();
    printf("Vertex\tColor\n");
    for (int i = 0; i < V; i++) {
        printf("%d\t%d\n", i, color[i]);
    }
    return 0;
}