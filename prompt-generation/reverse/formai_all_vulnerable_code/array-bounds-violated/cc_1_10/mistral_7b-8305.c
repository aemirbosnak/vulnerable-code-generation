//MISTRAL-7B DATASET v1.0 Category: Queue Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100

typedef struct Queue {
    int front;
    int rear;
    int arr[MAX_QUEUE_SIZE];
} Queue;

void enqueue(Queue *q, int data) {
    if ((q->rear + 1) % MAX_QUEUE_SIZE == q->front) {
        printf("Queue is full!\n");
        return;
    }

    q->arr[q->rear] = data;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty!\n");
        return -1;
    }

    int data = q->arr[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return data;
}

void print_queue(Queue q) {
    int i = q.front;

    printf("Queue: ");
    do {
        printf("%d ", q.arr[i]);
        i = (i + 1) % MAX_QUEUE_SIZE;
    } while (i != q.rear);

    printf("\b\n");
}

int main() {
    Queue q;
    q.front = q.rear = -1;

    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);

    print_queue(q);

    int data = dequeue(&q);
    printf("Dequeued: %d\n", data);

    print_queue(q);

    enqueue(&q, 20);
    print_queue(q);

    return 0;
}