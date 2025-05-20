//Code Llama-13B DATASET v1.0 Category: Queue Implementation ; Style: innovative
// Unique C Queue Implementation Example Program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Queue structure
typedef struct {
    int front;
    int rear;
    int *arr;
    int size;
} Queue;

// Function to create a new queue
Queue* create_queue(int size) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = 0;
    q->rear = -1;
    q->arr = (int*)malloc(sizeof(int) * size);
    q->size = size;
    return q;
}

// Function to enqueue an element
void enqueue(Queue *q, int element) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->arr[q->rear] = element;
}

// Function to dequeue an element
int dequeue(Queue *q) {
    if (q->front == q->rear) {
        printf("Queue is empty\n");
        return -1;
    }
    q->front++;
    return q->arr[q->front];
}

// Function to check if the queue is empty
bool is_empty(Queue *q) {
    return q->front == q->rear;
}

// Function to check if the queue is full
bool is_full(Queue *q) {
    return q->rear == q->size - 1;
}

int main() {
    Queue *q = create_queue(10);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("%d dequeued\n", dequeue(q));
    printf("%d dequeued\n", dequeue(q));
    printf("%d dequeued\n", dequeue(q));
    printf("Queue is empty: %s\n", is_empty(q) ? "true" : "false");
    printf("Queue is full: %s\n", is_full(q) ? "true" : "false");
    return 0;
}