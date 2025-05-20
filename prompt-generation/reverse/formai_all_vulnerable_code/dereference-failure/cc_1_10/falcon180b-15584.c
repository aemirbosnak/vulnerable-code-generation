//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

#define MAX_NODES 100
#define MAX_COLORS 7
#define INF INT_MAX

struct node {
    int id;
    int degree;
    int color;
    bool visited;
    struct node *edges[MAX_NODES];
};

void add_edge(struct node *n1, struct node *n2) {
    n1->edges[n1->degree++] = n2;
    n2->edges[n2->degree++] = n1;
}

void dfs(struct node *cur, int color) {
    cur->visited = true;
    cur->color = color;

    for (int i = 0; i < cur->degree; i++) {
        struct node *next = cur->edges[i];
        if (!next->visited) {
            dfs(next, color + 1);
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct node *nodes = (struct node *)malloc(n * sizeof(struct node));

    for (int i = 0; i < n; i++) {
        nodes[i].id = i;
        nodes[i].degree = 0;
        nodes[i].color = -1;
        nodes[i].visited = false;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        add_edge(&nodes[u], &nodes[v]);
    }

    for (int i = 0; i < n; i++) {
        if (!nodes[i].visited) {
            int color = 0;
            dfs(&nodes[i], color);
        }
    }

    int max_color = 0;
    for (int i = 0; i < n; i++) {
        if (nodes[i].color > max_color) {
            max_color = nodes[i].color;
        }
    }

    printf("Graph colored with %d colors.\n", max_color);

    return 0;
}