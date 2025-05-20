//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: careful
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000

typedef struct node {
    int color;
    struct node *next;
} node;

node *graph[MAX_VERTICES];

void add_node(int v) {
    graph[v] = malloc(sizeof(node));
    graph[v]->color = 0;
    graph[v]->next = NULL;
}

void add_edge(int v, int w) {
    graph[v]->next = graph[w];
}

void dfs_color(int v, int color) {
    graph[v]->color = color;
    for (node *adj = graph[v]->next; adj!= NULL; adj = adj->next) {
        if (adj->color == color) {
            printf("Error: Adjacent nodes have same color\n");
            exit(1);
        }
        dfs_color(adj->color, color);
    }
}

void print_graph() {
    for (int i = 0; i < MAX_VERTICES; i++) {
        printf("%d -> ", i);
        node *adj = graph[i];
        while (adj!= NULL) {
            printf("%d ", adj->color);
            adj = adj->next;
        }
        printf("\n");
    }
}

int main() {
    int n, m, v, w;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        printf("Enter vertices: ");
        scanf("%d %d", &v, &w);
        add_edge(v, w);
        add_edge(w, v);
    }

    int colors[n + 1];
    colors[0] = 0;

    for (int i = 1; i <= n; i++) {
        colors[i] = -1;
    }

    for (int i = 1; i <= n; i++) {
        if (colors[i] == -1) {
            dfs_color(i, i);
        }
    }

    print_graph();
    return 0;
}