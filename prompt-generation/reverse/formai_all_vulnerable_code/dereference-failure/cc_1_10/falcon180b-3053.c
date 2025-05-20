//Falcon-180B DATASET v1.0 Category: Graph Coloring Problem ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_THREADS 4
#define NUM_NODES 10
#define NUM_COLORS 5

typedef struct {
    int id;
    int color;
} node_t;

node_t nodes[NUM_NODES];
int adj_matrix[NUM_NODES][NUM_NODES];
sem_t mutex;
int finished;

void init_graph() {
    for (int i = 0; i < NUM_NODES; i++) {
        nodes[i].id = i;
        nodes[i].color = -1;
    }

    for (int i = 0; i < NUM_NODES; i++) {
        for (int j = 0; j < NUM_NODES; j++) {
            adj_matrix[i][j] = rand() % 2; // 0 or 1
        }
    }
}

void print_graph() {
    for (int i = 0; i < NUM_NODES; i++) {
        for (int j = 0; j < NUM_NODES; j++) {
            printf("%d ", adj_matrix[i][j]);
        }
        printf("\n");
    }
}

void print_solution(int *colors) {
    for (int i = 0; i < NUM_NODES; i++) {
        printf("%d -> %d\n", i, colors[i]);
    }
}

void *thread_func(void *arg) {
    int *colors = (int *) arg;
    int thread_id = *colors;
    colors[thread_id] = thread_id;

    sem_wait(&mutex);

    for (int i = 0; i < NUM_NODES; i++) {
        if (i!= thread_id && adj_matrix[thread_id][i] == 1) {
            for (int j = 0; j < NUM_THREADS; j++) {
                if (colors[j] == i) {
                    colors[thread_id] = j;
                    break;
                }
            }
        }
    }

    sem_post(&mutex);

    return NULL;
}

int main() {
    srand(time(NULL));
    init_graph();

    int *colors = (int *) malloc(NUM_THREADS * sizeof(int));
    for (int i = 0; i < NUM_THREADS; i++) {
        colors[i] = -1;
    }

    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *) &colors[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    print_solution(colors);

    free(colors);
    return 0;
}