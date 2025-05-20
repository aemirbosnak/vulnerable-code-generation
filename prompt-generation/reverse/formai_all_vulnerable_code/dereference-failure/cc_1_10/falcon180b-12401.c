//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int *data;
    int front;
    int rear;
    int size;
} Queue;

Queue *create_queue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->data = (int *)malloc(MAX_QUEUE_SIZE * sizeof(int));
    q->front = q->rear = -1;
    q->size = 0;
    return q;
}

void enqueue(Queue *q, int value) {
    if (is_full(q)) {
        printf("Queue is full!\n");
        return;
    }
    if (is_empty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    q->size--;
    return value;
}

int peek(Queue *q) {
    if (is_empty(q)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->data[q->front];
}

int is_empty(Queue *q) {
    return q->front == -1 && q->rear == -1;
}

int is_full(Queue *q) {
    return q->size == MAX_QUEUE_SIZE;
}

void destroy_queue(Queue *q) {
    free(q->data);
    free(q);
}

int main() {
    Queue *q = create_queue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    printf("Front element: %d\n", peek(q));
    dequeue(q);
    printf("Front element after dequeue: %d\n", peek(q));
    destroy_queue(q);
    return 0;
}