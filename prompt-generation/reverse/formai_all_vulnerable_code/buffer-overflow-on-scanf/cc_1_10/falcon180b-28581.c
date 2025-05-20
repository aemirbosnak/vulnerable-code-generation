//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define V 9
#define INF 9999
#define MAX_COLOR 7

int graph[V][V];
int color[V];
int n_colors;

void init_graph() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            graph[i][j] = 0;
        }
    }
}

void read_graph() {
    int i, j;
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
}

void print_graph() {
    int i, j;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

void color_graph() {
    int i, j;
    time_t seed = time(NULL);
    srand(seed);
    for (i = 0; i < V; i++) {
        color[i] = rand() % MAX_COLOR;
    }
    n_colors = 0;
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (graph[i][j] == 1 && color[i] == color[j]) {
                n_colors++;
            }
        }
    }
    printf("Number of colors used: %d\n", n_colors);
}

int main() {
    int i;
    init_graph();
    read_graph();
    color_graph();
    return 0;
}