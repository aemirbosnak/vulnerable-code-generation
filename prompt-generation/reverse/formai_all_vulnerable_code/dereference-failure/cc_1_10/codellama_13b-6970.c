//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: Donald Knuth
// Donald Knuth's Queue Implementation
#include <stdio.h>
#include <stdlib.h>

// Queue structure
typedef struct Queue {
    int size;
    int front;
    int rear;
    int *array;
} Queue;

// Initialize the queue
void initQueue(Queue *q, int size) {
    q->size = size;
    q->front = 0;
    q->rear = -1;
    q->array = malloc(sizeof(int) * size);
}

// Enqueue an element
void enqueue(Queue *q, int element) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = element;
}

// Dequeue an element
int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    int element = q->array[q->front];
    q->front++;
    return element;
}

// Check if the queue is empty
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// Check if the queue is full
int isFull(Queue *q) {
    return q->rear == q->size - 1;
}

// Display the elements of the queue
void display(Queue *q) {
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->array[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q, 5);
    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    display(&q);
    printf("Dequeued element: %d\n", dequeue(&q));
    display(&q);
    return 0;
}