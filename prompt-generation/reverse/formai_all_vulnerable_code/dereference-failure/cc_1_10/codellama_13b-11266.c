//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    int size;
    int front;
    int rear;
    int *arr;
};

void enqueue(struct Queue *q, int value) {
    if (q->rear == q->size - 1) {
        printf("Queue is full");
        return;
    }
    q->arr[q->rear] = value;
    q->rear++;
}

int dequeue(struct Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty");
        return -1;
    }
    int value = q->arr[q->front];
    q->front++;
    return value;
}

void printQueue(struct Queue *q) {
    for (int i = q->front; i < q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    q.size = 5;
    q.front = 0;
    q.rear = 0;
    q.arr = (int *)malloc(q.size * sizeof(int));

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    printQueue(&q);

    int value = dequeue(&q);
    printf("Dequeued value: %d\n", value);
    printQueue(&q);

    value = dequeue(&q);
    printf("Dequeued value: %d\n", value);
    printQueue(&q);

    enqueue(&q, 4);
    enqueue(&q, 5);
    printQueue(&q);

    value = dequeue(&q);
    printf("Dequeued value: %d\n", value);
    printQueue(&q);

    value = dequeue(&q);
    printf("Dequeued value: %d\n", value);
    printQueue(&q);

    return 0;
}