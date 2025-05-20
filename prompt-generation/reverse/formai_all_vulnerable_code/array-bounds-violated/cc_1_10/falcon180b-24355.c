//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int n;
int m;

void init_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
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
    printf("Vertex\tColor\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\n", i, colors[i]);
    }
}

int main() {
    int i, j, k, u, v;
    int flag = 1;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    init_graph();

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    printf("Enter the edges (u v):\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }

    for (i = 0; i < n; i++) {
        colors[i] = i;
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (graph[i][k] == 1 && graph[k][j] == 1 && colors[i] == colors[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) {
                break;
            }
        }
        if (flag == 0) {
            break;
        }
    }

    if (flag == 1) {
        printf("The graph can be colored with %d colors.\n", n);
        print_solution(n);
    } else {
        printf("The graph cannot be colored with %d colors.\n", n);
    }

    return 0;
}