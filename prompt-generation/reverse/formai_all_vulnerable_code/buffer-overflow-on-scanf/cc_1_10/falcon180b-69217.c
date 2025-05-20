//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_VERTICES 1000
#define MAX_COLORS 100

int graph[MAX_VERTICES][MAX_VERTICES];
int colors[MAX_VERTICES];
int num_colors;

void *color_thread(void *arg) {
    int vertex = *(int *) arg;
    int color = 1;

    while (color <= num_colors) {
        int i;
        for (i = 0; i < vertex; i++) {
            if (graph[vertex][i] && colors[i] == color) {
                break;
            }
        }
        if (i == vertex) {
            colors[vertex] = color;
            return NULL;
        }
        color++;
    }

    return NULL;
}

int main() {
    int i, j, k;
    int n, m;
    int *thread_ids;
    pthread_t threads[MAX_VERTICES];

    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {
        scanf("%d %d", &k, &j);
        graph[k][j] = 1;
        graph[j][k] = 1;
    }

    num_colors = 0;
    for (i = 0; i < n; i++) {
        colors[i] = 0;
    }

    for (i = 0; i < n; i++) {
        if (colors[i] == 0) {
            thread_ids = (int *) malloc(sizeof(int));
            *thread_ids = i;
            pthread_create(&threads[i], NULL, color_thread, thread_ids);
        }
    }

    for (i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Colors:\n");
    for (i = 0; i < n; i++) {
        printf("%d: %d\n", i, colors[i]);
    }

    return 0;
}