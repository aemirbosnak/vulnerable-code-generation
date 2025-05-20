//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    void *data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    size_t size;
} Queue;

Queue *create_queue(size_t capacity) {
    Queue *q = malloc(sizeof(Queue));
    if (q == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for queue.\n");
        exit(EXIT_FAILURE);
    }
    q->front = q->rear = NULL;
    q->size = capacity;
    return q;
}

bool is_empty(Queue *q) {
    return q->front == NULL;
}

bool is_full(Queue *q) {
    return q->rear!= NULL && (q->rear->next == NULL || q->rear->next->data == NULL);
}

void enqueue(Queue *q, void *data) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for node.\n");
        exit(EXIT_FAILURE);
    }
    node->data = data;
    node->next = NULL;
    if (is_empty(q)) {
        q->front = q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }
    q->size++;
}

void *dequeue(Queue *q) {
    if (is_empty(q)) {
        fprintf(stderr, "Error: Queue is empty.\n");
        exit(EXIT_FAILURE);
    }
    void *data = q->front->data;
    Node *node = q->front;
    q->front = q->front->next;
    free(node);
    q->size--;
    return data;
}

void destroy_queue(Queue *q) {
    while (!is_empty(q)) {
        void *data = dequeue(q);
        // Do something with the data
        free(data);
    }
    free(q);
}

int main() {
    Queue *q = create_queue(10);
    for (int i = 0; i < 20; i++) {
        enqueue(q, malloc(i));
    }
    while (!is_empty(q)) {
        void *data = dequeue(q);
        printf("Dequeued data: %p\n", data);
        free(data);
    }
    destroy_queue(q);
    return 0;
}