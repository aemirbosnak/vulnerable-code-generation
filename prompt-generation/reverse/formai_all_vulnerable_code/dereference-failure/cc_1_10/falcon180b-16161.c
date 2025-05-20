//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_NODES 100
#define MAX_EDGES 200

typedef struct node_t {
    int id;
    char *name;
} node_t;

typedef struct edge_t {
    int src;
    int dest;
} edge_t;

node_t nodes[MAX_NODES];
edge_t edges[MAX_EDGES];

int num_nodes = 0;
int num_edges = 0;

sem_t mutex;
sem_t cv;

void init() {
    sem_init(&mutex, 0, 1);
    sem_init(&cv, 0, 0);
}

void add_node() {
    char name[100];
    printf("Enter node name: ");
    scanf("%s", name);

    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->id = num_nodes;
    strcpy(new_node->name, name);

    sem_wait(&mutex);
    nodes[num_nodes] = *new_node;
    num_nodes++;
    sem_post(&mutex);
}

void add_edge() {
    int src, dest;

    printf("Enter source node ID: ");
    scanf("%d", &src);
    printf("Enter destination node ID: ");
    scanf("%d", &dest);

    edge_t *new_edge = (edge_t *) malloc(sizeof(edge_t));
    new_edge->src = src;
    new_edge->dest = dest;

    sem_wait(&mutex);
    edges[num_edges] = *new_edge;
    num_edges++;
    sem_post(&mutex);
}

void print_nodes() {
    sem_wait(&mutex);
    for (int i = 0; i < num_nodes; i++) {
        printf("ID: %d, Name: %s\n", nodes[i].id, nodes[i].name);
    }
    sem_post(&mutex);
}

void print_edges() {
    sem_wait(&mutex);
    for (int i = 0; i < num_edges; i++) {
        printf("Edge: (%d, %d)\n", edges[i].src, edges[i].dest);
    }
    sem_post(&mutex);
}

void *print_nodes_async(void *arg) {
    while (1) {
        sem_wait(&cv);
        print_nodes();
        sem_post(&mutex);
        usleep(500000); // sleep for half a second
    }
}

void *print_edges_async(void *arg) {
    while (1) {
        sem_wait(&cv);
        print_edges();
        sem_post(&mutex);
        usleep(500000); // sleep for half a second
    }
}

int main() {
    init();

    pthread_t nodes_thread, edges_thread;

    pthread_create(&nodes_thread, NULL, print_nodes_async, NULL);
    pthread_create(&edges_thread, NULL, print_edges_async, NULL);

    while (1) {
        int choice;
        printf("1. Add node\n2. Add edge\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_node();
                break;
            case 2:
                add_edge();
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}