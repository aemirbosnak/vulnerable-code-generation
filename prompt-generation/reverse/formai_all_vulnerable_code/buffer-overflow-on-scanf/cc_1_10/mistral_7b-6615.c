//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
#define MAX_EDGES 10000
#define TRUE 1
#define FALSE 0
#define MIN_COLOR 0
typedef struct Edge {
    int from, to;
} Edge;
typedef struct Graph {
    int V;
    int E;
    Edge* edge;
    int* color;
} Graph;
Graph* createGraph(int V) {
    Graph* graph = (Graph*) malloc(sizeof(Graph));
    graph->V = V;
    graph->E = 0;
    graph->edge = NULL;
    graph->color = calloc(V, sizeof(int));
    return graph;
}
void addEdge(Graph* graph, int from, int to) {
    graph->edge = realloc(graph->edge, sizeof(Edge) * (graph->E + 1));
    graph->edge[graph->E].from = from;
    graph->edge[graph->E].to = to;
    graph->E++;
}
int canColorGraph(Graph* graph, int vertex, int color) {
    for (int i = 0; i < graph->E; i++) {
        if (graph->edge[i].from == vertex || graph->edge[i].to == vertex) {
            for (int j = 0; j < vertex; j++) {
                if (graph->color[graph->edge[i].from] == color || graph->color[graph->edge[i].to] == color) {
                    return FALSE;
                }
            }
        }
    }
    return TRUE;
}
int graphColoring(Graph* graph, int m) {
    int color[MAX_VERTICES];
    int i, v, c;
    for (i = 0; i < graph->V; i++) {
        v = i;
        c = MIN_COLOR;
        while (TRUE) {
            if (canColorGraph(graph, v, c)) {
                graph->color[v] = c;
                if (i == graph->V - 1) {
                    free(graph->edge);
                    free(graph->color);
                    free(graph);
                    return TRUE;
                }
                i = -1;
                break;
            }
            c++;
            if (c > m) {
                return FALSE;
            }
        }
    }
    free(graph->edge);
    free(graph->color);
    free(graph);
    return TRUE;
}
int main() {
    int V, E, m;
    Graph* graph;
    scanf("%d %d %d", &V, &E, &m);
    graph = createGraph(V);
    for (int i = 0; i < E; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        addEdge(graph, from, to);
    }
    if (graphColoring(graph, m)) {
        printf("Graph Colored Successfully.\n");
    } else {
        printf("Graph cannot be colored with %d colors.\n", m);
    }
    return 0;
}