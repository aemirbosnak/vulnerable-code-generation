//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 1000

typedef struct {
    int front;
    int rear;
    int *queue;
} Queue;

Queue* createQueue() {
    Queue *q = (Queue*) malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->queue = (int*) malloc(MAX_QUEUE_SIZE * sizeof(int));
    return q;
}

void enqueue(Queue* q, int data) {
    if (q->rear == MAX_QUEUE_SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }
    q->rear++;
    q->queue[q->rear] = data;
}

int dequeue(Queue* q) {
    if (q->front == q->rear + 1) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = q->queue[q->front];
    q->front++;
    return data;
}

void displayQueue(Queue* q) {
    if (q->front == q->rear + 1) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    displayQueue(q);
    int data = dequeue(q);
    printf("Dequeued data: %d\n", data);
    displayQueue(q);
    return 0;
}