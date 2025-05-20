//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_NODES 100
#define MAX_COLORS 6

typedef struct {
    int node;
    int color;
} Node;

Node graph[MAX_NODES];
int num_nodes;
int num_colors;
int *color_map;

void *graph_coloring(void *arg) {
    int node = *(int *) arg;
    int color = 0;

    while (color_map[node] == -1) {
        color++;
        if (color == num_colors) {
            color = 0;
        }
    }

    color_map[node] = color;
    printf("Node %d colored with %d\n", node, color);
}

int main() {
    int i, j, k;
    int num_edges;
    int **edges;

    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the number of edges: ");
    scanf("%d", &num_edges);

    for (i = 0; i < num_nodes; i++) {
        graph[i].node = i;
        graph[i].color = -1;
    }

    edges = (int **) malloc(num_nodes * sizeof(int *));
    for (i = 0; i < num_nodes; i++) {
        edges[i] = (int *) malloc(num_nodes * sizeof(int));
        for (j = 0; j < num_nodes; j++) {
            edges[i][j] = 0;
        }
    }

    printf("Enter the edges (u v): ");
    for (i = 0; i < num_edges; i++) {
        scanf("%d %d", &k, &j);
        edges[k][j] = 1;
        edges[j][k] = 1;
    }

    num_colors = num_nodes;
    color_map = (int *) malloc(num_nodes * sizeof(int));
    for (i = 0; i < num_nodes; i++) {
        color_map[i] = -1;
    }

    pthread_t threads[num_nodes];
    for (i = 0; i < num_nodes; i++) {
        pthread_create(&threads[i], NULL, graph_coloring, (void *) &i);
    }

    for (i = 0; i < num_nodes; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < num_nodes; i++) {
        printf("Node %d colored with %d\n", i, color_map[i]);
    }

    for (i = 0; i < num_nodes; i++) {
        free(edges[i]);
    }
    free(edges);
    free(color_map);

    return 0;
}