//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_NODES 100
#define MAX_COLORS 3

typedef struct {
    int node;
    int color;
} Node;

Node graph[MAX_NODES];
int num_nodes;
int num_colors;

sem_t mutex;
sem_t nodes_avail;

void init_graph(int n, int c) {
    num_nodes = n;
    num_colors = c;
    sem_init(&mutex, 0, 1);
    sem_init(&nodes_avail, 0, n);
}

void *color_node(void *arg) {
    int node = *(int *) arg;
    int color = 0;

    sem_wait(&nodes_avail);
    sem_wait(&mutex);

    for (int i = 0; i < num_colors; i++) {
        if (graph[node].color!= i) {
            graph[node].color = i;
            color = i;
            break;
        }
    }

    sem_post(&mutex);
    sem_post(&nodes_avail);

    printf("Node %d colored with color %d\n", node, color);
    return NULL;
}

int main() {
    int n, c;
    scanf("%d %d", &n, &c);

    init_graph(n, c);

    for (int i = 0; i < n; i++) {
        graph[i].node = i;
        graph[i].color = -1;
    }

    int num_threads = n;
    pthread_t threads[n];

    for (int i = 0; i < n; i++) {
        pthread_create(&threads[i], NULL, color_node, &i);
    }

    for (int i = 0; i < n; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}