//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5
#define NUM_NODES 10

struct node {
    int id;
    struct node *next;
};

struct node *graph = NULL;

void *thread_func(void *param) {
    int thread_id = *(int *)param;
    int start_node = thread_id * NUM_NODES / NUM_THREADS;
    int end_node = (thread_id + 1) * NUM_NODES / NUM_THREADS - 1;

    printf("Thread %d is creating nodes %d to %d\n", thread_id, start_node, end_node);

    for (int i = start_node; i <= end_node; i++) {
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->id = i;
        new_node->next = NULL;

        if (graph == NULL) {
            graph = new_node;
        } else {
            struct node *temp = graph;
            while (temp->next!= NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, thread_func, (void *)&i);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}