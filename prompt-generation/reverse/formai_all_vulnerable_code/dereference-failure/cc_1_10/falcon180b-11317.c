//Falcon-180B DATASET v1.0 Category: Graph representation ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_THREADS 10
#define MAX_NODES 100

typedef struct node {
    int data;
    int id;
    struct node *next;
} Node;

Node *head = NULL;

void add_node(int data, int id) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->id = id;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
    } else {
        Node *temp = head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void print_graph() {
    Node *temp = head;
    while (temp!= NULL) {
        printf("Node %d: Data = %d\n", temp->id, temp->data);
        temp = temp->next;
    }
}

void *thread_func(void *param) {
    int *data = (int *)param;
    int id = *(int *)data;
    free(data);

    add_node(*(int *)data, id);

    pthread_exit(0);
}

int main() {
    pthread_t threads[MAX_THREADS];
    int data[MAX_THREADS];

    for (int i = 0; i < MAX_THREADS; i++) {
        data[i] = i + 1;
        pthread_create(&threads[i], NULL, thread_func, &data[i]);
    }

    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    print_graph();

    return 0;
}