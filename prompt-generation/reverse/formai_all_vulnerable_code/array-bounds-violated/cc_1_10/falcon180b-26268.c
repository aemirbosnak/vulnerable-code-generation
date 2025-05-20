//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 100
#define MAX_COLORS 10

int graph[MAX_NODES][MAX_NODES];
int n, m;
int colors[MAX_NODES];

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

void print_graph() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

void color_graph() {
    int i, j, k, l;
    for (i = 0; i < n; i++) {
        colors[i] = rand() % MAX_COLORS;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                for (k = 0; k < MAX_COLORS; k++) {
                    if (colors[i] == k || colors[j] == k) {
                        continue;
                    }
                    colors[j] = k;
                    break;
                }
            }
        }
    }
}

void print_colors() {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", colors[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    int i, j;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the number of edges: ");
    scanf("%d", &m);
    init_graph();
    for (i = 0; i < m; i++) {
        int u, v;
        printf("Enter the nodes for edge %d: ", i);
        scanf("%d %d", &u, &v);
        add_edge(u, v);
    }
    printf("The graph is:\n");
    print_graph();
    color_graph();
    printf("The colors are:\n");
    print_colors();
    return 0;
}