//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_VERTICES 100
#define MAX_EDGES 10000
typedef struct {
    int vertex;
    struct edge *next;
} edge;
typedef struct {
    int color;
    edge *edges[MAX_VERTICES];
} vertex;
vertex graph[MAX_VERTICES];
int num_vertices, num_edges;
bool dfs(int vertex, int color) {
    if (graph[vertex].color != -1) {
        if (graph[vertex].color == color) {
            printf("Graph has a cycle.\n");
            return false;
        }
    }
    graph[vertex].color = color;
    for (edge *e = graph[vertex].edges[0]; e != NULL; e = e->next) {
        if (!dfs(e->vertex, (color + 1) % num_vertices)) {
            graph[vertex].color = -1;
            return false;
        }
    }
    return true;
}
int main() {
    int i, j, k;
    printf("Enter number of vertices and edges:\n");
    scanf("%d%d", &num_vertices, &num_edges);
    for (i = 0; i < num_vertices; i++) {
        graph[i].color = -1;
    }
    printf("Enter edges (u v):\n");
    for (i = 0; i < num_edges; i++) {
        scanf("%d%d", &j, &k);
        edge *new_edge = malloc(sizeof(edge));
        new_edge->vertex = k;
        new_edge->next = graph[j].edges[0];
        graph[j].edges[0] = new_edge;
    }
    if (dfs(0, 0)) {
        printf("Graph can be colored.\n");
    } else {
        printf("Graph cannot be colored.\n");
    }
    return 0;
}