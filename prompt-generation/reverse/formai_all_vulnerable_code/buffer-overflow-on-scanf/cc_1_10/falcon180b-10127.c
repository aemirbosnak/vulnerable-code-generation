//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
    int vertex;
    int color;
} Edge;

int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

void init_graph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int v1, int v2) {
    graph[v1][v2] = 1;
    graph[v2][v1] = 1;
}

void print_graph(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 1) {
                printf("%d - %d \n", i, j);
            }
        }
    }
}

void color_graph(int n) {
    for (int i = 0; i < n; i++) {
        color[i] = rand() % MAX_COLORS;
    }
}

void print_colors(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d - color %d \n", i, color[i]);
    }
}

int main() {
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    init_graph(n);

    int m;
    printf("Enter the number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        int v1, v2;
        printf("Enter the vertices for edge %d: ", i+1);
        scanf("%d %d", &v1, &v2);
        add_edge(v1, v2);
    }

    color_graph(n);

    printf("The colored graph is:\n");
    print_graph(n);
    print_colors(n);

    return 0;
}