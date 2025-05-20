//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100

typedef struct {
    int *queue;
    int front;
    int rear;
    int count;
} Queue;

Queue *createQueue() {
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->queue = (int *) malloc(MAX_QUEUE_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->count = 0;
    return q;
}

void enqueue(Queue *q, int data) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = data;
    q->count++;
}

int dequeue(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    }
    q->count--;
    return data;
}

void display(Queue *q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i!= q->rear; i = (i + 1) % MAX_QUEUE_SIZE) {
        printf("%d ", q->queue[i]);
    }
    printf("%d\n", q->queue[q->rear]);
}

int main() {
    Queue *q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    display(q);
    int data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    data = dequeue(q);
    printf("Dequeued element: %d\n", data);
    display(q);
    return 0;
}