//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: multivariable
/* Queue Implementation in C */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* Queue Struct */
struct Queue {
    int front, rear, size;
    int *arr;
};

/* Initialize the Queue */
void initQueue(struct Queue *q, int size) {
    q->front = q->rear = -1;
    q->size = size;
    q->arr = (int *)malloc(size * sizeof(int));
}

/* Check if the Queue is empty */
bool isEmpty(struct Queue *q) {
    return (q->front == -1 && q->rear == -1);
}

/* Check if the Queue is full */
bool isFull(struct Queue *q) {
    return ((q->rear + 1) % q->size == q->front);
}

/* Enqueue an element */
void enqueue(struct Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full.\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->arr[q->rear] = data;
    if (q->front == -1) q->front = 0;
}

/* Dequeue an element */
void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    q->front = (q->front + 1) % q->size;
}

/* Display the Queue */
void displayQueue(struct Queue *q) {
    int i;
    printf("Queue: ");
    for (i = q->front; i < q->rear; i++) {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initQueue(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    dequeue(&q);
    enqueue(&q, 4);
    dequeue(&q);
    dequeue(&q);
    displayQueue(&q);
    return 0;
}