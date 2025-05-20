//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct queue {
    int front;
    int rear;
    int *arr;
} Queue;

Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    q->arr = (int*)malloc(MAX_SIZE * sizeof(int));
    return q;
}

void enqueue(Queue* q, int value) {
    if ((q->rear + 1) % MAX_SIZE == q->front) {
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->arr[q->rear] = value;
}

int dequeue(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    return value;
}

void display(Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i = (i + 1) % MAX_SIZE) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue* q = createQueue();
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);
    dequeue(q);
    dequeue(q);
    display(q);
    return 0;
}