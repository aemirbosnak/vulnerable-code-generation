//Falcon-180B DATASET v1.0 Category: Queue Implementation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

typedef struct {
    int *arr;
    int front;
    int rear;
    int count;
} Queue;

void initQueue(Queue *q) {
    q->arr = (int *)malloc(MAX_SIZE * sizeof(int));
    q->front = -1;
    q->rear = -1;
    q->count = 0;
}

void enqueue(Queue *q, int value) {
    if (q->count == MAX_SIZE) {
        printf("Queue is full.\n");
        return;
    }

    if (q->rear == MAX_SIZE - 1) {
        q->rear = 0;
    } else {
        q->rear++;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->arr[q->rear] = value;
    q->count++;
}

void dequeue(Queue *q) {
    if (q->count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    if (q->front == MAX_SIZE - 1) {
        q->front = 0;
    } else {
        q->front++;
    }

    q->count--;
}

void display(Queue *q) {
    if (q->count == 0) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    Queue q;

    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    return 0;
}