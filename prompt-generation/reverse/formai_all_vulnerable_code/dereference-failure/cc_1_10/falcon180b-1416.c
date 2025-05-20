//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int* data;
    int front;
    int rear;
    int size;
} Queue;

Queue* create_queue(int size) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->data = (int*)malloc(sizeof(int) * size);
    q->front = -1;
    q->rear = -1;
    q->size = size;
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == q->size - 1) {
        printf("Queue is full!\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->data[q->rear] = value;
}

int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int value = q->data[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

bool is_empty(Queue* q) {
    return q->front == -1;
}

bool is_full(Queue* q) {
    return q->rear == q->size - 1;
}

void destroy_queue(Queue* q) {
    free(q->data);
    free(q);
}

int main() {
    Queue* q = create_queue(MAX_QUEUE_SIZE);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("%d dequeued from the queue\n", dequeue(q));
    printf("%d dequeued from the queue\n", dequeue(q));
    printf("%d dequeued from the queue\n", dequeue(q));
    destroy_queue(q);
    return 0;
}