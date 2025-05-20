//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueNode {
    void* data;
    struct QueueNode* next;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
    int size;
} Queue;

Queue* createQueue() {
    Queue* q = malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

void enqueue(Queue* q, void* data) {
    QueueNode* node = malloc(sizeof(QueueNode));
    node->data = data;
    node->next = NULL;

    if (q->rear == NULL) {
        q->front = node;
        q->rear = node;
    } else {
        q->rear->next = node;
        q->rear = node;
    }

    q->size++;
}

void* dequeue(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }

    void* data = q->front->data;
    QueueNode* node = q->front;
    q->front = q->front->next;
    free(node);

    q->size--;
    return data;
}

void* peek(Queue* q) {
    if (q->front == NULL) {
        return NULL;
    }

    return q->front->data;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int main() {
    Queue* q = createQueue();

    enqueue(q, "Hello");
    enqueue(q, "World");
    enqueue(q, "!");

    printf("%s ", (char*)dequeue(q));
    printf("%s ", (char*)dequeue(q));
    printf("%s\n", (char*)dequeue(q));

    freeQueue(q);

    return 0;
}