//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_V 100
#define MAX_COLOR 7

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

void print_graph() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}

int is_valid_color(int v, int c) {
    int i;
    for (i = 0; i < V; i++) {
        if (i!= v && color[i] == c) {
            return 0;
        }
    }
    return 1;
}

void color_graph() {
    int i, c;
    for (i = 0; i < V; i++) {
        color[i] = 1;
    }
    for (c = 1; c <= MAX_COLOR; c++) {
        for (i = 0; i < V; i++) {
            if (color[i] == c) {
                continue;
            }
            if (is_valid_color(i, c)) {
                color[i] = c;
            }
        }
    }
}

void init_random_graph() {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (rand() % 2 == 0) {
                graph[i][j] = 1;
            }
        }
    }
}

int main() {
    int i;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    init_graph();
    for (i = 0; i < E; i++) {
        int u, v;
        printf("Enter the vertices of edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
    init_random_graph();
    color_graph();
    printf("The colored graph is:\n");
    print_graph();
    return 0;
}