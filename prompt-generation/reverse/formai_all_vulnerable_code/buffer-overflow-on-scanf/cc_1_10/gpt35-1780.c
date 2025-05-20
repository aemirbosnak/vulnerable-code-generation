//FormAI DATASET v1.0 Category: Graph representation ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>

#define MAXV 1000 //Maximum number of vertices
#define MAXE 10000 //Maximum number of edges

typedef struct edge {
    int u;
    int v;
    int weight;
}Edge;

typedef struct graph {
    int nvertices;
    int nedges;
    Edge edges[MAXE];
}Graph;

void print_graph(Graph *g) {
    int i;
    printf("Number of vertices: %d\n", g->nvertices);
    printf("Number of edges: %d\n", g->nedges);
    for(i=1;i<=g->nedges;++i) {
        printf("(%d, %d) with weight %d\n", g->edges[i].u, g->edges[i].v, g->edges[i].weight);
    }
}

void add_edge(Graph *g, int u, int v, int weight) {
    if(g->nedges == MAXE) {
        printf("Maximum number of edges exceeded\n");
        exit(1);
    }
    g->nedges++;
    g->edges[g->nedges].u = u;
    g->edges[g->nedges].v = v;
    g->edges[g->nedges].weight = weight;
}

void initialize_graph(Graph *g, int nvertices) {
    int i;
    g->nvertices = nvertices;
    g->nedges = 0;
    for(i=1;i<=nvertices;++i) {
        g->edges[i].u = 0;
        g->edges[i].v = 0;
        g->edges[i].weight = 0;
    }
}

int main() {

    Graph g;
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    initialize_graph(&g, n);
    printf("Enter n vertices (1 to %d):\n", n);

    int u, v, w;
    printf("Enter number of edges: ");
    int ne;
    scanf("%d", &ne);

    printf("Enter (u, v, w) for each edge\n");
    int i;
    for(i=0; i<ne; ++i) {
        printf("Edge %d: ", i+1);
        scanf("%d %d %d", &u, &v, &w);
        add_edge(&g, u, v, w);
    }
    print_graph(&g);
    return 0;
}