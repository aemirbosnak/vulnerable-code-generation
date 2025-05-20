//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAXV 100   // Maximum number of vertices in the graph

typedef struct edgenode {
    int y;
    struct edgenode *next;
} edgenode;

typedef struct {
    edgenode *edges[MAXV + 1];
    int degree[MAXV + 1];
    int nvertices;
    int nedges;
} graph;

void initialize_graph(graph *g) {
    int i;
    g -> nvertices = 0;
    g -> nedges = 0;
    for (i = 1; i <= MAXV; i++) {
        g -> degree[i] = 0;
        g -> edges[i] = NULL;
    }
}

void insert_edge(graph *g, int x, int y) {
    edgenode *p;
    p = malloc(sizeof(edgenode));
    p -> y = y;
    p -> next = g -> edges[x];
    g -> edges[x] = p;
    g -> degree[x]++;
}

void print_graph(graph *g) {
    int i;
    edgenode *p;
    for (i = 1; i <= g -> nvertices; i++) {
        printf("%d: ", i);
        p = g -> edges[i];
        while (p != NULL) {
            printf(" %d", p -> y);
            p = p -> next;
        }
        printf("\n");
    }
}

int get_maximum_degree(graph *g) {
    int i;
    int max_degree = 0;
    for (i = 1; i <= g -> nvertices; i++) {
        if (g -> degree[i] > max_degree) {
            max_degree = g -> degree[i];
        }
    }
    return max_degree;
}

int color_graph(graph *g, int colors[]) {
    int i, j;
    int color, max_color;
    int color_used[MAXV + 1];
    for (i = 1; i <= g -> nvertices; i++) {
        colors[i] = 0;
        color_used[i] = 0;
    }
    max_color = 0;
    for (i = 1; i <= g -> nvertices; i++) {
        for (j = 1; j <= g -> nvertices; j++) {
            if (colors[j] != 0) {
                color_used[colors[j]] = i;
            }
        }
        color = 1;
        while (color_used[color] == i) {
            color++;
        }
        if (color > max_color) {
            max_color = color;
        }
        colors[i] = color;
    }
    return max_color;
}

int main() {
    graph g;
    int colors[MAXV + 1];
    int i, n, x, y;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    initialize_graph(&g);
    g.nvertices = n;
    printf("Enter number of edges: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter edge: ");
        scanf("%d %d", &x, &y);
        insert_edge(&g, x, y);
        insert_edge(&g, y, x);
        g.nedges++;
    }

    printf("\nGraph:\n");
    print_graph(&g);

    printf("\nColoring the graph:\n");
    int max_color = color_graph(&g, colors);
    printf("Maximum number of colors required: %d\n", max_color);
    for (i = 1; i <= g.nvertices; i++) {
        printf("Vertex %d is assigned color %d\n", i, colors[i]);
    }
    
    return 0;
}