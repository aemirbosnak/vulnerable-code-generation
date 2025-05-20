//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NODES 1000
#define MAX_COLORS 10

int graph[MAX_NODES][MAX_NODES];
int nnodes, nedges;
int color[MAX_NODES];
int max_color;

void init_graph() {
    int i, j;
    for (i = 0; i < nnodes; i++) {
        for (j = 0; j < nnodes; j++) {
            graph[i][j] = 0;
        }
    }
}

void add_edge(int u, int v) {
    graph[u][v] = 1;
    graph[v][u] = 1;
}

void read_graph() {
    FILE *fp;
    int u, v;
    fp = fopen("graph.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file\n");
        exit(1);
    }
    fscanf(fp, "%d %d", &nnodes, &nedges);
    init_graph();
    while (fscanf(fp, "%d %d", &u, &v)!= EOF) {
        add_edge(u, v);
    }
    fclose(fp);
}

void color_graph() {
    int i, j, k;
    for (i = 0; i < nnodes; i++) {
        color[i] = 0;
    }
    for (k = 0; k < nnodes; k++) {
        for (i = 0; i < nnodes; i++) {
            if (graph[k][i] == 1 && color[i] == 0) {
                for (j = 0; j < max_color; j++) {
                    if (graph[k][j] == 0) {
                        color[i] = j + 1;
                        break;
                    }
                }
            }
        }
    }
}

void print_graph() {
    int i, j;
    for (i = 0; i < nnodes; i++) {
        for (j = 0; j < nnodes; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void print_color() {
    int i;
    for (i = 0; i < nnodes; i++) {
        printf("%d ", color[i]);
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    read_graph();
    color_graph();
    print_graph();
    print_color();
    return 0;
}