//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_V 1000
#define MAX_E 10000
#define MAX_COLOR 1000

int V;
int E;
int **graph;
int *color;

void init() {
    V = 0;
    E = 0;
    graph = NULL;
    color = NULL;
}

void read_graph() {
    FILE *f;
    int u, v, w;
    f = fopen("graph.txt", "r");
    if (f == NULL) {
        printf("Error: cannot open graph file\n");
        exit(1);
    }
    while (fscanf(f, "%d %d %d", &u, &v, &w)!= EOF) {
        graph[u] = (int *)malloc(sizeof(int) * w);
        for (int i = 0; i < w; i++) {
            graph[u][i] = v;
        }
        E++;
    }
    fclose(f);
}

void read_color() {
    FILE *f;
    int c;
    f = fopen("color.txt", "r");
    if (f == NULL) {
        printf("Error: cannot open color file\n");
        exit(1);
    }
    while (fscanf(f, "%d", &c)!= EOF) {
        color[c] = -1;
    }
    fclose(f);
}

void color_graph() {
    int i, j, k, c;
    for (i = 0; i < V; i++) {
        color[i] = -1;
    }
    for (i = 0; i < V; i++) {
        for (j = 0; j < E; j++) {
            k = graph[i][j];
            if (color[k] == -1) {
                color[k] = 1;
            } else {
                c = 1;
                while (color[c] == 1) {
                    c++;
                }
                color[k] = c;
            }
        }
    }
}

void write_color() {
    FILE *f;
    f = fopen("color.txt", "w");
    if (f == NULL) {
        printf("Error: cannot open color file\n");
        exit(1);
    }
    for (int i = 0; i < V; i++) {
        fprintf(f, "%d ", color[i]);
    }
    fclose(f);
}

int main() {
    init();
    read_graph();
    read_color();
    color_graph();
    write_color();
    return 0;
}