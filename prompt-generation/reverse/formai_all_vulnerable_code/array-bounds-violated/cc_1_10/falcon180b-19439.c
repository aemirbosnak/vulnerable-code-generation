//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_VERTICES 100
#define MAX_EDGES 200
#define MAX_COLORS 7

typedef struct {
    int vertex;
    int color;
} Edge;

int graph[MAX_VERTICES][MAX_VERTICES] = {0};
int num_vertices, num_edges;

void init_graph() {
    printf("Enter the number of vertices: ");
    scanf("%d", &num_vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for(int i = 0; i < num_edges; i++) {
        int u, v, c;
        printf("Enter the vertices and color of edge %d: ", i+1);
        scanf("%d %d %d", &u, &v, &c);
        graph[u][v] = c;
        graph[v][u] = c;
    }
}

int color[MAX_VERTICES];

void backtrack(int v, int c) {
    if(v == -1)
        return;

    color[v] = c;
    for(int u = 0; u < num_vertices; u++) {
        if(graph[v][u]!= 0 && color[u] == -1) {
            backtrack(u, c ^ graph[v][u]);
        }
    }
}

int main() {
    init_graph();

    srand(time(NULL));
    for(int i = 0; i < num_vertices; i++) {
        color[i] = rand() % MAX_COLORS;
    }

    int conflicts = 0;

    while(conflicts == 0) {
        conflicts = 0;
        for(int i = 0; i < num_vertices; i++) {
            if(color[i] == -1) {
                int c = rand() % MAX_COLORS;
                backtrack(i, c);
            }
        }
    }

    printf("Color of vertex 0: %d\n", color[0]);
    for(int i = 1; i < num_vertices; i++) {
        printf("Color of vertex %d: %d\n", i, color[i]);
    }

    return 0;
}