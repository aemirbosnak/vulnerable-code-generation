//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_COLORS 7
#define INF 999999

int V, E;
int graph[MAX_VERTICES][MAX_VERTICES];
int color[MAX_VERTICES];

void init_graph() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = INF;
        }
    }
}

void init_colors() {
    int i;
    for (i = 0; i < V; i++) {
        color[i] = -1;
    }
}

int min_color(int v) {
    int i, min_color = INF;
    for (i = 0; i < MAX_COLORS; i++) {
        if (color[i] == -1) {
            color[i] = v;
            return i;
        }
    }
    for (i = 0; i < MAX_COLORS; i++) {
        if (color[i] > v) {
            color[i] = v;
            return i;
        }
    }
    return -1;
}

int graph_coloring() {
    int i, j, k, u, v, w;
    int color_num = 0;
    srand(time(NULL));
    init_graph();
    init_colors();
    for (i = 0; i < V; i++) {
        if (color[i] == -1) {
            color[i] = rand() % MAX_COLORS;
            color_num++;
        }
    }
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j]!= INF) {
                if (color[i] == color[j]) {
                    return -1;
                }
            }
        }
    }
    return color_num;
}

int main() {
    int i, j, k, u, v, w;
    int E, V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    printf("Enter the number of edges: ");
    scanf("%d", &E);
    int graph[V][V];
    int color[V];
    printf("Enter the edges:\n");
    for (i = 0; i < E; i++) {
        printf("Enter the vertices of edge %d: ", i + 1);
        scanf("%d %d", &u, &v);
        graph[u][v] = graph[v][u] = 1;
    }
    int color_num = graph_coloring();
    if (color_num == -1) {
        printf("Graph is not colorable.\n");
    } else {
        printf("Graph is colorable with %d colors.\n", color_num);
    }
    return 0;
}