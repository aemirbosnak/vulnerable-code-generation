//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Queue {
    int front;
    int rear;
    int *queue;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->queue = (int*) malloc(MAX_SIZE * sizeof(int));
    return q;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_SIZE - 1) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = value;
}

int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front++;
    }
    return value;
}

int isEmpty(Queue* q) {
    if (q->front == -1) {
        return 1;
    } else {
        return 0;
    }
}

int isFull(Queue* q) {
    if (q->rear == MAX_SIZE - 1) {
        return 1;
    } else {
        return 0;
    }
}

void display(Queue* q) {
    if (q->front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
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
    display(q);
    int value = dequeue(q);
    printf("Dequeued value is: %d\n", value);
    display(q);
    dequeue(q);
    dequeue(q);
    printf("Dequeued value is: %d\n", dequeue(q));
    printf("Dequeued value is: %d\n", dequeue(q));
    printf("Dequeued value is: %d\n", dequeue(q));
    return 0;
}