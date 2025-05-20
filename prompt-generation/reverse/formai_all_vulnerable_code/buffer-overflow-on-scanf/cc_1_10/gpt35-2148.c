//FormAI DATASET v1.0 Category: Graph Coloring Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_VERTICES 100
#define MAX_COLORS 10

typedef struct {
    int v;
    int e;
    int **adj;
    int *colors;
} graph_t;

typedef struct {
    graph_t *g;
    int start;
    int end;
} thread_data_t;

void *color_vertices(void *arg) {
    thread_data_t *data = (thread_data_t*)arg;
    graph_t *g = data->g;
    int i, j;

    for (i = data->start; i < data->end; i++) {
        int used_colors[MAX_COLORS] = {0};

        for (j = 0; j < g->v; j++) {
            if (g->adj[i][j] && g->colors[j] != -1) {
                used_colors[g->colors[j]] = 1;
            }
        }

        for (j = 0; j < MAX_COLORS; j++) {
            if (!used_colors[j]) {
                g->colors[i] = j;
                break;
            }
        }
    }

    pthread_exit(NULL);
}

void parallel_coloring(graph_t *g, int num_threads) {
    int i, j;
    pthread_t threads[num_threads];
    thread_data_t data[num_threads];

    for (i = 0; i < g->v; i++) {
        g->colors[i] = -1;
    }

    int chunk_size = g->v / num_threads;
    int remainder = g->v % num_threads;
    int start = 0;

    for (i = 0; i < num_threads; i++) {
        data[i].g = g;
        data[i].start = start;
        data[i].end = start + chunk_size + (i < remainder ? 1 : 0);
        start = data[i].end;

        pthread_create(&threads[i], NULL, color_vertices, &data[i]);
    }

    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
}

int main() {
    int v, e, i, j;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &v, &e);

    graph_t *g = (graph_t*)malloc(sizeof(graph_t));
    g->v = v;
    g->e = e;
    g->colors = (int*)malloc(v * sizeof(int));
    g->adj = (int**)malloc(v * sizeof(int*));

    for (i = 0; i < v; i++) {
        g->adj[i] = (int*)malloc(v * sizeof(int));
        g->colors[i] = -1;

        for (j = 0; j < v; j++) {
            g->adj[i][j] = 0;
        }
    }

    printf("Enter the edges (vertice pairs):\n");
    for (i = 0; i < e; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        g->adj[x][y] = 1;
        g->adj[y][x] = 1;
    }

    printf("Coloring vertices in parallel using %d threads...\n", 4);
    parallel_coloring(g, 4);

    printf("Final colors:\n");
    for (i = 0; i < v; i++) {
        printf("%d ", g->colors[i]);
    }
    printf("\n");

    return 0;
}