//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>

#define MAX_NODES 100
#define MAX_COLORS 6

typedef struct {
    int node;
    int color;
} GraphNode;

typedef struct {
    int n;
    GraphNode *nodes;
} Graph;

void initGraph(Graph *g, int n) {
    g->n = n;
    g->nodes = (GraphNode*) malloc(n * sizeof(GraphNode));
    for (int i = 0; i < n; i++) {
        g->nodes[i].node = i;
        g->nodes[i].color = -1;
    }
}

void freeGraph(Graph *g) {
    free(g->nodes);
}

void printGraph(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("Node %d: Color %d\n", g->nodes[i].node, g->nodes[i].color);
    }
}

int isValidColor(GraphNode *node, int color) {
    for (int i = 0; i < node->node; i++) {
        if (node->color == color) {
            return 0;
        }
    }
    return 1;
}

void colorGraph(Graph *g) {
    int colors[MAX_COLORS] = {1, 2, 3, 4, 5, 6};
    int n = g->n;
    for (int i = 0; i < n; i++) {
        int color = -1;
        for (int j = 0; j < MAX_COLORS; j++) {
            if (isValidColor(g->nodes + i, colors[j])) {
                color = colors[j];
                break;
            }
        }
        g->nodes[i].color = color;
    }
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    srand(time(NULL));
    Graph g;
    initGraph(&g, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (rand() % 2 == 0) {
                GraphNode gn = {i, j};
                g.nodes[i].color = -1;
                g.nodes[j].color = -1;
            }
        }
    }

    colorGraph(&g);
    printf("Colored Graph:\n");
    printGraph(&g);

    freeGraph(&g);
    return 0;
}