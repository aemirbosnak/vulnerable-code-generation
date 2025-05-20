//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 9
#define NIL -1

int graph[V][V];
int color[V];
int n;

void init_graph() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void print_solution(int n) {
    int i;
    for (i = 0; i < V; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

void backtrack(int u, int k) {
    int i, j;
    color[u] = k;
    for (i = 0; i < V; i++) {
        if (graph[u][i] == 1 && color[i] == -1) {
            color[i] = k;
            backtrack(i, k);
        }
        else if (graph[u][i] == 1 && color[i]!= k) {
            printf("Error: Graph is not bipartite.\n");
            exit(0);
        }
    }
}

int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    init_graph();

    printf("Enter the edges of the graph:\n");
    int u, v;
    while (scanf("%d%d", &u, &v) == 2) {
        add_edge(u, v);
    }

    srand(time(NULL));
    int start_vertex = rand() % V;
    color[start_vertex] = 1;
    backtrack(start_vertex, 1);

    printf("The vertices can be colored in the following way:\n");
    print_solution(n);

    return 0;
}