//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_NODES 50

typedef struct {
    int id;
    int parent;
} Node;

Node nodes[MAX_NODES];
int num_nodes = 0;

void init_graph() {
    int i;
    for (i = 0; i < MAX_NODES; i++) {
        nodes[i].id = i;
        nodes[i].parent = -1;
    }
}

void add_node() {
    int id;
    printf("Enter node ID: ");
    scanf("%d", &id);
    if (num_nodes >= MAX_NODES) {
        printf("Error: Maximum number of nodes reached.\n");
        return;
    }
    nodes[num_nodes].id = id;
    nodes[num_nodes].parent = -1;
    num_nodes++;
}

void add_edge(int node1, int node2) {
    nodes[node1].parent = node2;
}

void print_graph() {
    int i;
    printf("Graph:\n");
    for (i = 0; i < num_nodes; i++) {
        printf("%d -> %d\n", i, nodes[i].parent);
    }
}

void *thread_func(void *arg) {
    int id = *(int *) arg;
    printf("Thread %d started.\n", id);
    sleep(1);
    printf("Thread %d finished.\n", id);
    return NULL;
}

int main() {
    int i;
    init_graph();
    add_node();
    add_node();
    add_edge(0, 1);
    print_graph();
    pthread_t threads[MAX_THREADS];
    int ids[MAX_THREADS];
    for (i = 0; i < MAX_THREADS; i++) {
        ids[i] = i;
        pthread_create(&threads[i], NULL, thread_func, &ids[i]);
    }
    for (i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    return 0;
}